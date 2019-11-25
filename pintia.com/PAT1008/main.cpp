#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	int n;
	scanf("%d", &n);
	int cur_level = 0, sum = 0;
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		if(cur_level > x) { //down
			sum += (cur_level - x) * 4;
		} else if(cur_level < x) { //up
			sum += (x - cur_level) * 6;
		}
		sum += 5;
		cur_level = x;
	}
	printf("%d", sum);
	
	return 0;
}
























