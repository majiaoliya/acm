
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 32

using namespace std;
float arr[5];

//float abs(float x) { return x > 0 ? x : -x; }

//上底下底 左边长度 右边长度
bool check(float up, float down, float lef, float rig) {
	float sub = abs(up-down);
	if(lef+rig>sub && lef+sub>rig && rig+sub>lef) return true;
	else return false;
}

float check(float up, float down, float lef, float rig) {
	float sub = abs(up-down);
	if(lef+rig>sub && lef+sub>rig && rig+sub>lef) return true;
	else return false;
}

int rs[5];
bool vis[5];

void dfs(int x) {
	if(x == 5) {
		for(int i=1; i<=4; i++) {
			printf("%.0f,", arr[rs[i]]);
		}
		bool ok = check(arr[rs[1]], arr[rs[2]], arr[rs[3]], arr[rs[4]]);
		printf("\t%s", ok ? "Yes" : "No");
		if(ok) printf("\t%f", mj(arr[rs[1]], arr[rs[2]], arr[rs[3]], arr[rs[4]]));
		printf("\n");
		return ;
	}
	for(int i=1; i<=4; i++) {
		if(!vis[i]) {
			vis[i] = true;
			rs[x] = i;
			dfs(x+1);
			vis[i] = false;
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%f %f %f %f", arr+1, arr+2, arr+3, arr+4);
		for(int i=1; i<=4; i++)
			rs[i] = i;
		dfs(1);
		printf("\n");
	}
	
	return 0;
}
