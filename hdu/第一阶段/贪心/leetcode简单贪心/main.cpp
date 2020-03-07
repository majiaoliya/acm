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

/**
 * 一共有2n个人,每个人去A地B地花费为[ai,bi]
 * 现在要选n个人去A地, n个人去B地, 求最小花费
 * 直接贪,按(ai-bi)从小到大排序,前n个人去A,后n个人去B
 */
int m;
class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
		priority_queue<int> q;
        for(auto x : arr) q.push(x);
		while(q.size() > 1) {
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			if(a == b) continue ;
			q.push(a - b);
		}
		return q.empty() ? 0 : q.top();
    }
};

#ifdef debug
int main() {
	vector<int> vec = { 2,7,4,1,8,1 };
	Solution solu; 
	cout << solu.lastStoneWeight(vec) << endl;




	return 0;
}
#endif 


