#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 100000
using namespace std;

struct Node {
	int add, val, nxt;
} arr[MAXN];

int head, n, k;

void dsp() {
	int t = head;
	while(t != -1) {
		printf("[%d-%d-%d]->", arr[t].add, arr[t].val, arr[t].nxt);
		t = arr[t].nxt;
	}
}

void swap_list() {
	int cnt = 0;
	int t = head;
	while(t != -1) {
		cnt ++;
		if(cnt % k == 0) {
			
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d %d", &head, &n, &k);
	for(int i=1; i<=n; i++) {
		int add, val, nxt;
		scanf("%d %d %d", &add, &val, &nxt);
		arr[add].add = add, arr[add].val = val, arr[add].nxt = nxt;
	}
	dsp();
	return 0;
}

