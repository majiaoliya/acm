#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#define MAXN (100005)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, arr[MAXN], tmp[MAXN], sz = 0;
#define M ('z'-'A'+5)
string str;

struct Node {
	int id;
	int next[M];
	Node() : id(0) { memset(next, false, sizeof(next)); }
} root, tree[500005];

void insert(string& s, int sid) {
	int now = 0;
	int len = s.length();
	for(int i=0; i<len; i++) {
		int pos = s[i] - 'A';
		if(!tree[now].next[pos]) tree[now].next[pos] = (++sz);
		now = tree[now].next[pos];
		//if(!now->next[pos]) now->next[pos] = new Node();
		//now = now->next[pos];
	}
	tree[now].id = sid;
}

int searchid(string& s) {
	int now = 0;
	int len = s.length();
	for(int i=0; i<len; i++) {
		int pos = s[i] - 'A';
		if(!tree[now].next[pos]) return false;
		now = tree[now].next[pos];
	}
	return tree[now].id;
}

ll ans = 0;
void merge(int lef, int rig) {
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	merge(lef, mid);
	merge(mid+1, rig);
	int i = 0, x = lef, y = mid + 1;
	for(i=0; i<(rig-lef+1); i++) {
		if(x<=mid && y<=rig) {
			if(arr[x] > arr[y]) 
				ans += mid-x+1, tmp[i] = arr[y++];
			else tmp[i] = arr[x++];
		} else if(x <= mid) tmp[i] = arr[x++];
		else if(y <= rig) tmp[i] = arr[y++];
	}
	for(int i=0; i<(rig-lef+1); i++)
		arr[lef+i] = tmp[i];
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	cin.ignore();
	for(int i=1; i<=n; i++) {
		cin >> str;
		insert(str, i);
	}
	for(int i=1; i<=n; i++) {
		cin >> str;
		arr[i] = searchid(str);
	}
	merge(1, n);
	printf("%lld\n", ans);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


