//https://code.cvp.vn/contest/11/problem/BIGNUM
#include <bits/stdc++.h>
using namespace std;

int Q, ans;
char X[1010], Y[1010], Z[1010], op;
long long my_base[30];

long long mod(long long x, long long y, long long z)
{
    return ((x * (y / 1000000) % z * 1000000) % z + (x * (y % 1000000)) % z) % z;
}

long long Hash(char S[], int len, long long base)
{
    long long hsgs = 0;
    for (int i = 0 + (S[0] == '-'); i < len; i++)
        hsgs = (hsgs * 10 + S[i] - '0') % base;
    return (S[0] == '-') ? base - hsgs : hsgs;
}

main()
{
    srand(time(0));
    for (int i = 0; i < 30; i++)
        my_base[i] = 1LL * (1 + rand()%10000) * (1 + rand()%10000) * (1 + rand()%10000);

    scanf("%d", &Q);
    while (Q--)
    {
        scanf("\n%s %s %s %s", &X, &op, &Y, &Z);
        ans = 1;
        for (int i = 0, lenX = strlen(X), lenY = strlen(Y), lenZ = strlen(Z); i < 30; i++)
            if (op == '+')
                ans &= (Hash(Z, lenZ, my_base[i]) == (Hash(X, lenX, my_base[i]) + Hash(Y, lenY, my_base[i])) % my_base[i]);
            else if (op == '-')
                ans &= (Hash(Z, lenZ, my_base[i]) == (Hash(X, lenX, my_base[i]) - Hash(Y, lenY, my_base[i]) + my_base[i]) % my_base[i]);
            else ans &= (Hash(Z, lenZ, my_base[i]) == mod(Hash(X, lenX, my_base[i]), Hash(Y, lenY, my_base[i]), my_base[i]));
        printf("%s\n", ans ? "YES" : "NO");
    }
}
