#include <iostream>
#include <algorithm>
using namespace std;

void input() {
	int n, beSreach;
	cin >> n >> beSreach;
	int arr[n];
	for(int i=0; i<n; i++) 
	  cin >> arr[i];
	int binSreach(int*, int, int);
	int index = binSreach((int*)arr, n, beSreach);
	cout << "index: " << index << endl;
}

int binSreach(int* arr, int n, int beSreach) {
	int left=0, right=n-1, ret = -1;
	int mid = (left+right)/2;
	while(left < right) {
		mid = (left+right)/2;
		if(beSreach > arr[mid]) {
			left = mid;
		} else if(beSreach < arr[mid]) {
			right = mid;
		} else {
			ret = mid;
			break;
		}
	}

	return ret;
}

int main(void) {
	freopen("测试数据", "r", stdin);
	input();
	return 0;
}
