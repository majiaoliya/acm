
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int n, rs;
int pos[MAX];

void dfs(int level) {
	if(level == n) rs ++;
	else {
		for(int i=0; i<n; i++) {
			pos[level] = i;
			bool ok = true;
			for(int k=0; k<level; k++) {
				if(pos[level]==pos[k] || //检测是否同一列 
					level-pos[level]==k-pos[k] || level+pos[level]==k+pos[k]) {
					ok = false;
					break;
				}
			}
			if(ok) 
				dfs(level+1);
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n), n; ) {
		rs = 0;
		dfs(0);
		printf("%d\n", rs);
	}
	return 0;
}












/**

#include <cstring>
#include <cstdio>

int num;
int a[15];

void trial(int i, int n)
{
    if(i == n){
        num++;
        return;}
    else{
        for(int m=0;m<n;m++){
            int ok = 1;
            a[i] = m;
            for(int j=0;j<i;j++)
                if(a[i]==a[j]||i-a[i]==j-a[j]||i+a[i]==j+a[j])
                {
                    ok = 0;
                    break;
                }
            if(ok)
                trial(i+1,n);

        }

    }
}

int main()
{	
	freopen("test", "r", stdin);
    int N;
    while(scanf("%d",&N) == 1 && N!=0)
    {
        num = 0;
        memset(a,0,sizeof(a));
        trial(0, N);
        printf("%d\n",num);
    }
    return 0;
}
*/

