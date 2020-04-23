#include<iostream>//AC
using namespace std;
int n,dp[40][500]={0};
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
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum/2;j++)
        {
            if(j<i)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
        }
    }
    cout<<dp[n][sum/2]<<endl;
	return 0;
}
