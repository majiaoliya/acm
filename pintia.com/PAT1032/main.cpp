#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1000010

using namespace std;

int xhead, yhead, n;
struct Node {
	char val;
	int next;
} arr[MAXN];
bool vis[MAXN];

void iter(int ad) {
	while(ad != -1) {
		vis[ad] = true;
//		printf("%c,", arr[ad].val);
		ad = arr[ad].next;
	}
//	printf("\n");
}

int main()
{
    freopen("test", "r", stdin); 
   	scanf("%d %d %d", &xhead, &yhead, &n);
	int count = 0;
	memset(vis, false, n+5);
	for(int i=1; i<=n; i++) {
		int ad, val, nxt;
		scanf("%d %c %d", &ad, &val, &nxt);
		if(nxt == -1) count ++;
		arr[ad].val = (char)val, arr[ad].next = nxt;
	}
	iter(xhead);
	int tad = yhead;
	while(tad != -1) {
		if(vis[tad]) { printf("%05d\n", tad); return 0; }
		tad = arr[tad].next;
	}
	printf("-1\n");
    return 0;
}

