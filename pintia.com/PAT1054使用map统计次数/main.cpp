//这题测试点里面没有[出现次数相同的颜色]
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024

using namespace std;

int main()
{
    freopen("test", "r", stdin); 
    int r, c;
    map<int, int> mp;
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++) {
    	for(int k=0; k<c; k++) {
    		int x;
    		scanf("%d", &x);
    		int& rx = mp[x];
    		rx ++;
    		if(rx > (r*c)>>1) { //出现次数超过一半 结果就是他了
    			printf("%d\n", x);
    			return 0;
    		}
    	}
    }
    map<int, int>::iterator it = mp.begin();
    int max_count = 0, rs = 0;
    while(it!=mp.end()) {
    	if(it->second > max_count) {
    		max_count = it->second;
    		rs = it->first;
    	}
    	it ++;
    }
    return 0;
}

