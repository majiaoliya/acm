#include <iostream> 
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;
#include <iostream>
#include <math.h>
#include <vector>
#define MAXN 16
#define ll long long int
using namespace std;

int n, m;

void dfs(int x, int state, int cnt) {
	if(cnt+n-x < m) return ; //剪枝 剩下的全选也达不到m就return
    if(cnt == m) {
        for(int i=0, c=0; i<n; i++) 
            if(state>>i & 1) {
                if(c++) printf(" ");
                printf("%d", i+1);
            }
		printf("\n");
		return ;
    }
    if(x == n) return;
    
    dfs(x+1, state|(1<<x), cnt+1);
    dfs(x+1, state, cnt);
}

int main(void) {
	freopen("test", "r", stdin);
    for( ; EOF != scanf("%d %d", &n, &m); ) {
        dfs(0, 0, 0);
    }
	return 0;
}


