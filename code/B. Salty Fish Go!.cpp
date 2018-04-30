/*
    author:gsw
    data:2018.04.30
    link:https://www.nowcoder.com/acm/contest/104/B
    accout:1697782237@qq.com(tonygsw)
*/
#define ll long long
#define IO ios::sync_with_stdio(false);

#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int v,l,n,m;
    while(~scanf("%d%d%d%d",&v,&l,&n,&m))
    {
        double speed=0;int tem;
        for(int i=0;i<v;i++)
        {
            scanf("%d",&tem);
            speed+=tem;
        }
        speed=speed/v;
        double s=double(m)*l/(double(m+1));
        double ans=s/speed;
        printf("%.9f\n",ans);
    }
}
