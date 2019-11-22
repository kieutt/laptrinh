#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
struct node
{
    int L, R, M, sum, tag;
    node operator + (const node & op) const
    {
        node ret;
        ret.L = L + (M == sum ? op.L : 0);
        ret.R = op.R + (op.M == op.sum ? R : 0);
        ret.M = max(max(M, op.M), max(max(ret.L, ret.R), R + op.L));
        ret.sum = sum + op.sum;
        ret.tag = -1;
        return ret;
    }
} IT[2002002];

void refresh(int k, int l, int r, int t)
{
    IT[k].tag = t;
    IT[k].L = IT[k].R = IT[k].M = (t ? 0 : r - l + 1);
}

void build(int k, int l, int r)
{
    IT[k].L = IT[k].R = IT[k].M = IT[k].sum = r - l + 1;
    IT[k].tag = -1;
    if (l == r) return;
    build(2 * k, l, (l + r) / 2);
    build(2 * k + 1, (l + r) / 2 + 1, r);
}

void push_down(int k, int l, int r)
{
    if (IT[k].tag == -1) return;
    refresh(2 * k, l, (l + r) / 2, IT[k].tag);
    refresh(2 * k + 1, (l + r) / 2 + 1, r, IT[k].tag);
    IT[k].tag = -1;
}

void update(int k, int l, int r, int x, int y, bool v)
{
    if (r < x || y < l) return;
    if (x <= l && r <= y) refresh(k, l, r, v);
    else
    {
        push_down(k, l, r);
        update(2 * k, l, (l + r) / 2, x, y, v);
        update(2 * k + 1, (l + r) / 2 + 1, r, x, y, v);
        IT[k] = IT[2 * k] + IT[2 * k + 1];
    }
}

int query(int k, int l, int r, int p)
{
    push_down(k, l, r);
    if (IT[k].L >= p) return l;
    int m = (l + r) / 2;
    if (IT[2 * k].M >= p) return query(2 * k, l, m, p);
    if (IT[2 * k].R + IT[2 * k + 1].L >= p) return m - IT[2 * k].R + 1;
    if (IT[2 * k + 1].M >= p) return query(2 * k + 1, m + 1, r, p);
    return -1;
}

node get(int k, int l, int r, int x, int y)
{
    if (r < x || y < l) return {-1e9, -1e9, -1e9, -1e9};
    if (x <= l && r <= y) return IT[k];
    push_down(k, l, r);
    node r1 = get(2 * k, l, (l + r) / 2, x, y);
    node r2 = get(2 * k + 1, (l + r) / 2 + 1, r, x, y);
    if (r1.sum == -1e9) return r2;
    if (r2.sum == -1e9) return r1;
    return r1 + r2;
}

main()
{
    scanf("%d %d\n", &N, &M);
    build(1, 1, N);
    for (int p, l, r; M--;)
        if (getchar() == 'A')
        {
            scanf("%d\n", &p);
            int pos = query(1, 1, N, p);
            if (pos == -1) ans++;
                else update(1, 1, N, pos, pos + p - 1, 1);
        }
        else
        {
            scanf("%d %d\n", &l, &r);
            update(1, 1, N, l, r, 0);
        }
    printf("%d", ans);
}
