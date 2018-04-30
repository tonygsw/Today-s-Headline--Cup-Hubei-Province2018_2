#include <bits/stdc++.h>
using namespace std;
int main()
{
	random_device rd;
	int n = 2, m = 2;
	while (__gcd(n, m) != 1)
	{
		n = rd() % 100 + 1;
		m = rd() % 100 + 1;
	}
	cout << n << ' ' << m <<endl;
	return 0;
}
