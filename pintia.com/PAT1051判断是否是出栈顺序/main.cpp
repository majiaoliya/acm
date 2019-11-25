#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <stack>
#include <sstream>
#include <queue>
#include <algorithm>
#define MAXN 100005

using namespace std;

int main()
{
    freopen("test", "r", stdin);
 	
 	int m, n, k;
 	scanf("%d %d %d", &m, &n, &k);
 	for( ; k--; ) {
 		int arr[n], idx = 0, ok = true, cnt = 1;
 		for(int i=0; i<n; i++)
 			scanf("%d", arr+i);
 		stack<int> s1, s2;
 		while(true) {
 			if(cnt > n) break;
 			s1.push(cnt++);
 			if(s1.size() > m) { ok = false; break; }
 			while(!s1.empty() && s1.top()==arr[idx]) {
 				s2.push(s1.top());
 				s1.pop();
 				idx++;
 			}
 		}
 		if(s1.empty() && ok) {
 			printf("YES\n");
 		} else {
 			printf("NO\n");
 		}
 	}
 	  
    return 0;
}


