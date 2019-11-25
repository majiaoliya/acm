#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <set>
#define MAXN 10005
using namespace std;

int n, arr[MAXN], tree[MAXN];
int idx = 1;

void inorder(int root) {
	if(root > n) return ;
	inorder(root<<1);
	tree[root] = arr[idx++];
	inorder(root<<1|1);
}

int main()
{
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	sort(arr+1, arr+1+n);
	
	inorder(1);
	for(int i=1; i<=n; i++) {
		if(i!=1) printf(" ");
		printf("%d", tree[i]);
	}
	return 0;
}







