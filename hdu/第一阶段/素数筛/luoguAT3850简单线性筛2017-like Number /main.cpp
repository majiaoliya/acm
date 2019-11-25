#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <unordered_set>
#define IS_PRIME(x) (!vis[x])
#define ll long long int

using namespace std;

int prime[MAXN], n, pn, vis[MAXN];
int sum[MAXN]; //统计符合要求的前缀和

void get_prime() {
	vis[0] = vis[1] = true;
	int MN = MAXN- 1;
	for(int i=2; i<MN; i++) {
		if(!vis[i]) {
			prime[pn++] = i;
		}
		if(i!=2 && IS_PRIME(i) && IS_PRIME((i+1)>>1))
		   sum[i] = sum[i-1] + 1;
		else sum[i] = sum[i-1];

		for(int k=0; k<pn && i*prime[k]<MN; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	get_prime();
//	forarr(prime, 0, 13);
//	forarr(sum, 0, 7);
	int Q, lef, rig;
	scanf("%d ", &Q);
	while(Q--) {
		scanf("%d %d ", &lef, &rig);
		printf("%d\n", sum[rig]-sum[lef-1]);
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

