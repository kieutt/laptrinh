//Đếm số là Palindrome <=N và chia hết cho m
#include <bits/stdc++.h>
using namespace std;
int oneDigit(int num)
{
    return (num >= 0 && num < 10);
}
bool isPalUtil(int num, int* dupNum)
{
    if (oneDigit(num))
        return (num == (*dupNum) % 10);
    if (!isPalUtil(num/10, dupNum))
        return false;
    *dupNum /= 10;
    return (num % 10 == (*dupNum) % 10);
}
int isPal(int num)
{
    if (num < 0)
       num = -num;
    int *dupNum = new int(num);
    return isPalUtil(num, dupNum);
}
int main() {
	int n, m, total = 0;
	cin >> n >> m;
	for(int i=1; i<=n; ++i)
		if(isPal(i) && i%m==0)
			total++;
	cout << total;
	return 0;
}
