#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, c;

//struct Node {
//	string col[6];
//} arr[MAXN];

//int cmp(Node& x, Node& y) {
//	if(x.col[c] == y.col[c])
//		return x.col[1] < y.col[1];
//	return x.col[c] < y.col[c];
//}

struct Stu {
	int xh, cj;
	string name;
} arr[MAXN];

int cmp(Stu& x, Stu& y) {
	if(c == 1) return x.xh < y.xh;
	else if(c == 2) {
		if(x.name == y.name) {
			return x.xh < y.xh;
		}
		return x.name < y.name;
	} else if(c == 3) {
		if(x.cj == y.cj) {
			return x.xh < y.xh;
		}
		return x.cj < y.cj;
	}
}

int main()
{
	freopen("test", "r", stdin);
	cin >> n >> c;
	for(int i=1; i<=n; i++) {
		cin >> arr[i].xh >> arr[i].name >> arr[i].cj;
	}
	sort(arr+1, arr+1+n, cmp);
	for(int i=1; i<=n; i++) {
		printf("%06d %s %d\n", arr[i].xh, arr[i].name.data(), arr[i].cj);
	}
	return 0;
}

