#include <bits/stdc++.h>
using namespace std;
int main()
{
	random_device rd;
	for (int i = 0; i < 100000; i++)
	{
		int a = rd() % 300 + 60;
		int b = rd() % 300 + 60;
		int c = 360 - a - b;
		while (a <= 60 || b <= 60 || c <= 60 || a >= 180 || b >= 180 || c >= 180)
		{
			a = rd() % 300 + 60;
			b = rd() % 300 + 60;
			c = 360 - a - b;
		}
		cout << a << ' ' << b << ' ' << c << endl;
	}
	return 0;
}
