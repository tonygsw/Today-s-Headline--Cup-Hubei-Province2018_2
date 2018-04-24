/*
    data:2018.04.22
    author:gsw
    link:https://www.nowcoder.com/acm/contest/104#question
    tip:武大校赛--补题
*/
#define IO ios::sync_with_stdio(false);
#define ll long long

#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        int ans[3];
        ans[0]=a-60;
        ans[1]=b-60;
        ans[2]=c-60;
        sort(ans,ans+3);
        printf("%d %d %d\n",ans[0],ans[1],ans[2]);
    }
}
