#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		cout << min(min(a, b), c) - 60 << ' ' << (a + b + c - min(min(a, b), c) - max(max(a, b), c) - 60) << ' ' << max(max(a, b), c) - 60 << endl;
	}
	return 0;
}
