
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int n, m, rs, s_row, s_col, cur_max;
char mtx[MAX][MAX];
bool vis[MAX][MAX];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int row, int col) {
	if(rs > n*m) return ;
	rs ++;
	vis[row][col] = true;
	for(int i=0; i<4; i++) {
		int nrow = row+dr[i];
		int ncol = col+dc[i];
		if(nrow<0 || nrow>=m || ncol<0 || ncol>=n) continue ;
		if(vis[nrow][ncol]) continue ;
		if(vis[nrow][ncol] == '#') continue ;
		dfs(nrow, ncol);
	}
	vis[row][col] = false;
}

int main()
{
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d %d", &n, &m), n+m; ) {
		rs = 0, cur_max = 0;
		for(int i=0; i<m; i++) {
			scanf("%s", mtx[i]);
			for(int k=0; k<n; k++) 
				if(mtx[i][k]=='@') s_row = i, s_col = k;
		}
		dfs(s_row, s_col);
		cout << rs << endl;
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

