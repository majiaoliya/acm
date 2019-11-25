#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 205
using namespace std;

int main()
{
    int t,n;
    int cnt[N];
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
         int maxn=-1,from,to;
         while(n--)
         {
             scanf("%d%d",&from,&to);
             if(from>to)
                swap(from,to);
             from=(from+1)/2;
             to=(to+1)/2;
             for(int i=from;i<=to;i++){
                cnt[i]++;//从from~to沿途经过的点都加一次
                if(cnt[i]>maxn)
                    maxn=cnt[i];
             }
         }
         printf("%d\n",maxn*10);
        }
    return 0;
}


