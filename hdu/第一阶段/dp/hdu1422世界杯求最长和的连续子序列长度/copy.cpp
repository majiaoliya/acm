#include<iostream>
#include<cstdio>
#define N 200010
using namespace std;

int a[N],ans[N];

int main()
{
	freopen("test", "r", stdin);
    int n,i,t1,t2;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&t1,&t2);
            a[i]=a[i+n]=t1-t2;
            ans[i]=ans[i+n]=1;
        }
        for(i=1;i<2*n;i++)
        {
            if(a[i]+a[i-1]>=0&&a[i-1]>=0)
            {
                a[i]=a[i]+a[i-1];
                ans[i]+=ans[i-1];
                if(ans[i]==n) break;
            }
        }
        int max_ans=0;
        for(i=0;i<2*n;i++)
            if(max_ans<ans[i])
                max_ans=ans[i];
        printf("%d\n",max_ans);
    }
    return 0;
}
/*
5
3 1 1 2 1 4 4 2 1 2
*/
