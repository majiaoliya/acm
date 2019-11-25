#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n, arr[MAXN], half[MAXN];

bool check() {
	bool ret = true;
	if(arr[0] & 1) arr[0]++;
	for(int i=1; i<n; i++) {
		if(arr[i] & 1) arr[i]++;
		if(arr[i] != arr[0]) 
			ret = false;
	}
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; cin>>n && n; ) {
		for(int i=0; i<n; i++)
			cin >> arr[i];
		int cnt = 0, rig, lef;
		while(!check()) {
			cnt ++;
			for(int i=0; i<n; i++)
				half[i] = arr[i]>>1;
			for(int i=0; i<n; i++) {
				rig = (i+1) % n;
				lef = i==0 ? n-1 : i-1;
				arr[i] += half[lef] - half[i];
			}
//			for(int i=0; i<n; i++)
//				cout << arr[i] << " ";
//			cout << endl;
//			char c; 
//			cin >> c;
		}
		printf("%d %d\n", cnt, arr[1]);
	}
	return 0;
}
