
#include <iostream>
#include <algorithm>
#define MAX 100005
using namespace std;
int n, m; 

struct Node {
	int s, e, val;
};

Node arr[MAX];

int cmp(Node& x, Node& y) { return x.val > y.val; }

int main()
{
	freopen("test", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &arr[i].s, &arr[i].e, &arr[i].val);
//		printf("%d, %d, %d\n", arr[i].s, arr[i].e, arr[i].val);
	}
	
	sort(arr, arr+m, cmp);
	for(int i=0; i<m; i++) {
		printf("%d, %d, %d\n", arr[i].s, arr[i].e, arr[i].val);
	}
	return 0;
}

