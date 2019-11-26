//https://code.cvp.vn/contest/11/problem/COLOR

#include <bits/stdc++.h>
using namespace std;

int N, M, a[44], c[44];
map <long long, long long> data[2];
long long ans = LONG_LONG_MAX;

void sub1()
{
    for (int mask = 0; mask < (1 << N); mask++)
    {
        long long sumA = 0, sumC = 0;
        for (int i = 1; i <= N; i++)
            if (mask >> (i - 1) & 1)
            {
                sumA += a[i];
                sumC += c[i];
            }
        if (sumA == M) ans = min(ans, sumC);
    }
}

void build(int n, int id)
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        long long sumA = 0, sumC = 0;
        for (int i = 1; i <= n; i++)
            if (mask >> (i - 1) & 1)
            {
                sumA += a[id == 0 ? i : i + N / 2];
                sumC += c[id == 0 ? i : i + N / 2];
            }
        if (data[id].count(sumA)) data[id][sumA] = min(data[id][sumA], sumC);
            else data[id][sumA] = sumC;
    }
}

void sub2()
{
    build(N / 2, 0);
    build(N - N / 2, 1);

    if (data[0].count(M)) ans = min(ans, data[0][M]);
    if (data[1].count(M)) ans = min(ans, data[1][M]);
    for (map <long long, long long> :: iterator it = data[0].begin(); it != data[0].end(); it++)
        if (it -> first > M) break;
            else if (data[1].count(M - (it -> first)))
                ans = min(ans, it -> second + data[1][M - it -> first]);
}

main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> c[i];

    if (N <= 20) sub1();
        else sub2();

    cout << (ans == LONG_LONG_MAX ? -1 : ans);
}
