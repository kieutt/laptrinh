#include <bits/stdc++.h>
using namespace std;

int N, a[111111];

main()
{
    #ifndef KIEUQUOCDAT
        freopen("vao.inp", "r", stdin);
    #endif

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++)
        a[i] = max(a[i] + i, a[i - 1]);
    printf("%d", a[N]);
    for (int i = N; i > 1; i--)
    {
        a[i] = max(a[i] - N, a[i + 1]) + 1;
        a[i - 1] += N - i + 1;
        printf(" %d", max(a[i], a[i - 1]));
    }
}
