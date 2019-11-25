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
vector<int> v;

/**
void dfs(int x, int state) {
	if(x == n) {
		for(auto x : v)
			printf("%d ", x);
		printf("\n");
		return 	;
	}
	for(int i=0; i<n; i++) {
		if(state>>i & 1) continue;
		v.push_back(arr[i]);
		dfs(x+1, state|1<<i);
		v.pop_back();
	}
}
*/

void dfs(int x, int state) {
	if(x == n) {
		for(int i=0, c=0; i<n; i++) {
			if(c++) printf(" ");
			printf("%d", arr[rs[i]]);
		}
		printf("\n");
		return 	;
	}
	for(int i=0; i<n; i++) {
		if(state>>i & 1) continue;
		rs[x] = i;
		dfs(x+1, state|1<<i);
	}
}

int main(void) {
    for(int i=0; i<MAXN; i++)
        arr[i] = i+1;
	freopen("test", "r", stdin);
    for( ; EOF != scanf("%d", &n); ) {
        dfs(0, 0);
    }
	return 0;
}


