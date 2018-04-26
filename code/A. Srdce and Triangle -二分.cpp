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
int a,b,c;
using namespace std;

const double expp=1e-11;
const double pi=3.14159265358;
const double g3=sqrt(3)/2;
double cosc,x,y,ad,cd,bd,cos_c,th1,th2,mid,ans[3];
inline bool judge(double th1)
{
    th2=180-a-th1;
    th1=th1/180*pi;th2=th2/180*pi;
    th1=tan(th1);th2=tan(th2);
    x=th2/(th2+th1);
    y=x*th1;
    ad=x*x+y*y;
    cd=(x-0.5)*(x-0.5)+(y-g3)*(y-g3);
    cos_c=(ad+cd-1)/(2*sqrt(ad*cd));
    if(cos_c>cosc)return 1;
    else return 0;
}
inline double ef(double l,double r)
{
    while(r-l>expp)
    {
        mid=(l+r)/2;
        if(judge(mid))l=mid;
        else r=mid;
    }
    return l;
}
int main()
{
   freopen("temin.txt","r",stdin);
    freopen("temout.txt","w",stdout);

    while(~scanf("%d%d%d",&a,&b,&c))
    {
        cosc=cos((double)c/180*pi);
        th1=ef(0,min(180-a,60));
        th2=180-a-th1;
        th1=th1/180*pi;th2=th2/180*pi;
        th1=tan(th1);th2=tan(th2);
        x=th2/(th2+th1);
        y=x*th1;//th2*th1/(th2+th1);
        //cout<<x<<" "<<y<<endl;
        ad=x*x+y*y;
        cd=(x-0.5)*(x-0.5)+(y-g3)*(y-g3);
        bd=(x-1)*(x-1)+y*y;
        //cout<<ad<<" "<<cd<<" "<<bd<<endl;
        ans[0]=acos((ad+cd-bd)/(2*sqrt(ad*cd)))/pi*180;
        ans[1]=acos((ad+bd-cd)/(2*sqrt(ad*bd)))/pi*180;
        ans[2]=acos((bd+cd-ad)/(2*sqrt(bd*cd)))/pi*180;
        sort(ans,ans+3);
        printf("%f %f %f\n",ans[0],ans[1],ans[2]);
    }
}
