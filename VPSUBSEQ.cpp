#include <bits/stdc++.h>
using namespace std;

int N, a[100010], L[100010], R[100010], ans[100010];
stack <int> S;

main()
{
    #ifndef KIEUQUOCDAT
        freopen("vao.inp", "r", stdin);
    #endif

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    S.push(0);
    for (int i = 1; i <= N; i++)
    {
        while (!S.empty() && a[S.top()] >= a[i]) S.pop();
        L[i] = S.top() + 1;
        S.push(i);
    }
    while (!S.empty()) S.pop();
    S.push(N + 1);
    for (int i = N; i; i--)
    {
        while (!S.empty() && a[S.top()] >= a[i]) S.pop();
        R[i] = S.top() - 1;
        S.push(i);
    }
    for (int i = 1; i <= N; i++)
		ans[R[i] - L[i] + 1] = max(ans[R[i] - L[i] + 1], a[i]);
	for (int i = N; i; i--)
		ans[i] = max(ans[i], ans[i + 1]);

	for (int i = 1; i <= N; i++)
        printf("%d ", ans[i]);
}

