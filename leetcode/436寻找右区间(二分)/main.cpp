#define ll long long int
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    vector<int>* pv;
    int idx;
    Node(vector<int>* _pv, int _idx) : pv(_pv), idx(_idx) { }
};

bool cmp(Node& x, Node& y) { return *(x.pv) < *(y.pv); }

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<Node> tmp;
        for(int i=0; i<n; i++) 
            tmp.push_back(Node(&arr[i], i));
        vector<int> ans(n, -1);
        sort(tmp.begin(), tmp.end(), cmp);
        for(int i=0; i<n; i++) {
            int lef = 0, rig = n-1, mid, key = arr[i][1], idx = -1;
			printf("i:%d key:%d \n", i, key);
            while(lef <= rig) {
                mid = (lef + rig) >> 1;
                int midv = tmp[mid].pv->at(0);
                if(midv >= key) idx = mid, rig = mid - 1;
				else lef = mid + 1;
				printf("	mid:%d\t midv:%d\n", mid, midv);
            }
            if(-1 != idx) ans[i] = tmp[idx].idx;
        	printf("	\nidx:%d\n", idx);
		}
        return ans;
    }
};

#define debug
#ifdef debug
int main(void) {
	vector<vector<int> > arr = {
		{3, 4},
		{2, 3},
		{1, 2}
	};
	Solution s;
	vector<int> ans = s.findRightInterval(arr);
	printf("\n");
	for(auto x : ans)
		printf("%d, ", x);
	return 0;
}
#endif
