#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
typedef pair<int, int> pii;
vector<pii> e[maxn];
int totn;

void gcd(int p, int q, int u, int v, int tp)
{
    if (q == 0)
    {
        if (tp)
            e[u].push_back(pii(v, 0));
        return;
    }
    int r = p / q;
    if (tp)
    {
        for (int i = 0; i < r; i++)
            e[u].push_back(pii(v, 1));
        gcd(q, p % q, u, v, tp ^ 1);
    }
    else
    {
        totn++;
        e[u].push_back(pii(totn, r));
        gcd(q, p % q, totn, v, tp ^ 1);
    }
}

int main()
{
    int p, q;
    cin >> p >> q;
    totn = 2;
    gcd(p, q, 1, 2, 0);
    int sume = 0;
    for (int i = 1; i <= totn; i++)
        sume += e[i].size();
    cout << totn << ' ' << sume << endl;
    for (int i = 1; i <= totn; i++)
    {
        for (pii ee : e[i])
        {
            cout << i << ' ' << ee.first << ' ' << ee.second << endl;
        }
    }
    cout << 1 << ' ' << 2 << endl;
    return 0;
}