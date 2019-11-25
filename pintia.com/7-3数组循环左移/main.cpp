#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024
using namespace std;

int arr[MAXN];

int main() {
	freopen("test", "r", stdin);
	
	int n, m;
	scanf("%d %d", &n, &m);
	m %= n;
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	int lef = 0, rig = n;
	for(int i=0; i<m; i++) {
		arr[rig] = arr[lef];
		lef ++, rig ++;
	}
	
	for(int i=lef, c=0; i<rig; i++) {
		if(c++) printf(" ");
		printf("%d", arr[i]);
	}
	
	return 0;
}
























