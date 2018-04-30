/*
    author:gsw
    data:2018.04.30
    link:https://www.nowcoder.com/acm/contest/104/B
    accout:1697782237@qq.com(tonygsw)
*/
#define ll long long
#define IO ios::sync_with_stdio(false);

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
void dg(int x,int y,int k,int num)
{
    if(y==0)return;
    n=max(num,n);
    int a=x/y;
    m++;
    x=x-a*y;
    if(x==0){
    	m++;return;
	}
    int b=y/x;
    m+=b;
    int y1=y-b*x;
    int x1=x;
    dg(x1,y1,num,num+1);
}
void print(int x,int y,int k,int num)
{
    if(y==0)return;
    int a=x/y;
    printf("%d %d %d\n",k,num,a);
    x=x-a*y;
    if(x==0)
    {
    	printf("%d %d %d\n",num,2,0);
    	return;
	}
    int b=y/x;
    for(int i=0;i<b;i++)
        printf("%d %d %d\n",num,2,1);
    int y1=y-b*x;
    int x1=x;
    print(x1,y1,num,num+1);
}
int p,q;

int main()
{
    scanf("%d%d",&p,&q);
    n=m=0;
    dg(p,q,1,3);
    printf("%d %d\n",n,m);
    print(p,q,1,3);
    printf("1 2");
}
