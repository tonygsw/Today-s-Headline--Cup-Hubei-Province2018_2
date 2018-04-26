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

int recode[maxn];
int in[maxn];
vector<int> g[maxn];
int n,a,b;int beg;
void init()
{
    for(int i=0;i<maxn;i++)
        recode[i]=1;
    memset(in,0,sizeof(in));
    for(int i=0;i<maxn;i++)
        g[i].clear();
}
int bfs(int beg,int fa)
{
    for(int i=0;i<g[beg].size();i++)
    {
        if(g[beg][i]==fa)continue;
        recode[beg]+=bfs(g[beg][i],beg);
    }
    return recode[beg];
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);g[b].push_back(a);
        in[a]++;in[b]++;
    }
    for(int i=1;i<=n;i++)
        if(in[i]==1)
        {
            beg=i;break;
        }
   // cout<<"beg="<<beg<<endl;
    bfs(beg,0);
    
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+recode[i])%mod; 
    printf("%d\n",ans);
}
