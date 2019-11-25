
#include <iostream>
#include <algorithm>
#define MAX 105
using namespace std;

int n;
int pre[MAX], arr[MAX], value[MAX], node_count[MAX];
char mtx[MAX][MAX];

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(x != ret) 
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int root_x = find_root(x);
	int root_y = find_root(y);
	if(root_x != root_y) {
		value[root_x] += value[root_y];
		node_count[root_x] += node_count[root_y];
		pre[root_y] = root_x;
	}
}

int main()
{
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d", &n);
		bool tag = false; //是否有敌方节点
		bool self_tag = false; //是否有己方节点
		for(int i=0; i<n; i++) {
			pre[i] = -1;
			node_count[i] = 1;
			scanf("%d", arr+i);
			value[i] = arr[i];
			if(arr[i] == 0) {
				tag = true; 
			} else if(arr[i] != 0) {
				self_tag = true;
			}
		}
		for(int i=0; i<n; i++) {
			scanf("%s", mtx[i]);
		}
		if(!tag || !self_tag) { printf("%d\n", -1); continue; }
		for(int i=0; i<n; i++) {
			for(int k=0; k<n; k++) {
				if(arr[i]!=0 && arr[k]!=0 && mtx[i][k]=='Y') {
					union_xy(i, k);
//						printf("union_xy(%d, %d)\n", i, k);
				}
			}
		}
//			for(int i=0; i<n; i++) 
//				printf("%d,", value[i]);
//			printf("\n");
		bool is_find = false;
		int min = 99999999;
		for(int i=0; i<n; i++) {
			if(arr[i] == 0) {
				for(int k=0; k<n; k++) {
					if(mtx[i][k] == 'Y') {
						int root_id = find_root(k);
						int can_get = value[root_id] - node_count[root_id] + 1;
						if(can_get < min) min = can_get;
						is_find = true;
					}
				}
			}
		}
		if(!is_find) 
			printf("%d\n", -1);
		else 
			printf("%d\n", min);
	}
	return 0;
}

