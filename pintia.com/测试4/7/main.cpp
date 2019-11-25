#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <set>
#include <algorithm>
#define MAXN 10005
using namespace std;

int n;

struct Node {
	string str;
	int idx;
} arr[MAXN];

int cmp(Node& x, Node& y) {
	if(x.str.length() == y.str.length())
		return x.idx < y.idx;
	return x.str.length() < y.str.length();
}

int main()
{
	freopen("test", "r", stdin);
	int cnt = 0;	
	for(int i=0; ; i++) {
		cin >> arr[i].str;
		if(arr[i].str == "#") break;
		arr[i].idx = i;
		cnt ++;
	}
	sort(arr, arr+cnt, cmp);
	for(int i=0; i<cnt; i++) {
		printf("%s ", arr[i].str.data());
	}
	return 0;
}

