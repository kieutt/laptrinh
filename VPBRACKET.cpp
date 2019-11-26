#include <bits/stdc++.h>
using namespace std;

int N, Q, l, r, s[100001], IT[400004];
char c;

void build(int k, int l, int r)
{
    if (l == r) IT[k] = s[l];
    else
    {
        int m = (l + r) / 2;
        build(2 * k, l, m);
        build(2 * k + 1, m + 1, r);
        IT[k] = min(IT[2 * k], IT[2 * k + 1]);
    }
}

int getmin(int k, int l, int r, int x, int y)
{
    if (r < x || y < l) return INT_MAX;
    if (x <= l && r <= y) return IT[k];
    else
    {
        int m = (l + r) / 2;
        return min(getmin(2 * k, l, m, x, y), getmin(2 * k + 1, m + 1, r, x, y));
    }
}

main()
{
    #ifndef KIEUQUOCDAT
        freopen("vao.inp", "r", stdin);
        freopen("ra.out", "w", stdout);
    #endif

    scanf("%d %d\n", &N, &Q);
    for (int i = 1; i <= N; i++)
    {
        scanf("%c", &c);
        s[i] = s[i - 1] + ((c == '(') ? 1 : -1);
    }
    build(1, 1, N);
    while (Q--)
    {
        scanf("%d %d", &l, &r);
        printf("%s\n", (s[l - 1] == s[r] && getmin(1, 1, N, l, r) >= s[r]) ? "YES" : "NO");
    }
}
