#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int n,V,w[maxn],v[maxn],dp[maxn]={0},cnt=0;
bool vis[maxn]={false};

void Print(int t,int val,int weight)
{
    if(t>=n)
    {
        if(val==dp[V])
        {
            cnt++;
            printf("case %d:\n",cnt);
            for(int i=0;i<n;i++)
                if(vis[i])
                    printf("%d\n",i+1);
        }
    }
    else
    {
        if(weight+w[t]<=V)
        {
            vis[t]=true;
            Print(t+1,val+v[t],weight+w[t]);
        }
        vis[t]=false;
        Print(t+1,val,weight);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d,%d",&w[i],&v[i]);
    scanf("%d",&V);
    for(int i=0;i<n;i++)
        for(int j=V;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    //printf("%d\n",dp[V]);
    Print(0,0,0);
    return 0;
}
