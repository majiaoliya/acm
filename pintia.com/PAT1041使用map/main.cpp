#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <sstream>
#include <algorithm>
#define MAXN 100005

using namespace std;

struct Node {
	int val, cnt;
} arr[MAXN];

int main()
{
    freopen("test", "r", stdin);
    int n;
    for( ; EOF != scanf("%d", &n); ) {
    	map<int, Node*> mp; //mp映射下标
    	int x, cnt = 0;
    	for(int i=0; i<n; i++) {
    		scanf("%d", &x);
    		Node* n = mp[x];
    		if(n == 0) {
    			mp[x] = arr + cnt;
    			arr[cnt].val = x, arr[cnt].cnt = 1;
    			cnt ++;
    		} else {
    			n->cnt ++;
    		}
    	}
    	int i = 0;
    	for(i=0; i<cnt; i++) {
    		if(arr[i].cnt == 1) {
    			printf("%d\n", arr[i].val);
    			break;
    		}
    	}
    	if(i == cnt) {
    		printf("None\n");
    	}
    }
   	
    return 0;
}


