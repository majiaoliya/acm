#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int mouse[MAXN], mouse2[MAXN], idx[MAXN], n, m, rak[MAXN];

int get_maxid(int arr[], int lef, int m, int r) {
	int max_w = arr[lef], max_id = lef;
	for(int i=lef+1; i<lef+m; i++) {
		if(max_w < arr[i]) {
			max_w = arr[i];
			max_id = i;
		}
	}
	for()
	return max_id;
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", mouse+i);
	for(int i=0; i<n; i++) {
		scanf("%d", idx+i);
		mouse2[i] = mouse[idx[i]];
		cout << mouse2[i] << ",";
	}
	cout << endl;
	for(int i=0; i<n; i+=m) {
		if(n-i<m) {
			cout << get_maxid(mouse2, i, n-i) << ",";
		} else {
			cout << get_maxid(mouse2, i, m) << ",";
		}
	}
	return 0;
}


