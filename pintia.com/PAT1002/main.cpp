// 17分 ?? why ??
//#include <iostream>
//#include <stack>
//#include <set>
//#include <map>

//using namespace std;

//int main() {
//	freopen("test", "r", stdin);
//	
//	int len1, len2;
//	while(EOF != scanf("%d", &len1)) {
//		map<int, double, greater<int>> mp;
//		for(int i=1; i<=len1; i++) {
//			int mi;
//			double xishu;
//			scanf("%d %lf", &mi, &xishu);
//			mp[mi] = xishu;
//		}
//		scanf("%d", &len2);
//		for(int i=1; i<=len2; i++) {
//			int mi;
//			double xishu;
//			scanf("%d %lf", &mi, &xishu);
//			mp[mi] += xishu;
//		}
//		printf("%d", mp.size());
//		for(map<int,double>::iterator it=mp.begin(); it!=mp.end(); it++) {
//			if(it->second != 0.0)
//				printf(" %d %.1lf", it->first, it->second);
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}








#include <iostream>
#include <stack>
#include <set>
#include <string.h>
#include <map>
#define MAXN 1010
using namespace std;

float xishu[MAXN]; // 系数

int main() {
	freopen("test", "r", stdin);
	int n;
	for( ; EOF != scanf("%d", &n); ) {
		memset(xishu, false, sizeof(xishu));
		for( ; n--; ) {
			int idx;
			float val;
			scanf("%d %f", &idx, &val);
			xishu[idx] = val;
		}
		scanf("%d", &n);
		for( ; n--; ) {
			int idx;
			float val;
			scanf("%d %f", &idx, &val);
			xishu[idx] += val;
		}
		int count = 0;
		for(int i=0; i<MAXN; i++)
			if(xishu[i] != 0) count++;
		printf("%d", count);
		for(int i=MAXN; i>=0; i--) {
			if(xishu[i] != 0.0)
				printf(" %d %.1f", i, xishu[i]);
		}
		printf("\n");
	}
	
	return 0;
}
