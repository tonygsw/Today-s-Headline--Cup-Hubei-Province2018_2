#include <iostream>
#include <vector>
#include <cstring>

#include <queue>

using namespace std;

const int maxn = 100000 + 5;
const long long mod = 1007681537, g = 3;
vector<long long> ans[maxn];

typedef pair<int, int> pii;

long long pow_mod(long long a, long long b)
{
	long long ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

template <typename T>
__inline void clear(T& container) {
	container.clear();
	T(container).swap(container);
}

struct NTT {
	long long w[131072 * 2];
	int cur_w_dir = 0;
	void pre_processw(int oper, int n) {
		if (cur_w_dir == oper * n) return;
		w[0] = 1; w[1] = pow_mod(g, (mod - 1) / n);
		if (oper == -1) w[1] = pow_mod(w[1], mod - 2);
		for (int i = 2; i < n; i++) w[i] = w[i - 1] * w[1] % mod;
	}

	void fft(vector<long long> &P, int n, int oper) {
		pre_processw(oper, n);
		for (int i = 1, j = 0; i < n - 1; i++) {
			for (int s = n; j ^= s >>= 1, ~j & s;);
			if (i < j) swap(P[i], P[j]);
		}
		for (int d = 0; (1 << d) < n; d++) {
			int m = 1 << d, m2 = m * 2, rm = n >> (d + 1);
			for (int i = 0; i < n; i += m2) {
				for (int j = 0; j < m; j++) {
					long long &P1 = P[i + j + m], &P2 = P[i + j];
					long long t = w[rm * j] * P1 % mod;
					P1 = (P2 - t + mod) % mod;
					P2 = (P2 + t) % mod;
				}
			}
		}
		if (oper == -1) {
			int invn = pow_mod(n, mod - 2);
			for (int i = 0; i < n; i++)
				(P[i] *= invn) %= mod;
		}
	}
}ntt;

char buf[maxn];
int sizneed[maxn * 2];

int main()
{
	int n;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	scanf("%d", &n);
	for (int i = 1; i < maxn; i <<= 1)
	{
		for (int j = 0; j < i; j++) {
			sizneed[i + j] = (i << 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", buf);
		int len = strlen(buf);
		pq.push(pii(len / 2 + len % 2, i));
		ans[i].resize(len / 2 + len % 2);
		for (int j = 0; j < len; j++)
			ans[i][j / 2] = ans[i][j / 2] + (buf[len - j - 1] - '0') * ((j & 1) ? 10 : 1);
	}
	while (pq.size() > 1)
	{
		auto v1 = pq.top();pq.pop();
		auto v2 = pq.top();pq.pop();
		//--
		int resestlen = v1.first + v2.first;
		int needsz = sizneed[resestlen];
		//--
		ans[v1.second].resize(needsz, 0);
		ans[v2.second].resize(needsz, 0);
		//--
		ntt.fft(ans[v1.second], needsz, 1);
		ntt.fft(ans[v2.second], needsz, 1);
		//--
		for (int i = 0; i < needsz; i++)
			(ans[v1.second][i] *= ans[v2.second][i]) %= mod;
		//--
		ntt.fft(ans[v1.second], needsz, -1);
		//--
		for (int i = 0; i < needsz - 1; i++) {
			ans[v1.second][i + 1] += ans[v1.second][i] / 100;
			ans[v1.second][i] %= 100;
		}
		//--
		int new_len = needsz;
		while (ans[v1.second][new_len - 1] == 0) new_len--;
		//--
		clear(ans[v2.second]);
		//--
		pq.push(pii(new_len, v1.second));
	}
	pii res = pq.top();
	printf("%lld", ans[res.second][res.first - 1]);
	for (int i = res.first - 2; i >= 0; i--) {
		printf("%02lld", ans[res.second][i]);
	}
	printf("\n");
	return 0;
}
