#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
const int maxn=4000005;
int a[maxn];
int Find(int *a,int start,int end,int size);

int main()
{
    int n=0,x,y;
    while(~scanf("%d,%d",&x,&y))
        a[n++]=y;
    int mid=Find(a,0,n-1,(n+1)/2);
    printf("%d\n",mid);
    return 0;
}

int Find(int *nums,int start,int end,int size)
{
    int mid=rand()%(end-start+1)+start;
    int pivot=nums[mid];
    int i=start-1,j=end+1;
    for(int k=start;k<j;k++)
    {
        if(nums[k]<pivot)
        {
            i++;
            swap(nums[i],nums[k]);
        }
        else if(nums[k]>pivot)
        {
            j--;
            swap(nums[j],nums[k]);
            k--;
        }
    }
    if(i-start+1>=size)
        return Find(nums,start,i,size);
    else if (j-start>=size)
        return nums[j-1];
    else
        return Find(nums,j,end,size-(j-start));
}
