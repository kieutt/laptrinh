//https://code.cvp.vn/contest/11/problem/COPYARR
#include <bits/stdc++.h>
using namespace std;

int N, Q, a[100001], b[100001], IT[400004], lazyL[400004], lazyR[400004];

void push_down(int k)
{
    if (lazyL[k] && lazyR[k])
    {
        int m = (lazyL[k] + lazyR[k]) / 2;
        lazyL[2 * k] = lazyL[k];        lazyR[2 * k] = m;
        if (lazyL[k] == m) IT[2 * k] = a[lazyL[k]];
        lazyL[2 * k + 1] = m + 1;
        lazyR[2 * k + 1] = lazyR[k];
        if (m + 1 == lazyR[k]) IT[2 * k + 1] = a[lazyR[k]];
        lazyL[k] = lazyR[k] = 0;
    }
}

void build(int k, int l, int r)
{
    if (l == r) IT[k] = b[l];
    else
    {
        int m = (l + r) / 2;
        build(2 * k, l, m);
        build(2 * k + 1, m + 1, r);
    }
}

void update(int k, int l, int r, int x, int y, int lA, int rA)
{
    if (r < x || y < l) return ;
    if (x <= l && r <= y)
    {
        if (l == r) IT[k] = a[lA + l - x];
        lazyL[k] = lA + l - x;
        lazyR[k] = rA - (y - r);
    }
    else
    {
        push_down(k);
        int m = (l + r) / 2;
        update(2 * k, l, m, x, y, lA, rA);
        update(2 * k + 1, m + 1, r, x, y, lA, rA);
    }
}

int get(int k, int l, int r, int x)
{
    if (r < x || x < l) return INT_MIN;
    if (l == r) return IT[k];
    else
    {
        push_down(k);
        int m = (l + r) / 2;
        return max(get(2 * k, l, m, x), get(2 * k + 1, m + 1, r, x));
    }
}

main()
{

    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++) scanf("%d", &b[i]);

    build(1, 1, N);
    for (int cmd, x, y, k; Q--;)
    {
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            scanf("%d %d %d", &x, &y, &k);
            update(1, 1, N, y, y + k - 1, x, x + k - 1);
        }
        else
        {
            scanf("%d", &x);
            printf("%d\n", get(1, 1, N, x));
        }
    }
}
