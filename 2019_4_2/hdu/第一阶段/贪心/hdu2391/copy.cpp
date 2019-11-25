#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int map[1005][1005];

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        memset(map,0,sizeof(map));
        int r,c;
        scanf("%d%d",&r,&c);
        for(int j=1;j<=r;j++)
            for(int k=1;k<=c;k++)
            {
                scanf("%d",&map[j][k]);
                map[j][k] += max(map[j-1][k],map[j][k-1]);
            }
            printf("Scenario #%d:\n%d\n\n",i,map[r][c]);
    }
    return 0;
}

