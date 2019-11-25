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

int n, m, arr[MAXN], rs[MAXN];
bool vis[MAXN];

void dfs(int x) {
    if(x == n) {
        for(int i=0, c=0; i<n; i++) {
            if(c++) printf(" ");
            printf("%d", arr[rs[i]]);
        }
        printf("\n");
        return ;
    }
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        rs[x] = i;
        dfs(x+1);
        vis[i] = false;
    }   
}

int main(void) {
    for(int i=0; i<MAXN; i++)
        arr[i] = i+1;
	freopen("test", "r", stdin);
    for( ; EOF != scanf("%d", &n); ) {
        dfs(0);
    }
	return 0;
}


