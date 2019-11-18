//https://code.cvp.vn/contest/9/problem/AMIS
#include <bits/stdc++.h>
using namespace std;

int N, Q, a[100001], IT[400004], add[400004], mul[400004], init[400004];

void push_down(int k, int l, int r, int m)
{
    if (init[k])
    {
        init[2 * k] = init[2 * k + 1] = init[k];
        mul[2 * k] = mul[2 * k + 1] = 1;
        add[2 * k] = add[2 * k + 1] = 0;
        IT[2 * k] = 1LL * (m - l + 1) * init[k] % 1000000007;
        IT[2 * k + 1] = 1LL * (r - m) * init[k] % 1000000007;
        init[k] = 0;
    }
    if (mul[k] != 1 || add[k] != 0)
    {
        mul[2 * k] = 1LL * mul[2 * k] * mul[k] % 1000000007;
        add[2 * k] = (1LL * add[2 * k] * mul[k] + add[k]) % 1000000007;
        IT[2 * k] = (1LL * IT[2 * k] * mul[k] + 1LL * (m - l + 1) * add[k]) % 1000000007;
        mul[2 * k + 1] = 1LL * mul[2 * k + 1] * mul[k] % 1000000007;
        add[2 * k + 1] = (1LL * add[2 * k + 1] * mul[k] + add[k]) % 1000000007;
        IT[2 * k + 1] = (1LL * IT[2 * k + 1] * mul[k] + 1LL * (r - m) * add[k]) % 1000000007;
        mul[k] = 1;
        add[k] = 0;
    }
}

void adding(int k, int l, int r, int x, int y, int v)
{
    if (r < x || y < l) return ;
    if (x <= l && r <= y)
    {
        IT[k] = (IT[k] + 1LL * (r - l + 1) * v) % 1000000007;
        add[k] = (add[k] + v) % 1000000007;
    }
    else
    {
        int m = (l + r) / 2;
        push_down(k, l, r, m);
        adding(2 * k, l, m, x, y, v);
        adding(2 * k + 1, m + 1, r, x, y, v);
        IT[k] = (IT[2 * k] + IT[2 * k + 1]) % 1000000007;
    }
}

void multiplying(int k, int l, int r, int x, int y, int v)
{
    if (r < x || y < l) return ;
    if (x <= l && r <= y)
    {
        IT[k] = 1LL * IT[k] * v % 1000000007;
        mul[k] = 1LL * mul[k] * v % 1000000007;
        add[k] = 1LL * add[k] * v % 1000000007;
    }
    else
    {
        int m = (l + r) / 2;
        push_down(k, l, r, m);
        multiplying(2 * k, l, m, x, y, v);
        multiplying(2 * k + 1, m + 1, r, x, y, v);
        IT[k] = (IT[2 * k] + IT[2 * k + 1]) % 1000000007;
    }
}

void initializing(int k, int l, int r, int x, int y, int v)
{
    if (r < x || y < l) return ;
    if (x <= l && r <= y)
    {
        IT[k] = 1LL * (r - l + 1) * v % 1000000007;
        init[k] = v;
        mul[k] = 1;
        add[k] = 0;
    }
    else
    {
        int m = (l + r) / 2;
        push_down(k, l, r, m);
        initializing(2 * k, l, m, x, y, v);
        initializing(2 * k + 1, m + 1, r, x, y, v);
        IT[k] = (IT[2 * k] + IT[2 * k + 1]) % 1000000007;
    }
}

int getsum(int k, int l, int r, int x, int y)
{
    if (r < x || y < l) return 0;
    if (x <= l && r <= y) return IT[k];
    else
    {
        int m = (l + r) / 2;
        push_down(k, l, r, m);
        return (getsum(2 * k, l, m, x, y) + getsum(2 * k + 1, m + 1, r, x, y)) % 1000000007;
    }
}

main()
{
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
        initializing(1, 1, N, i, i, a[i]);
    }

    fill(mul + 1, mul + 4 * N + 1, 1);
    for (int cmd, x, y, v; Q--;)
    {
        scanf("%d %d %d", &cmd, &x, &y);
        if (cmd != 4)
        {
            scanf("%d", &v);
            if (cmd == 1) adding(1, 1, N, x, y, v);
                else if (cmd == 2) multiplying(1, 1, N, x, y, v);
                    else initializing(1, 1, N, x, y, v);
        }
        else printf("%d\n", getsum(1, 1, N, x, y));
    }
}
