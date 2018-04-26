#include <bits/stdc++.h>
#include <time.h> 
using namespace std;
const int N = 2e5+5;
const int MOD = 10000007;
int n,x,y;
long long ans,calc[N];
vector<int> G[N];
void dfs(int u,int fa)
{
	long long tmp = 1;
	for(int v : G[u])
	 if(v != fa) 
	 {
		 dfs(v,u);
		 tmp = (tmp * (calc[v]+1)) % MOD;
	 }
	(ans += tmp) %= MOD;
	calc[u] = tmp;
}
int main()
{
//	freopen("who10.in","r",stdin);
//	freopen("who10.ans","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i < n;i++)
	{
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans<<endl;
}
