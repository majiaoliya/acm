#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#define MAXN 36

using namespace std;
typedef long long int ui;

ui n, m, rs, arr[MAXN];

ui dfs() {
	ui ret = 1, tmax = 1<<n;
	for(ui i=1; i<tmax; i++) {
		ui temp = i, tw = 0;
		ui k = 1;
#define debug
#ifdef debug
		while(k <= n) {
#endif
#ifdef submit
		while(temp) {
#endif
			if(temp & 1) tw += arr[k];
#ifdef debug
			printf("%d ", temp&1);
#endif
			temp >>= 1;
			k++;
		}
		printf("\n");
		if(tw <= m) ret ++;
	}
	return ret;
}

void dfs(ui x, ui tm) {
	if(tm > m) return;
	if(x == n+1) {
		rs ++;
		return ;
	}
	dfs(x+1, tm+arr[x]);
	dfs(x+1, tm);
}

ui fpow(ui a, ui b) {
	ui rs = 1;
	while(b) {
		if(b & 1) rs = rs*a;
		b >>= 1;
		a = a*a;
	}
	return rs;
}
int main() {
	freopen("test", "r", stdin);
	while(EOF != scanf("%lld %lld", &n, &m)) {
		ui tmin, tsum;
		memset(&tmin, -1, sizeof(ui));
		memset(&tsum, 0, sizeof(ui));
		for(ui i=1; i<=n; i++) {
			scanf("%lld", arr+i);
			tmin = arr[i] < tmin ? arr[i] : tmin;
			tsum += arr[i];
		}
		if(tmin > m) { //剪枝
			printf("1\n");
			continue ;
		}
		
		if(tsum <= m) {
			printf("%lld\n", fpow(2, n));
			continue ;
		}
		
//		sort(arr+1, arr+1+n);
		rs = 0; 
		dfs(1, 0);
		printf("%lld\n", rs);
	}
	return 0;
}

