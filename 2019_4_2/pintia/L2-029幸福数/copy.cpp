#include <iostream>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <sstream>
#define  maxn 10005
typedef long long ll;
const ll inf=99999999;
using namespace std;
int re[maxn]={0};
bool isprime(int x)
{
    int t=sqrt(x);
    for(int i=2;i<=t;i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
   	freopen("test", "r", stdin);
    int a,b;
    scanf("%d %d",&a,&b);
    for(int x=a;x<=b;x++)
    {
        int t=x;
        if(!re[x]) //目前这个值不依赖
        {
            int vis2[maxn]={0};
            while (1)
            {
                int tmp=0;
                while (x)
                {
                    tmp += (int) pow((x % 10), 2);
                    x /= 10;
                }
                x = tmp;
                if(x==1) break;
                re[x]=1;//迭代出来的数都不是独立的
                if(vis2[x])//死循环
                {
                    re[x]=1;
                    re[t]=1;
                    break;
                }
                vis2[x]=1;//标记迭代内出现的数
            }
        }
        x=t;
    }
    int c=0;
    for(int x=a;x<=b;x++)
    {
        int t=x;
        if(!re[x])//不依赖
        {
            int num=0,res=x;
            if(isprime(x))
                c=2;
            else 
                c=1;
            while(x!=1)
            {
                num++;
                int tmp=0;
                while (x)
                {
                    tmp += (int) pow((x % 10), 2);
                    x /= 10;
                }
                x=tmp;
            }
            printf("%d %d\n",res,c*num);
        }
        x=t;
    }
    if(c==0)
        printf("SAD");
    return 0;
}
