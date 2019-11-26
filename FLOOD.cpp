//https://code.cvp.vn/contest/11/problem/FLOOD
#include <bits/stdc++.h>
using namespace std;

int N, M, K, Time[111], ans;
bool picked[111];
vector <int> GRAPH[111];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > Q;

int calc()
{
    memset(Time, 0x3f, sizeof Time);
    while (!Q.empty()) Q.pop();

    Q.push(make_pair(Time[1] = 0, 1));
    while (!Q.empty())
    {
        pair <int, int> P = Q.top();      Q.pop();
        if (Time[P.second] != P.first) continue;
        if (P.second == N) return P.first;
        for (vector <int> :: iterator it = GRAPH[P.second].begin(); it != GRAPH[P.second].end(); it++)
        {
            int x = *it;
            int tx = P.first + picked[P.second] + 1;
            if (Time[x] > tx)
                Q.push(make_pair(Time[x] = tx, x));
        }
    }
}

void sub1()
{
    for (int mask = 1; mask < (1 << N); mask++)
        if (__builtin_popcount(mask) == K)
        {
            for (int i = 1; i <= N; i++)
                picked[i] = mask >> (i - 1) & 1;
            ans = max(ans, calc());
        }
}

void sub2()
{
    for (int i = 1; i <= K; i++) picked[i] = 1;

    srand(time(0));
    double start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < 0.95)
    {
        int x = 1 + rand()%N;
        int y = 1 + rand()%N;
        if (picked[x] + picked[y] == 1)
        {
            picked[x] ^= 1;
            picked[y] ^= 1;
            int cur = calc();
            if (cur >= ans) ans = cur;
                else
                {
                    picked[x] ^= 1;
                    picked[y] ^= 1;
                }
        }
    }
}

main()
{

    scanf("%d %d %d", &N, &M, &K);
    for (int u, v; M--; )
    {
        scanf("%d %d", &u, &v);
        GRAPH[u + 1].push_back(v + 1);
        GRAPH[v + 1].push_back(u + 1);
    }

    if (N <= 22) sub1();
        else sub2();

    printf("%d", ans);
}
