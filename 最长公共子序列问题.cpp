#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10005;
char a[maxn],b[maxn];
int dp[2][maxn];
int main()
{
    int i,j;
    bool now,pre;
    scanf("%s%s",a,b);
    memset(dp,0,sizeof(dp));
    int lena=strlen(a),lenb=strlen(b);
    for(now=1,pre=0,i=0; i<lena; i++)
        for(swap(now,pre),j=0; j<lenb; j++)
            if(a[i]==b[j])
                dp[now][j+1]=dp[pre][j]+1;
            else
                dp[now][j+1]=dp[pre][j+1]>dp[now][j]?dp[pre][j+1]:dp[now][j];
    printf("%d\n",dp[now][lenb]);
    return 0;
}
