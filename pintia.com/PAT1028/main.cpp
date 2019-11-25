#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAXN 10086
using namespace std;

int n, cmp_col;

struct Record {
	string cols[4];
} arr[MAXN];

int cmp(Record& x, Record& y) {
	if(x.cols[cmp_col] == y.cols[cmp_col])
		return x.cols[1] < y.cols[1];
	return x.cols[cmp_col] < y.cols[cmp_col];
}

int main() {
	freopen("test", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> cmp_col;
	for(int i=1; i<=n; i++) 
		cin >> arr[i].cols[1] >> arr[i].cols[2] >> arr[i].cols[3];
	sort(arr+1, arr+1+n, cmp);
	
	for(int i=1; i<=n; i++) {
		cout << arr[i].cols[1] << " " << 
		 arr[i].cols[2] << " " << arr[i].cols[3] << endl;
	}
	return 0;
}
























