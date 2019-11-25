#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 100086

using namespace std;

int max_size, n;

int table[MAXN], prime[MAXN], pn;
bool vis[MAXN];

void get_prime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXN; i++) {
		if(!vis[i])
			prime[pn++] = i;
		for(int k=0; k<pn && i*prime[k]<MAXN; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

int my_hash(int x) { return x % max_size; }

int main()
{
    freopen("test", "r", stdin); 
    for(int i=0; i<MAXN; i++)
    	table[i] = -1;
    get_prime();
    scanf("%d %d", &max_size, &n);
    if(vis[max_size] == true) { //max_size化成最近的素数
    	for(int i=max_size; i<MAXN; i++)
    		if(vis[i] == false) {
    			max_size = i;
    			break;
    		}
    }
    for(int i=0, c=0; i<n; i++) {
    	int x;
    	scanf("%d", &x);
    	int idx = my_hash(x);
    	if(c++) printf(" ");
    	bool tag = false;
    	for(int k=idx; k<max_size; k++) {
			if(table[k] == -1) {
				printf("%d", k);
				table[k] = k;
				tag = true;
				break;
			}
    	}
    	if(!tag) printf("-");
    }
    
    return 0;
}

