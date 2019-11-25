//#include <iostream>
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <string.h>
//#include <queue>
//using namespace std;
//#define ll long long int
//#define MAXN ((int)1e5+7)
//int n, m, vis[MAXN];
//
//int main(void) {
//	freopen("test", "r", stdin);
//	while(~scanf("%d %d", &n, &m)) {
//		queue<int> qx, qy;
//		for(int i=0, x; i<m; i++) {
//			scanf("%d", &x);
//			vis[x] = true;
//			qx.push(x);
//		}
//		for(int i=1; i<=n; i++) {
//			if(vis[i] == false) qy.push(i);
//		}
//		for(int i=1; i<=n; i++) {
//			if(!qx.empty() && !qy.empty()) {
//				if(qx.front() < qy.front()) {
//					printf("%d\n", qx.front());
//					qx.pop();
//				} else {
//					printf("%d\n", qy.front());
//					qy.pop();
//				}
//			} else if(!qx.empty()) {
//				printf("%d\n", qx.front());
//				qx.pop();
//			} else if(!qy.empty()) {
//				printf("%d\n", qy.front());
//				qy.pop();
//			}
//		}
//	}
//	return 0;
//}





#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
#define ll long long int
#define MAXN ((int)1e5+7)
int n, m, vis[MAXN];

int main(void) {
	while(~scanf("%d %d", &n, &m)) {
		queue<int> qx, qy;
		for(int i=0, x; i<m; i++) {
			scanf("%d", &x);
			vis[x] = true;
			qx.push(x);
		}
		for(int i=1; i<=n; i++) {
			if(vis[i] == false) qy.push(i);
		}
		for(int i=1; i<=n; i++) {
			if(!qx.empty() && !qy.empty()) {
				if(qx.front() < qy.front()) {
					printf("%d\n", qx.front());
					qx.pop();
				} else {
					printf("%d\n", qy.front());
					qy.pop();
				}
			} else if(!qx.empty()) {
				printf("%d\n", qx.front());
				qx.pop();
			} else if(!qy.empty()) {
				printf("%d\n", qy.front());
				qy.pop();
			}
		}
	}
	return 0;
}

