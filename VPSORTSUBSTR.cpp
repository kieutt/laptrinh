#include <bits/stdc++.h>
using namespace std;

int N, Q, l, r, id, IT[400010][28], val[400010], cnt[30];
pair <int, int> rev[30];
char S[100010];

void lazy(int k, int l, int r)
{
    if (!val[k]) return ;
    memset(IT[k], 0, sizeof IT[k]);
    IT[k][val[k]] = r - l + 1;
    if (l != r)
        val[2 * k] = val[2 * k + 1] = val[k];
    val[k] = 0;
}

void update(int k, int l, int r, int x, int y, int v)
{
    lazy(k, l, r);
    if (x <= l && r <= y)
    {
        val[k] = v;
        lazy(k, l, r);
    }
    else if (r < x || y < l) return ;
    else
    {
        int mid = (l + r) / 2;
        update(2 * k, l, mid, x, y, v);
        update(2 * k + 1, mid + 1, r, x, y, v);
        for (int i = 1; i < 27; i++)
            IT[k][i] = IT[2 * k][i] + IT[2 * k + 1][i];
    }
}

void get(int k, int l, int r, int x, int y)
{
    lazy(k, l, r);
    if (x <= l && r <= y)
    {
        for (int i = 1; i < 27; i++)
            cnt[i] += IT[k][i];
    }
    else if (r < x || y < l) return ;
    else
    {
        int mid = (l + r) / 2;
        get(2 * k, l, mid, x, y);
        get(2 * k + 1, mid + 1, r, x, y);
    }
}

main()
{
    scanf("%d %d\n%s", &N, &Q, S + 1);

    for (int i = 1; i <= N; i++)
        update(1, 1, N, i, i, S[i] - 'a' + 1);
    while (Q--)
    {
        scanf("%d %d %d", &l, &r, &id);

        memset(cnt, 0, sizeof cnt);
        get(1, 1, N, l, r);

        int len = 0;
        for (int i = 1; i < 27; i++)
            if (cnt[i]) rev[++len] = make_pair(i, cnt[i]);
        if (!id) reverse(rev + 1, rev + len + 1);
        for (int i = 1; i <= len; i++)
        {
            r = l + rev[i].second - 1;
            update(1, 1, N, l, r, rev[i].first);
            l = r + 1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        memset(cnt, 0, sizeof cnt);
        get(1, 1, N, i, i);
        for (int j = 1; j < 27; j++)
            if (cnt[j]) printf("%c", j + 'a' - 1);
    }
}
