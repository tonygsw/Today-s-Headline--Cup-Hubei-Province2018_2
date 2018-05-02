/*
    author:gsw
    data:2018.05.02
    link:https://www.nowcoder.com/acm/contest/104/E
    accout:tonygsw
*/
#define ll long long
#define IO ios::sync_with_stdio(false);
#define maxn 1505

#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

int n,m,x,y,l;
ll dp[maxn][maxn];
int value[maxn][maxn];

void init()
{
    memset(dp,0,sizeof(dp));
}

int DP()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=max(dp[i][j],max(dp[i-1][j]+value[i][j],dp[i][j-1]+value[i][j]));
    printf("%lld\n",dp[n][n]);
}
inline void xz(int x,int y,int l)
{
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            int tem=value[x+i][y+j];
            //cout<<tem<<" ---------"<<endl;
            value[x+i][y+j]=value[x+i+l][y+j];
            value[x+i+l][y+j]=value[x+i+l][y+j+l];
            value[x+i+l][y+j+l]=value[x+i][y+j+l];
            value[x+i][y+j+l]=tem;
        }
    }
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    //cout<<n<<" "<<m<<"-----------"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&value[i][j]);
        }
    }
    //cout<<n<<" "<<m<<"-----------"<<endl;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&l);
        xz(x,y,l);
    }
/*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<value[i][j]<<" ";
        cout<<endl;
    }*/
    DP();
}

