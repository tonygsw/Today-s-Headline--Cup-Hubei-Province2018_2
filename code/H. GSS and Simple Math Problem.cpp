#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1000000000
#define mod 1000000007
#define N 350000
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const double pi = 3.141592653;
char s1[N>>1],s2[N>>1];
double rea[N],ina[N],reb[N],inb[N],ret[N],intt[N];
int i,len1,len2,lent,lenres,len;
int res[N>>1];
void FFT(double *reA,double *inA,int n,int flag)
{
    if (n == 1) return;
    int k,u,i;
    double reWm = cos(2*pi/n) , inWm = sin(2*pi/n);//本原根
    if (flag) inWm = -inWm;
    double reW = 1.0 , inW = 0.0;
    for (k = 1,u = 0;k < n; k += 2,u++)//奇数项和偶数项分开
        {ret[u] = reA[k]; intt[u] = inA[k];}
    for (k = 2;k < n; k += 2)
        {reA[k/2] = reA[k]; inA[k/2] = inA[k];}
    for (k = u,i = 0;k < n && i < u; k++,i++)
        {reA[k] = ret[i]; inA[k] = intt[i];}
    FFT(reA,inA,n/2,flag); FFT(reA+n/2,inA+n/2,n/2,flag);
    fo(k,0,n/2-1)//合并
        {
            int tag = n / 2 + k;
            double reT = reW * reA[tag] - inW * inA[tag];
            double inT = reW * inA[tag] + inW * reA[tag];
            double reU = reA[k] , inU = inA[k];
            reA[k] = reU + reT; inA[k] = inU + inT;
            reA[tag] = reU - reT; inA[tag] = inU - inT;
            double reWt = reW * reWm - inW * inWm;
            double inWt = reW * inWm + inW * reWm;
            reW = reWt; inW = inWt;
        }
}
void mul()
{
	    memset(res, 0 , sizeof(res)); 
        memset(rea, 0 , sizeof(rea));  
        memset(ina, 0 , sizeof(ina));  
        //memset(reb, 0 , sizeof(reb));  
       // memset(inb, 0 , sizeof(inb));  
    	len1 = strlen(s1); len2 = strlen(s2);
    	lent = (len1 > len2 ? len1 : len2);
		len = 1;
    	while (len < lent) len <<= 1;
		len <<= 1;
    	fo(i,0,len-1)
        {
            if (i < len1) rea[i] = (double) s1[len1-i-1] - '0';
            if (i < len2) reb[i] = (double) s2[len2-i-1] - '0';
            ina[i] = inb[i] = 0.0;
        }
    FFT(rea,ina,len,0); FFT(reb,inb,len,0);//求出a、b的点值表示法 
    fo(i,0,len-1)//求出c的点值表示法 
        {
            //printf("%.5lf %.5lf\n",rea[i],ina[i]);
            double rec = rea[i] * reb[i] - ina[i] * inb[i];
            double inc = rea[i] * inb[i] + ina[i] * reb[i];
            rea[i] = rec; ina[i] = inc;
        }
    FFT(rea,ina,len,1);//求出c的系数表示法
    fo(i,0,len-1) {rea[i] /= len; ina[i] /= len;}

    fo(i,0,len-1) res[i] = (int)(rea[i] + 0.5);
    fo(i,0,len-1) res[i+1] += res[i] / 10 , res[i] %= 10;

    lenres = len1 + len2 + 2;
    while (res[lenres] == 0 && lenres > 0) lenres--;
    int kk=0;
	fd(i,lenres,0)
    	s1[kk++]=res[i]+'0';
}
int main()
{
	   freopen("temin.txt","r",stdin);
    freopen("temout.txt","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		scanf("%s",s1);
		printf("%s\n",s1);
	}
	else
	{
		scanf("%s",s1);
		for(int i=1;i<n;i++)
		{
			scanf("%s",s2);
			mul();
		}
		printf("%s\n",s1);
	}
    return 0;
}
