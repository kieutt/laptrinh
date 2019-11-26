#include <bits/stdc++.h>
using namespace std;

int N, Q, IT[400004];
bool flip[400004];

void push_down(int k, int l, int r)
{
    if (flip[k])
    {
        int m = (l + r) / 2;
        flip[2 * k] ^= 1;       IT[2 * k] = (m - l + 1) - IT[2 * k];
        flip[2 * k + 1] ^= 1;   IT[2 * k + 1] = (r - m) - IT[2 * k + 1];
        flip[k] = 0;
    }
}

void update(int k, int l, int r, int x, int y)
{
    if (r < x || y < l) return ;
    if (x <= l && r <= y)
    {
        IT[k] = (r - l + 1) - IT[k];
        flip[k] ^= 1;
    }
    else
    {
        push_down(k, l, r);
        int m = (l + r) / 2;
        update(2 * k, l, m, x, y);
        update(2 * k + 1, m + 1, r, x, y);
        IT[k] = IT[2 * k] + IT[2 * k + 1];
    }
}

int get(int k, int l, int r, int x, int y)
{
    if (r < x || y < l) return 0;
    if (x <= l && r <= y) return IT[k];
    push_down(k, l, r);
    int m = (l + r) / 2;
    return get(2 * k, l, m, x, y) + get(2 * k + 1, m + 1, r, x, y);
}

main()
{
    scanf("%d %d", &N, &Q);
    for (int cmd, l, r; Q--; )
    {
        scanf("%d %d %d", &cmd, &l, &r);
        if (cmd == 1) update(1, 1, N, l, r);
            else printf("%d\n", get(1, 1, N, l, r));
    }
}
