#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
int n,len,a[20],b[20],cnt;
 
int cmp(int a,int b)
{
    return a>b;
}
 
void dfs(int x,int posa,int sum,int posb)
{
    int i;
    if(sum>n)
        return;
    if(sum == n)
    {
        cnt++;
        for(i = 0; i<posb; i++)
        {
            if(i)
                printf("+%d",b[i]);
            else
                printf("%d",b[i]);
        }
        printf("\n");
    }
    for(i = posa; i<len; i++)
    {
        b[posb] = a[i];
        dfs(a[i],i+1,sum+a[i],posb+1);
        while(i+1<len && a[i] == a[i+1])//搜索完毕后，若下一个搜索的数仍与当前相同，则跳过直至不相同  
            i++;
    }
}
 
int main()
{
	freopen("test", "r", stdin);
    int i;
    while(~scanf("%d%d",&n,&len),n+len!=0)
    {
        for(i = 0; i<len; i++)
            scanf("%d",&a[i]);
        sort(a,a+len,cmp);
        printf("Sums of %d:\n",n);
        cnt = 0;
        dfs(0,0,0,0);
        if(!cnt)
            printf("NONE\n");
    }
 
    return 0;
}
