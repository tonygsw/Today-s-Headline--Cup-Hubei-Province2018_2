/*
    data:2018.04.27
    author:gsw
    link:https://www.nowcoder.com/acm/contest/104/H
    account:tonygsw
*/
#define ll long long
#define IO ios::sync_with_stdio(false);

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5+5;

class Node{
    public:
        int cnt,ls,rs;
};
Node tr[maxn*40];
int root[maxn];int cnt;

int in(int pre,int x,int deep)
{
    int num=++cnt;
    tr[num]=tr[pre];
    tr[num].cnt=tr[pre].cnt+1;
    if(deep<0)return num;
    if(!((x>>deep)&1))tr[num].ls=in(tr[pre].ls,x,deep-1);
    else tr[num].rs=in(tr[pre].rs,x,deep-1);
    return num;
}
int query(int l,int r,int x,int deep)
{
    if(deep<0)return 0;
    if(!((x>>deep)&1))
    {
        if(tr[tr[r].rs].cnt>tr[tr[l].rs].cnt)return (1<<deep)+query(tr[l].rs,tr[r].rs,x,deep-1);
        else return query(tr[l].ls,tr[r].ls,x,deep-1);
    }
    else
    {
        if(tr[tr[r].ls].cnt>tr[tr[l].ls].cnt)return (1<<deep)+query(tr[l].ls,tr[r].ls,x,deep-1);
        else return query(tr[l].rs,tr[r].rs,x,deep-1);
    }
}


int main()
{
    int n,x,m,b,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        root[i]=in(root[i-1],x,29);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&b,&l,&r);
        printf("%d\n",query(root[l-1],root[r],b,29));
    }
}
