
#include <iostream>
#include <algorithm>
#define MAX 5005
using namespace std;

struct Node {
	int l, w;
};

int n;
Node arr[MAX];
bool vis[MAX];

int cmp(Node& x, Node& y) { return x.l < y.l; }

int main()
{
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d %d", &(arr[i].l), &(arr[i].w));
		sort(arr, arr+n, cmp);
		int count = 1;
		for(int i=0; i<n; i++) {
			if(!vis[i]) {
				vis[i] = true;
				int tmax = 0;
				int max_id = i;
				for(int k=0; k<n; k++) {
					if(!vis[k] && arr[k].w<=arr[i].w) {
						if(arr[k].w>tmax) {
							tmax = arr[k].w;
							max_id = k;
						}
					}
				}
				vis[max_id] = true;
			}
		}
		printf("%d\n", count);
	}
	
	return 0;
}



