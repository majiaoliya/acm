#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int sum[MAXN];

/**
 * 给定一个数组和多个查询 每次查询子数组的异或和
 * 只查不改
 * 异或==不进位加法 => 可以用前缀和或线段树
 */

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
		for(int i=0; i<(int)arr.size(); i++)
			sum[i+1] = sum[i] ^ arr[i];
		vector<int> ans;
		for(auto it : q) {
			int L = it[0], R = it[1];
			ans.push_back(sum[L] ^ sum[R+1]);
		}
		return ans;
    }
};

#ifdef debug
int main() {
#endif
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	vector<int> vec = { 1,3,4,8 };
	vector<vector<int> > q = {
		{0,1},{1,2},{0,3},{3,3}
	};
	Solution s;
	auto ans = s.xorQueries(vec, q);
	for(auto it : ans)
		printf("%d ", it);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
#ifdef debug
	return 0;
}
#endif

