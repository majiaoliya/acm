#include <map>
#include <vector>
#include <iostream>
#include <stdio.h>
#define ll long long int

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
		if(arr.size() < 2) return false;
		map<int, int> mp;
		int m = min(k, (int)arr.size());
    	for(int i=0; i<m; i++) {
			int& rx = mp[arr[i]];
			if(rx) return true;
			rx ++;	
		}
		for(int i=m, lef=0; i<(int)arr.size(); i++, lef++) {
			int& rx = mp[arr[i]];
			int& ry = mp[arr[lef]];
			if(rx > 0) return true;
			rx ++;
			if(ry > 0) ry --;
		}
		return false;
	}
};
#define debug
#ifdef debug
int main(void) {
	vector<int> arr = {1,2,3,1};
	Solution s;
	cout << s.containsNearbyDuplicate(arr, 3) << endl; //true
	arr = {1,0,1,1};
	cout << s.containsNearbyDuplicate(arr, 1) << endl; //true
	return 0;
}
#endif
