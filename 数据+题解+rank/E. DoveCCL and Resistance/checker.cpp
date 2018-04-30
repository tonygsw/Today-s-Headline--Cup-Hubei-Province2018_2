#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long pow_mod(long long a, long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

typedef long long ll;  
  
struct Frac {  
  
    ll a, b;  
  
    Frac() {a = 0; b = 1;}  
    Frac(ll a, ll b) {this->a = a; this->b = b; deal();}  
  
    void init() {a = 0; b = 1;}  
  
    ll gcd(ll a, ll b) {  
    while (b) {  
        ll tmp = a % b;  
        a = b;  
        b = tmp;  
    }  
    return a;  
    }  
  
    void deal() {  
    ll d = gcd(a, b);  
    a /= d; b /= d;  
    if (b < 0) {  
        a = -a;  
        b = -b;  
    }  
    }  
  
    Frac operator + (Frac c) {  
    Frac ans;  
    ans.a = a * c.b + b * c.a;  
    ans.b = b * c.b;  
    ans.deal();  
    return ans;  
    }  
  
    Frac operator - (Frac c) {  
    Frac ans;  
    ans.a = a * c.b - b * c.a;  
    ans.b = b * c.b;  
    ans.deal();  
    return ans;  
  
    }  
  
    Frac operator * (Frac c) {  
    Frac ans;  
    ans.a = a * c.a;  
    ans.b = b * c.b;  
    ans.deal();  
    return ans;  
    }  
  
    Frac operator / (Frac c) {  
    Frac ans;  
    ans.a = a * c.b;  
    ans.b = b * c.a;  
    ans.deal();  
    return ans;  
    }  
  
    void operator += (Frac c) {*this = *this + c;}  
    void operator -= (Frac c) {*this = *this - c;}  
    void operator *= (Frac c) {*this = *this * c;}  
    void operator /= (Frac c) {*this = *this / c;}  
  
    bool operator > (Frac c) {return a * c.b > b * c.a;}  
    bool operator == (Frac c) { return a * c.b == b * c.a;}  
    bool operator < (Frac c) {return !(*this < c && *this == c);}  
    bool operator >= (Frac c) {return !(*this < c);}  
    bool operator <= (Frac c) {return !(*this > c);}  
    bool operator != (Frac c) {return !(*this == c);}  
    bool operator != (ll c) {return *this != Frac(c, 1);}  
      
    void operator = (ll c) {this->a = c; this->b = 1;}  
};  
  
const int N = 105;  
  
int t, n, m, parent[N], node[N];  
Frac g[N][N], A[N][N];  
  
int find(int x) {  
    return x == parent[x] ? x : parent[x] = find(parent[x]);  
}  
  
Frac gauss(int n, int u, int v) {  
    for (int i = 0; i < n; i++) {  
    int r;  
    for (r = i; r < n; r++)  
        if (A[r][i] != 0)  
        break;  
    if (r == n) continue;  
    for (int j = 0; j <= n; j++) swap(A[i][j], A[r][j]);  
    for (int j = n; j > i; j--) A[i][j] /= A[i][i];  
    A[i][i] = 1;  
    for (int j = 0; j < n; j++) {  
        if (i == j) continue;  
        if (A[j][i] != 0) {  
        for (int k = n; k > i; k--)  
            A[j][k] -= A[j][i] * A[i][k];  
        A[j][i] = 0;  
        }  
    }  
    }  
    return A[u][n] / A[u][u] - A[v][n] / A[v][v];  
}  
  
Frac solve(int u, int v) {  
    int tu, tv, tn = 0;  
    for (int i = 0; i < n; i++) {  
    if (i == u) tu = tn;  
    if (i == v) tv = tn;  
    if (find(u) == find(i)) node[tn++] = i;  
    }  
    tn++;  
    for (int i = 0; i < tn; i++)  
    for (int j = 0; j <= tn; j++)  
        A[i][j].init();  
    for (int i = 0; i < tn - 1; i++) {  
    for (int j = 0; j < tn - 1; j++) {  
        if (i == j) continue;  
        int u = node[i], v = node[j];  
        A[i][i] += g[u][v];  
        A[i][j] -= g[u][v];  
    }  
    }  
    A[tu][tn] = 1;  
    A[tv][tn] = -1;  
    A[tn - 1][0] = 1;

    return gauss(tn, tu, tv);  
}

typedef pair<int, int> pii;
typedef pair<pii, int> edg;
vector<edg> es;

int id[105];

int fa[105];

int find_fa(int x)
{
    return (fa[x] == x) ? x : (fa[x] = find_fa(fa[x]));
}

void uni_fa(int x, int y)
{
    if (find_fa(x) == find_fa(y)) return;
    fa[find_fa(x)] = find_fa(y);
}

int main(int argc, char * argv[])
{
    setName("checker for circuit");
    registerTestlibCmd(argc, argv);

    long long p = inf.readInt();
    long long q = inf.readInt();
    long long target = p * pow_mod(q, mod - 2) % mod;

    int ansn = n = ouf.readInt(1, 100);
    int ansm = ouf.readInt(0, 1000);
    long long totw = 0;

    for (int i = 1; i <= n; i++) fa[i] = i;

    for (int i = 1; i <= ansm; i++)
    {
        int u, v, w;
        u = ouf.readInt(1, n);
        v = ouf.readInt(1, n);
        w = ouf.readInt(0, p);
        if (u == v) continue;
        if (w == 0) uni_fa(u, v);
        else es.push_back(edg(pii(u, v), w));
        totw += w;
    }
    if (totw > max(p, q))
        quitf(_wa, "sum w_i = %lld, but no greater than %lld expected", totw, max(p, q));
    //--
    memset(id, -1, sizeof id);
    //--
    int nnn = 0;
    for (int i = 1; i <= n; i++)
        if (find_fa(i) == i)
            id[i] = nnn++;
    
    for (int i = 1; i <= n; i++)
        if (id[i] == -1)
            id[i] = id[find_fa(i)];

    int S = ouf.readInt(1, n);
    int T = ouf.readInt(1, n);
    int s = id[(S)];
    int t = id[(T)];
    
    for (int i = 0; i < nnn; i++) {  
        parent[i] = i;  
        for (int j = 0; j < nnn; j++)  
        g[i][j].init();  
    }

    for (auto rr : es)
    {
        int u = id[rr.first.first];
        int v = id[rr.first.second];
        long long r = rr.second;
        if (u == v) continue;  
        g[u][v] += Frac(1, r);  
        g[v][u] += Frac(1, r);  
        int pu = find(u);  
        int pv = find(v);  
        if (pu != pv)  
        parent[pu] = pv;
    }

    int pu = find(s);
    int pv = find(t);

    if (pu != pv)
    {
        quitf(_wa, "%d and %d not connected", S, T);
    }
    n = nnn;
    Frac ans = solve(s, t);

    if (ans.a != p || ans.b != q)
    {
        quitf(_wa, "wrong answer, resistance between node %d and node %d is %lld/%lld, %lld/%lld expected", S, T, ans.a, ans.b, p, q);
    }

    quitf(_ok, "ok, resistance between node %d and node %d is %lld/%lld", S, T, ans.a, ans.b);
}
