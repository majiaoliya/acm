#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024
using namespace std;

int n;
bool is_ss(int x) {
	if(x==1 || x==0) return false;
	int tx = sqrt(x);
	for(int i=2; i<=tx; i++) 
		if(x%i == 0) return false;
	return true;
}

int main() {
	freopen("test", "r", stdin);
	
	vector<int> rs;
	int m; 
	scanf("%d", &m);
	for(int i=m-1; i>=1 && rs.size()<10; i--) {
		if(is_ss(i)) {
			rs.push_back(i);
			printf("%6d", i);
		}
	}
	return 0;
}
























