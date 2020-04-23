#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e4+5;
const double ep=1e-6;
int n,k;
double a[maxn],sum;
double binSearch(double left,double right);
bool isEqual(double a,double b);

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lf",&a[i]);
    sum=0.0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    printf("%.2lf\n",binSearch(0.0,sum/(k*1.0)));
    return 0;
}

bool isEqual(double a, double b)
{
    if(fabs(a-b)<ep)
        return true;
    return false;
}

double binSearch(double left,double right)
{
    double mid=(left+right)/2.0;
    int cnt=0;
    for(int i=0;i<n;i++)
        cnt+=(int)(a[i]/mid);
    if(isEqual(left,right)&&cnt==k)
        return mid;
    else if(cnt>=k)
        return binSearch(mid,right);
    else
        return binSearch(left,mid);
}
