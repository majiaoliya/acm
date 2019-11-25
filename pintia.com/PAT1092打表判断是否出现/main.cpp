//这题测试点里面没有[出现次数相同的颜色]
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024

using namespace std;

char table1[MAXN], table2[MAXN];
string str1, str2;

int main()
{
    freopen("test", "r", stdin); 
    
    for( ; cin>>str1>>str2; ) {
    	memset(table1, false, sizeof(table1));
    	memset(table2, false, sizeof(table2));
    	int cnt = 0;
    	for(int i=0; i<str1.length(); i++)
    		table1[str1[i]] ++;
    	for(int i=0; i<str2.length(); i++) {
    		if(table1[str2[i]] == 0) {
    			cnt ++;
    		} else {
    			table1[str2[i]] --;
    		}
    	}
    	if(cnt == 0) {
    		printf("Yes %d\n", str1.length()-str2.length());
    	} else {
    		printf("No %d\n", cnt);
    	}
    }
    
    return 0;
}

