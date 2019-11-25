#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#define debug
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& v, int a, int b) {
		int lef = min(a, b), rig = max(a, b), lsum = 0, rsum = 0;
		for(int i=lef; i<rig; i++) lsum += v[i];
		for(int i=rig; i<v.size(); i++) rsum += v[i];
		for(int i=0; i<lef; i++) rsum += v[i];
//		cout << lsum << " " << rsum << endl;
		return min(lsum, rsum);
    }
};

#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	vector<int> v = {1,2,3,4};
	int a = 0, b = 1;
	Solution s;
	cout << s.distanceBetweenBusStops(v, a, b) << endl;
	return 0;
}
#endif
