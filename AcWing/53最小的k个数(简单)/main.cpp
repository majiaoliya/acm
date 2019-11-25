#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ret(k);
		priority_queue<int> q;
		int i;
		for(i=0; i<k && i<input.size(); i++) q.push(input[i]);
		for( ; i<input.size(); i++) {
			if(q.top() > input[i]) {
				q.pop();
				q.push(input[i]);
			}
		}
		i = k-1;
		while(!q.empty()) {
			ret[i--] = q.top();
			q.pop();
		}
		return ret;
    }
};

#ifdef debug
int main(void) {
	vector<int> v = { 1,2,3,4,5,6,7,8 };
	Solution s;
	vector<int> rs = s.getLeastNumbers_Solution(v, 4);
	for(int i=0; i<rs.size(); i++)
		printf("%d ", rs[i]);
	return 0;
}
#endif
