#include <bits/stdc++.h>
using namespace std;

string N;
int len, Nmin, Nmax;

int get(string X)
{
    int hsgs = 0;
    for (int i = 0; i < len; i++)
        hsgs = hsgs * 10 + X[i] - '0';
    return hsgs;
}

main()
{
    cin >> N;   len = N.size();
    Nmin = Nmax = get(N);
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
        {
            swap(N[i], N[j]);
            if (N[0] != '0')
            {
                Nmin = min(Nmin, get(N));
                Nmax = max(Nmax, get(N));
            }
            swap(N[i], N[j]);
        }
    cout << Nmin << " " << Nmax;
}
