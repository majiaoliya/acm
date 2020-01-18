#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)2e6)
#include <map>
#include <queue>
#include <unordered_set>
#define ll long long int

using namespace std;

int m;

bool cmp(vector<int>& va, vector<int>& vb) {
	return va[0] - va[1] < vb[0] - vb[1];
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);
		int sum = 0;
		for(int i=0; i<(int)(v.size()>>1); i++) sum += v[i][0];
		for(int i=(int)(v.size()>>1); i<((int)v.size()); i++)
		   	sum += v[i][1];
		return sum;
    }
};

#ifdef debug
int main() {
	vector<vector<int> > vec = {
		{10,20},
		{30,200},
		{400,50},
		{130,20}
	};
	int K = 2;
	Solution solu; 
	cout << solu.twoCitySchedCost(vec) << endl;




	return 0;
}
#endif 


