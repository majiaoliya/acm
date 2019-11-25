//给定数组nums = {1,2,3,4,5},给定目标值target = 9,那么所能得到的结果有
#include <iostream>
#define MAX 30
using namespace std;

int n, m;
int arr[MAX];
bool vis[MAX];

void bt(int i, int cur_value) {
	if(i > n) return;
	if(cur_value == m) { //找到
		for(int k=0; k<n; k++)
			if(vis[k]) printf("%d,", arr[k]);
		printf("\n");
		return;
	}
	int t = cur_value + arr[i];
	if(t <= m) {
		vis[i] = true;
		bt(i+1, t);
		vis[i] = false;
	}
	bt(i+1, cur_value);	
}

int main(void) {
		
	freopen("test", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	bt(0, 0);
	return 0;
}
