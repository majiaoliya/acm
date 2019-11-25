#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 10086
using namespace std;

int prime[MAXN], vis[MAXN], pn = 0;

void get_prime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<=MAXN-1; i++) {	
		if(vis[i]) continue;
		prime[pn++] = i;
		for(int k=2; k*i<=MAXN-1; k++) {
			vis[k*i] = true;
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	get_prime();
	for(int i=0; i<pn; i++)
		printf("%d,", prime[i]);
	cout << endl;
	int n, cnt=0, lst;
	scanf("%d", &n);
	for(int i=0; i<pn; i++) {
		if(prime[i] > n) break;
		if(i==0) lst = prime[i];
		else {
			if(prime[i] - lst == 2) {
				cnt ++;
			}
			lst = prime[i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}

