//https://code.cvp.vn/contest/9/problem/FINDSUM2
#include <bits/stdc++.h>
using namespace std;

int N, Q, a[5005], f[50005];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > myqueue;

main()
{
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    memset(f, 0x3f, sizeof f);
    myqueue.push(make_pair(f[0] = 0, 0));
    while (!myqueue.empty())
    {
        pair <int, int> P = myqueue.top();        myqueue.pop();
        for (int i = 1; i <= N; i++)
        {
            int y = (P.second + a[i]) % a[1];
            if (f[y] > P.first + a[i])
                myqueue.push(make_pair(f[y] = P.first + a[i], y));
        }
    }

    for (int M; Q--; )
    {
        scanf("%d", &M);
        printf("%s\n", M >= f[M % a[1]] ? "yes" : "no");
    }
}
