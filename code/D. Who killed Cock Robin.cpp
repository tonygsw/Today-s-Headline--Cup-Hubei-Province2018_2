/*
    data:2018.04.22
    author:gsw
    link:https://www.nowcoder.com/acm/contest/104#question
    tip:武大校赛--补题
*/
#define IO ios::sync_with_stdio(false);
#define ll long long
#define mod 10000007
#define maxn 200005

#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[maxn];
vector<int> g[maxn];
int a,b,n,ans=0;
void init()
{
    memset(dp,0,sizeof(dp));
}

void dfs(int node,int fa)
{
    ll t=1;
    for(int i=0;i<g[node].size();i++)
    {
        if(g[node][i]==fa)continue;
        dfs(g[node][i],node);
        t=(t+t*dp[g[node][i]])%mod;
    }
    dp[node]=t;
    ans=(ans+t)%mod;
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);g[b].push_back(a);
    }
    dfs(1,0);
    printf("%d\n",ans);
}
