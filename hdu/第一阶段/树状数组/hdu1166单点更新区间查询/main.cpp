//#include <iostream>
//#include <algorithm>
//#define MAXN 50005
//using namespace std;

//int n, t, arr[MAXN], c[MAXN];

//int lowbit(int x) { return x & (-x); }

//void add(int i, int value) {
//	while(i<=n) {
//		c[i] += value;
//		i += lowbit(i);
//	}
//}

//int sum(int i) {
//	int sum = 0;
//	while(i > 0) {
//		sum += c[i];
//		i -= lowbit(i);
//	}
//	return sum;
//}

//int main()
//{
//	char str[12];
//	freopen("test", "r", stdin);
//	scanf("%d", &t);
//	for(int ii=1; ii<=t; ii++) {
//		printf("Case %d:\n", ii);
//		scanf("%d", &n);
//		for(int i=1; i<=n; i++) {
//			scanf("%d", arr+i);
//			add(i, arr[i]);
//		}
//		int lef, rig, idx, val;
//		while(EOF!=scanf("%s", str) && str[0]!='E') {
//			if(str[0] == 'Q') { //Query
//				scanf("%d %d", &lef, &rig);
//				printf("%d\n", sum(rig)-sum(lef-1));
//			} else if(str[0] == 'A') { //Add
//				scanf("%d %d", &idx, &val);
//				add(idx, val); 
//			} else if(str[0] == 'S') {
//				scanf("%d %d", &idx, &val);
//				add(idx, -val); 
//			}
//		}
//	}
//	return 0;
//}



#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 50005
using namespace std;

int n, t, arr[MAXN], c[MAXN];

int lowbit(int x) { return x & (-x); }

void add(int i, int val) {
	while(i<=n) {
		c[i] += val;
		i += lowbit(i);
	}
}

int sum(int i) {
	int sum = 0;
	while(i) {
		sum += c[i];
		i -= lowbit(i);
	}
	return sum;
}

int main()
{
	char str[12];
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for(int ii=1; ii<=t; ii++) {
		printf("Case %d:\n", ii);
		scanf("%d", &n);
		memset(c, false, sizeof(c));
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			add(i, arr[i]);
		}
		int lef, rig, idx, val;
		while(~scanf("%s", str) && str[0]!='E') {
			if(str[0] == 'Q') {
				scanf("%d %d", &lef, &rig);
				printf("%d\n", sum(rig)-sum(lef-1));
			} else if(str[0] == 'A') {
				scanf("%d %d", &idx, &val);
				add(idx, val);
			} else {
				scanf("%d %d", &idx, &val);
				add(idx, -val);
			}
		}
	}
	return 0;
}

