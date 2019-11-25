//
//#define ll long long int
//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//
//	bool check(ll mid, vector<int>&nums, int m) {
//		ll sum = 0;
//		int mm = 0;
//		for(size_t i=0; i<nums.size(); i++) {
//			if(sum+nums[i] > mid) {
//				sum = nums[i];
//				if(nums[i] > mid) return false;
//				mm ++;
//			} else {
//				sum += nums[i];
//			}
//		}
//		return mm < m;
//	}
//
//	int splitArray(vector<int>& nums, int m) {
//    	ll L = 0, R = 1, mid, ret = 0;
//		for(size_t i=0; i<nums.size(); i++) R += nums[i];
//		while(L < R) {
//			mid = (L + R) >> 1;
////			cout << "mid : " << mid << endl;
//			if(check(mid, nums, m)) ret = mid, R = mid;
//			else L = mid+1;
//		}
//		return ret;
//	}
//};
//
//int main(void) {
//	vector<int> v = { 7, 2, 5, 10, 8 };
//	int m = 2;
//	Solution s;
//	cout << s.splitArray(v, m) << endl;
//	return 0;
//}




#define ll long long int
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
    	ll L = 0, R = 1, mid, ret = 0, sum, mm;
		for(int i=0; i<nums.size(); i++) R += nums[i];
		while(L < R) {
			mid = (L + R) >> 1;
			bool ok = false;
			sum = mm = 0;
			for(int i=0; i<nums.size(); i++) {
				if(sum + nums[i] > mid) {
					sum = nums[i];
					if(nums[i] > mid) goto b;
					mm ++;
				} else sum += nums[i];
			}
			ok = mm < m;
			b:
			if(ok) ret = mid, R = mid;
			else L = mid+1;
		}
		return ret;
	}
};

int main(void) {
	vector<int> v = { 7, 2, 5, 10, 8 };
	int m = 2;
	Solution s;
	cout << s.splitArray(v, m) << endl;
	return 0;
}

