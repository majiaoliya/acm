#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
		int n = A.size();
 		int arr[n+3], lef[n+3], rig[n+3];
		memset(lef, false, sizeof(lef));
		memset(rig, false, sizeof(rig));
		memset(arr, false, sizeof(arr));
    	for(int i=1; i<=n; i++) {
			
		}
	}
};

#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	return 0;
}
#endif
