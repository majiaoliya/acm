// 尺取法
#include <iostream>
#include <map>
#include <set>
using namespace std;

//找最小的连续的区间[l,r], 要求[l,r]包含所有出现过数字

const int MAXN = 1e7+7;
int n, m, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n) ) {
		set<int> seta;
		map<int, int> mp;
		for(int i=0; i<n; i++) {
			scanf("%d", arr+i);
			seta.insert(arr[i]);
		}
		int size = seta.size();
		int s = 0, t = 0, num = 0, res = n+3;
		while(true) {
			while(num<size && t<n) {
				int& rx = mp[arr[t]];
				if(rx == 0) num ++;
				rx ++;
				t ++;
			}
			if(num < size) break ;
			res = min(res, t-s);
			int& rx = mp[arr[s]];
			rx --;
			if(rx == 0) num --;
			s ++;
		}
		printf("%d\n", res > n ? 0 : res);
	}
	return 0;
}


