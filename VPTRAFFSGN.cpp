//https://code.cvp.vn/contest/9/problem/TRAFFSGN
#include <bits/stdc++.h>
using namespace std;

int N, x, Last_traff, Pos[100010];
set < pair <int, int> > S;

void Delete(int x)
{
    if (Pos[x])
    {
        S.erase(S.find(make_pair(Pos[x], x)));
        Pos[x] = 0;
    }
}

main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &x);
        Delete(x ? abs(x) : Last_traff);
        if (x > 0)
            S.insert(make_pair(Pos[x] = i, x));
        printf("%d ", Last_traff = S.size() ? (--S.end()) -> second : 0);
    }
}


