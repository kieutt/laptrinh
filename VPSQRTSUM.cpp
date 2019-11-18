//https://code.cvp.vn/contest/9/problem/SQRTSUM
#include <bits/stdc++.h>
using namespace std;

int N, Q, jump[100001];
long long a[100001], BIT[100001];

void update(int x, long long v)
{
    for (; x <= N; x += x & -x)
        BIT[x] += v;
}

long long get(int x)
{
    long long ret = 0;
    for (; x; x -= x & -x)
        ret += BIT[x];
    return ret;
}

int next_pos(int x)
{
    if (x > N) return N + 1;
    if (jump[x] != x) jump[x] = next_pos(jump[x]);
    return jump[x];
}

main()
{
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &a[i]);
        update(i, a[i]);
        jump[i] = i;
    }
    for (int cmd, x, y; Q--; )
    {
        scanf("%d %d %d", &cmd, &x, &y);
        if (cmd == 1)
            for (int i = next_pos(x); i <= y; i = next_pos(i + 1))
            {
                if (a[i] == 1) continue;
                update(i, -a[i]);
                a[i] = floor(sqrt((double)a[i]));
                update(i, a[i]);
                if (a[i] == 1) jump[i] = i + 1;
            }
        else printf("%lld\n", get(y) - get(x - 1));
    }
}
