#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
struct act
{
    int s;
    int f;
    bool flag;
}a[maxn];

bool cmp(act a,act b)
{
    return a.s<b.s;
}

int main()
{
    int n,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].s,&a[i].f);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(!a[i].flag)
        {
            int temp=i;
            count++;
            a[i].flag=true;
            for(int j=i+1;j<n;j++)
            {
                if(a[j].s>=a[temp].f&&!a[j].flag)
                {
                    a[j].flag=true;
                    temp=j;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
