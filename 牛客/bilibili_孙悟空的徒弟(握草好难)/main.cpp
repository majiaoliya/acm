/** 假算法
#include<time.h>
#include<limits.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 1e6+5;

int n, m, arr[MAXN];

//#define debug

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
#ifdef debug
		map<int, int> mp;
#endif
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
#ifdef debug
			int& rx = mp[arr[i]];
			rx ++;
			if(rx >= 2) printf("[%d %d]\n", arr[i], rx);
			if(arr[i] < 0) printf("%d is neg\n", arr[i]);
#endif 
		}

		sort(arr+1, arr+n+1);
		int lef = n - 1, rig = n;
		int k = n - 1; //[lef, rig]代表前 k 大
		
		while(k < m) { m -= k; k --, rig --; } lef = rig - m; //		printf("lef:%d rig:%d = %d\n", lef, rig, arr[lef]*arr[rig]); printf("%d\n", arr[lef]*arr[rig]); for(int i=n; i>=1; i--) for(int k=i-1; k>=1; k--) printf("%d * %d = %d\n", arr[i], arr[k], arr[i]*arr[k]); 
	}

	return 0;
}
*/

// 二分答案 : 二分第K大值

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;

int main(){
    freopen("test", "r", stdin);
	LL n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
		scanf("%d", arr+i);
   	sort(v.begin(),v.end());
  	if(m==1){
        LL x = (LL)v[n-1]*v[n-2];
		printf("%d\n", x);
		return 0;
  	}
	ll l = 
}

