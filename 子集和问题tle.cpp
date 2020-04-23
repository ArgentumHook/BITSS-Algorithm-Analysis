#include<iostream>//TLE
#include<algorithm>
#include<cstring>
using namespace std;
int n,w[45]={0},x[45]={0},now_sum,target_sum,rest_sum,cnt;

void BackTrack(int t)
{
    if(rest_sum==0)
    {
        cnt++;
        return;
    }
    if(t>=n)
        return;
    rest_sum-=w[t];
    if(rest_sum<0)
    {
        rest_sum+=w[t];
        return;
    }
    if(now_sum+w[t]<=target_sum)
    {
        x[t]=1;
        now_sum+=w[t];
        BackTrack(t+1);
        now_sum-=w[t];
    }
    rest_sum+=w[t];
    x[t]=0;
    BackTrack(t+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int sum=((n+1)*n)/2;
    if(sum%2)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        w[i]=i+1;
    cnt=0,now_sum=0,rest_sum=target_sum=((n+1)*n)/4;
    BackTrack(0);
    cout<<cnt/2<<endl;
	return 0;
}
