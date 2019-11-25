#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define M 9999999
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main(void) {

	int n;
	for( ; cin>>n; ) {
		int arr[n];
		memset(arr, 0, n);
		for(int i=0; i<n; i++) cin >> arr[i];

		vector<int> v; //系统集合
		for(int i=0; i<n; i++) {
			bool add = true;
			sort(v.begin(), v.end()); //排序
			int cur = 0;
			for(int k=0; k<v.size(); k++) { //从集合里找刚好可以拦截的设备
				if(v[k] >= arr[i]) {
					add = false;
					cur = k;
					break;
				}
			}

			if(add) { //找不到刚好可以拦截的设备 加一台
				v.push_back(arr[i]);
			} else { //找到 调整高度
				v[cur] = arr[i];
			}
		}
				
		cout << v.size() << endl;
	}

	return 0;
}
