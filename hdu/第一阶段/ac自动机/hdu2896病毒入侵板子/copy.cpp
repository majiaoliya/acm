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
#include <set>
#include <queue>
#define ll long long int
#define QAQ (0)

using namespace std;

const int MAXN = 500*200 + 10;
int sol[510];

struct Tire {
	int next[MAXN][128], fail[MAXN], end[MAXN];
	int root, L;
	int newnode() {
		for(int i=0; i<128; i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L - 1;
	}
	void init() { L = 0; root = newnode(); }
	void insert(char* buf, int id) {
		int now = root;
		for(int i=0; buf[i]; i++) {
#define bufi (int)(buf[i])
			if(next[now][bufi] == -1) next[now][bufi] = newnode();
			now = next[now][bufi];
		}
		end[now] = id;
	}
	void build() {
		queue<int> Q;
		fail[root] = root;
		for(int i=0; i<128; i++)
			if(next[root][i] == -1) next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		while(!Q.empty()) {
			int now = Q.front(); Q.pop();
			for(int i=0; i<128; i++) 
				if(next[now][i] == -1) 
					next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
		}
	}
	bool query(char* buf) {
		int now = root, falg = 0;
		for(int i=0; buf[i]; i++) {
			now = next[now][bufi];
			for(int t=now; t!=root; t=fail[t])
				if(end[t]) {
					sol[end[t]] = 1;
					falg = true;
				}
		}
		return falg;
	}
} ac;

char buf[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	int n, m;
	while(~scanf("%d ", &n)) {
		ac.init();
		int tot = 0;
		for(int i=1; i<=n; i++) 
			scanf("%s ", buf), ac.insert(buf, i);
		ac.build();
		scanf("%d ", &m);
		for(int i=1; i<=m; i++) {
			scanf("%s ", buf);
			bool falg = ac.query(buf);
			if(falg) {
				tot ++;
				printf("web %d:", i);
				for(int j=1; j<=n; j++) {
					if(sol[j]) {
						sol[j] = 0;
						printf(" %d", j);
					}
				}
				printf("\n");
			}
		}
		printf("total: %d\n", tot);
	}





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




