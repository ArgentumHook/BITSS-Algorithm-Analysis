#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2000;
typedef struct Node
{
    int to,next;
}Graph;
Graph G[maxn];
int id,edge_num,node_num,node;
int head[maxn],dp[maxn][2],k;

void BuildGraph(int u,int v)
{
    G[k].to=v;
    G[k].next=head[u];
    head[u]=k;
    k++;
}

void MPC_DP(int u,int fa)
{
    dp[u][0]=1;
    dp[u][1]=0;
    for(int i=head[u];i!=-1;i=G[i].next)
    {
        int v=G[i].to;
        if(v==fa)
            continue;
        MPC_DP(v,u);
        dp[u][0]+=min(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}

int main()
{
    while(~scanf("%d",&node_num))
    {
        memset(head,-1,sizeof(head));
        int root=-1,k=0;
        for(int i=0;i<node_num;i++)
        {
            scanf("%d:(%d)",&id,&edge_num);
            for(int j=0;j<edge_num;j++)
            {
                scanf("%d",&node);
                BuildGraph(id,node);
            }
            if(!i)
                root=id;
        }
        MPC_DP(root,-1);
        printf("%d\n",min(dp[root][0],dp[root][1]));
    }
    return 0;
}
