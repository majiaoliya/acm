#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int 
using namespace std;

int cnt, vis[20];

int main(void) {
	freopen("test", "r", stdin);
	for(int i=1, x; i<=18; i++) {
		scanf("%d", &x);
		if(x == 0) {
			cnt ++;
			continue;
		}
		if(vis[x] == false) {
			vis[x] = true;
			cnt ++;
		} else {
			vis[x] = false;
			cnt --;
		}
	}
	printf("%d", cnt);
	return 0;
}
