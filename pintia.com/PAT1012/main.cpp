#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 3000
using namespace std;

int n, m;
struct Student {
	double c, m, e, avg;
	string name;
} stu[MAXN];

int main() {
	freopen("test", "r", stdin);
	for( ; cin >> n >> m; ) {
		for(int i=1; i<=n; i++) {
			cin >> stu[i].name >> stu[i].c >> stu[i].m >> stu[i].e;
			stu[i].avg = (stu[i].c + stu[i].m + stu[i].e) / 3;
		}
	}
	
	return 0;
}
























