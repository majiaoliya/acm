#define ll long long int
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> fraction(vector<int>& arr) {
        ll n = arr.size();
		if(n == 1) return {arr[0], 1};
		for(int i=0; i<n; i++)
			cout << arr[i] << endl;
		int fz = 1, fm = arr[n-1];
		for(int i=n-2; i>=0; i--) {
			printf("%d %d %d lcm:%d\n", fz, fm, arr[i], lcm(fz,fm));
			if(arr[i] != 0) {
				int tmp = lcm(arr[i], fm);
				int az = arr[i] * tmp;
				int bz = fz * (tmp/fm);
				fz = az + bz;
				fm = tmp;
			}
			if(i) swap(fz, fm);
		}
		return {fz/__gcd(fz, fm), fm/__gcd(fz, fm)};
	}

	int lcm(int x, int y) {
		if(x < 0 || y < 0) return 0;
		return (x*y/__gcd(x, y));
	}
};

#define debug
#ifdef debug
int main(void) {
//	vector<int> arr = {3, 2, 0, (int)pow(2,31)-1};
	vector<int> arr = {(int)pow(2,31)-1, (int)pow(2,31)-1, (int)pow(2,31)-1, (int)pow(2,31)-1};
//	vector<int> arr = {
//		3, 2, 0, 2
//	};
	Solution s;
	vector<int> ret = s.fraction(arr);
	for(int i=0; i<ret.size(); i++)
		cout << ret[i] << ",";
	return 0;
}
#endif


