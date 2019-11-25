#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool is_ss(int x) {
	if(x == 1 || x == 0) return false;
	int t = sqrt(x);
	int ret = true;
	for(int i=2; i<=t; i++) {
		if(x%i == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	
	int n, m;
	for( ; EOF != scanf("%d %d", &n, &m), (m+n); ) {
		bool tag = true;
		for(int i=n; i<=m; i++) {
			int rs = i*i+i+41;
			if(!is_ss(rs)) {
				tag = false;
				break;
			}
		}
		printf("%s\n", tag ? "OK" : "Sorry");
	}
	
	return 0;
}
