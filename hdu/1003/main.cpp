//https://blog.csdn.net/eagle_or_snail/article/details/51290688

#include <iostream>
#include <limits>
using namespace std;

int max_func(int x, int y) { return x > y ? x : y; }

int main(void) {
	
	int i = 0, count = 0;
	cin >> count;
	for(int i=1; i<=count; i++) {

		int n;
		cin >> n;
		int arr[n];
		
		for(int k=0; k<n; k++) {
			cin >> arr[k];
		}

		int start = 0, end = 0, max = arr[0];
		int curL = 0, curR = 0;
		int dp[n];
		dp[0] = max;
		for(int k=1; k<n; k++) {
			if(dp[k-1] >= 0) {
				dp[k] = dp[k-1] + arr[k];
			} else {
				dp[k] = arr[k];
				curL = k;
			}
			if(max < dp[k]) {
				max = dp[k];
				start = curL;
				end = k;
			}
		}

		
/**
		for(int k=1; k<n; k++) {
			temp += arr[k];
			if(temp < 0) {
				temp = arr[k];
				curRight = curLeft = k;
			}
			if(temp > max) {
				max = temp;
				curRight = k;
				start = curLeft;
				end = curRight;
			}
		}
*/

/** 还是超时
		for(int k=0; k<n; k++) {
			int temp = 0;
			int curLeft = k;
			int curRight = k; 
			for(int j=k; j<n; j++) {
				temp += arr[j];
				curRight = j;
				if(temp > max) {
					start = curLeft;
					end = curRight;
					max = temp;
				}
			}
		}
*/
		cout << "Case " << i << ":" << endl;
		cout << max << " " << (start+1) << " " << (end+1) << endl;
		if(i != count) cout << endl;
	}

	return 0;
}

/**  枚举所有子序列 时间复杂度太高 超时了
#include <iostream>
#include <limits>
using namespace std;

int max_func(int x, int y) { return x > y ? x : y; }

int main(void) {
	
	int i = 0, count = 0;
	cin >> count;
	for(int i=1; i<=count; i++) {

		int n;
		cin >> n;
		int arr[n];
		
		for(int k=0; k<n; k++) {
			cin >> arr[k];
		}

		int max = INT8_MIN;
		int start, end;
		for(int k=0; k<n; k++) {
			for(int j=n-1; j>=0; j--) {
				int sub = 0;
				int curLeft = k;
				int curRight = k;
				for(int z=k; z<=j; z++) {
				   sub += arr[z];
				   curRight = z;
				}
 				if(sub > max) {
					max = sub;
					start = curLeft;
					end = curRight;
				}
			}
		}

		cout << max << " " << (start+1) << " " << (end+1) << endl;
		if(i != count) cout << endl;
	}

	return 0;
}

*/
