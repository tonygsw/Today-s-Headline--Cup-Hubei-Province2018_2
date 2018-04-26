#include <cstdio>
#include <vector>
using namespace std;

char num[100000 * 2];

int main()
{
	vector<int> n;
	freopen("test01.in", "w", stdout);
	freopen("test01.ans", "w", stderr);
	for (int i = 0;; i++)
	{
		scanf("%s", num);
		if (num[0] == 'a') break;
		int tans = 0;
		sscanf(num, "%d", &tans);
		n.push_back(tans);
//		fprintf(stdout, "%s\n", num);
//		fputs(num, stdout);
//		cout << num << endl;
	}
	fprintf(stdout, "%d\n", int(n.size()));
	for (int v : n) {
		fprintf(stdout, "%d\n", v);
	}
	scanf("%s", num);
	fprintf(stderr, "%s\n", num);
//	fputs(num, stderr);
//	cerr << num << endl;
}
