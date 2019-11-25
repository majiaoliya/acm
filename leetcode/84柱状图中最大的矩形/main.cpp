#define ll long long int
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int n;

typedef vector<vector<int> > vvi;

class Solution {
public:
    int n, ans;
    //n^3瞎暴力
	//int largestRectangleArea(vector<int>& arr) {
    //    n = arr.size(), ans = 0;
    //    for(int i=0; i<n; i++) {
    //        for(int k=n-1; k>=i; k--) {
	//			int minx = arr[i];
	//			for(int j=i; j<=k; j++) minx = min(arr[j], minx);
//	//			printf("%d %d = %d*%d = %d\n", i, k, (k-i+1), minx, (k-i+1)*minx);
	//			ans = max(ans, (k-i+1)*minx);
	//		}
    //    }
    //    return ans;
    //}

	//n^2优化瞎暴力
	//int largestRectangleArea(vector<int>& arr) {
    //    n = arr.size(), ans = 0;
    //    for(int i=0; i<n; i++) {
	//		int minx = arr[i];
    //        for(int k=i; k<n; k++) {
	//			minx = min(minx, arr[k]);
	//			ans = max(ans, (k-i+1)*minx);
	//		}
    //    }
    //    return ans;
    //}

	//nlogn无脑分治
	//int bt(vector<int>& arr, int lef, int rig) {
	//	if(lef > rig) return 0;
	//	if(lef == rig) return arr[lef];
	//	int minx = arr[lef], min_id = lef;
	//	for(int i=lef; i<=rig; i++) 
	//		if(arr[i] < minx) {
	//			min_id = i;
	//			minx = arr[i];
	//		}
	//	int lef_ans = bt(arr, lef, min_id-1);
	//	int rig_ans = bt(arr, min_id+1, rig);
	//	return max(minx*(rig-lef+1), max(lef_ans, rig_ans));
	//}

	//int largestRectangleArea(vector<int>& arr) {
	//	ans = 0;
	//	n = arr.size();
	//	ans = bt(arr, 0, n-1);
	//	return ans;
    //}





	//官方题解,牛逼的O(N)栈辅助滑动窗口
	int largestRectangleArea(vector<int>& arr) {
		ans = 0;
		stack<int> stk;
	   	stk.push(-1); //先压一个-1进去	
		for(int i=0; i<n; i++) {
			//遇到一个比栈顶小的数(arr[i]<arr[i-1]), 就用公式算
			while(stk.top()==-1 || arr[stk.top()]<arr[i]) 
				stk.push(i++);
		}
		return ans;
    }

};

#define debug
#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	vector<int> v = {2,1,5,6,2,3};
	Solution s;
	int ans = s.largestRectangleArea(v);
	cout << ans << endl;
	return 0;
}
#endif


