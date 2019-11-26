#include <bits/stdc++.h>
using namespace std;

int N, Q, x, IT[400004], lazy[400004];
char c, S[100001];

void update(int k, int x, int y, int d, int c, int v)
{
    if (c < x || y < d) return;
    if (d <= x && y <= c) IT[k] += v, lazy[k] += v;
    else
    {
        int m = (x + y) / 2;
        update(2 * k, x, m, d, c, v);
        update(2 * k + 1, m + 1, y, d, c, v);
        IT[k] = min(IT[2 * k], IT[2 * k + 1]) + lazy[k];
    }
}

int get(int k, int x, int y, int d, int c)
{
    if (c < x || y < d) return 1e9;
    if (d <= x && y <= c) return IT[k];
    else
    {
        int m = (x + y) / 2;
        return min(get(2 * k, x, m, d, c) , get(2 * k + 1, m + 1, y, d, c)) + lazy[k];
    }
}

bool check(int l, int r)
{
    if ((r - l + 1) & 1) return 0;
    int y = (l == 1 ? 0 : get(1, 1, N, l - 1, l - 1));
    int z = get(1, 1, N, r, r);
    return (y == z && get(1, 1, N, l, r) >= z);
}

main()
{
    #ifndef KIEUQUOCDAT
        freopen("vao.inp", "r", stdin);
        freopen("ra1.out", "w", stdout);
    #endif

    scanf("%d %d %s", &N, &Q, S + 1);
    for (int i = 1; i <= N; i++)
        update(1, 1, N, i, i, x += (S[i] == '(') ? 1 : -1);
    for (int cmd, i, j; Q--; )
    {
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            scanf("%d %c\n", &i, &c);
            if (S[i] == c) continue;
                else S[i] = c;
            update(1, 1, N, i, N, (c == '(') ? 2 : -2);
        }
        else
        {
            scanf("%d %d\n", &i, &j);
            printf("%s\n", check(i, j) ? "YES" : "NO");
        }
    }
}
