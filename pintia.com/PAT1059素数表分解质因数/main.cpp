#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 500000

using namespace std;

int prime[MAXN], pn, n;
bool* vis = new bool[MAXN];

void get_prime(bool* vis) { //线性筛打素数表
	for(int i=2; i<=MAXN; i++) {
		if(!vis[i]) {
			prime[pn++] = i;
		}
		for(int k=0; k<pn&&i*prime[k]<=MAXN; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

int main()
{
    freopen("test", "r", stdin); 
    scanf("%d", &n);
    if(n == 0) { printf("0=0"); return 0; }
    else if(n == 1) { printf("1=1"); return 0; }
    int count = 0;
    get_prime(vis);
    int tn = n;
    map<int, int> mp; // <素数, 出现次数>
    while(tn != 1) { //找第一个可以整除n的素数x, 然后 n /= x 直到 x == n
    	for(int i=0; i<pn; i++) {
    		if(tn%prime[i] == 0) {
    			mp[prime[i]] ++;
    			tn /= prime[i];
    		}
    	}
    }
    map<int, int>::iterator it = mp.begin();
    printf("%d=", n);
    int c = 0;
    while(it != mp.end()) {
    	if(c++) printf("*");
    	if(it->second != 1)
	    	printf("%d^%d", it->first, it->second);
		else 
			printf("%d", it->first);
		it ++;
    }
    
    return 0;
}

