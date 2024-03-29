//https://code.cvp.vn/contest/9/problem/PALINSORT

#include <bits/stdc++.h>
using namespace std;

int N, Q, cnt[26], lazy[400004];
char S[100001];
struct node
{
    int x[26];
    void reset() {memset(x, 0, sizeof x);}
} IT[400004];

void push_down(int k, int l, int r)
{
    if (l != r && lazy[k] != -1)
    {
        int m = (l + r) / 2;
        lazy[2 * k] = lazy[2 * k + 1] = lazy[k];
        IT[2 * k].reset();          IT[2 * k].x[lazy[k]] = m - l + 1;
        IT[2 * k + 1].reset();      IT[2 * k + 1].x[lazy[k]] = r - m;
        lazy[k] = -1;
    }
}

void update(int k, int l, int r, int x, int y, int letter)
{
    if (y < l || r < x) return ;
    if (x <= l && r <= y)
    {
        IT[k].reset();      IT[k].x[letter] = r - l + 1;
        lazy[k] = letter;
    }
    else
    {
        push_down(k, l, r);
        int m = (l + r) / 2;
        update(2 * k, l, m, x, y, letter);
        update(2 * k + 1, m + 1, r, x, y, letter);
        for (int i = 0; i < 26; i++)
            IT[k].x[i] = IT[2 * k].x[i] + IT[2 * k + 1].x[i];
    }
}

void get(int k, int l, int r, int x, int y)
{
    if (y < l || r < x) return ;
    if (x <= l && r <= y)
    {
        for (int i = 0; i < 26; i++)
            cnt[i] += IT[k].x[i];
    }
    else
    {
        push_down(k, l, r);
        int m = (l + r) / 2;
        get(2 * k, l, m, x, y);
        get(2 * k + 1, m + 1, r, x, y);
    }
}

int main()
{
    scanf("%d %d\n%s\n", &N, &Q, S + 1);

    memset(lazy, -1, sizeof lazy);
    for (int i = 1; i <= N; i++)
        update(1, 1, N, i, i, S[i] - 'a');
    for (int l, r; Q--;)
    {
        scanf("%d %d", &l, &r);
        memset(cnt, 0, sizeof cnt);
        get(1, 1, N, l, r);

        int odd = 0, letter;
        for (int i = 0; i < 26; i++)
            if (cnt[i] & 1) odd++, letter = i;

        if (odd > 1) continue;
        for (int x = 0, i = 0; i < 26; i++)
            if (cnt[i] > 1)
            {
                update(1, 1, N, l + x, l + x + cnt[i] / 2 - 1, i);
                update(1, 1, N, r - x - cnt[i] / 2 + 1, r - x, i);
                x += cnt[i] / 2;
            }
        if (odd) update(1, 1, N, (l + r) / 2, (l + r) / 2, letter);
    }

    for (int i = 1; i <= N; i++)
    {
        memset(cnt, 0, sizeof cnt);
        get(1, 1, N, i, i);
        for (int j = 0; j < 26; j++)
            if (cnt[j]) printf("%c", j + 'a');
    }
}
