#include <bits/stdc++.h>
using namespace std;

int M, cnt[300];
char status;

main()
{
    #ifndef KIEUQUOCDAT
        freopen("vao.inp", "r", stdin);
    #endif

    scanf("%d\n", &M);
    for (int i = 1; i <= M; i++)
    {
        scanf("%c", &status);
        cnt[status]++;
    }
    printf("%d", M - max(cnt['E'], max(cnt['W'], max(cnt['S'], cnt['N']))));
}

