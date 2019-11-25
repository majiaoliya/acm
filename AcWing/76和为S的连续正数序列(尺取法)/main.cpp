#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

class Solution {
public:
    vector<vector<int> > findContinuousSequence(int m) {
        int i=1, j=1, sum=0;
		vector<int> v;
		vector<vector<int> > ret;
		while(j<=m) {
			while(sum < m) {
				sum += j;
				j ++;
			}
			if(sum == m) {
				for(int ii=i; ii<j; ii++) v.push_back(ii);
				ret.push_back(v);
				v.clear();
			}
			sum -= i;
			i ++;
		}
		return ret;
    }
};

#ifdef debug
int main(void) {
	Solution s;
	vector<vector<int> > rs = s.findContinuousSequence(15);
	for(auto x : rs) {
		for(auto y : x)
			printf("%d ", y);
		printf("\n");
	}
	return 0;
}
#endif
