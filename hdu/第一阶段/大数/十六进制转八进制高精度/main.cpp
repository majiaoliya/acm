#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <time.h>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

//十六进制转8进制高精度
//先转成2进制再映射成8进制

int n, m;
string str16, str2, str8;
string mp[256];
map<string, int> mp2;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	mp[(int)'0'] = "0000";
	mp[(int)'1'] = "0001";
	mp[(int)'2'] = "0010";
	mp[(int)'3'] = "0011";
	mp[(int)'4'] = "0100";
	mp[(int)'5'] = "0101";
	mp[(int)'6'] = "0110";
	mp[(int)'7'] = "0111";
	mp[(int)'8'] = "1000";
	mp[(int)'9'] = "1001";
	mp[(int)'A'] = "1010";
	mp[(int)'B'] = "1011";
	mp[(int)'C'] = "1100";
	mp[(int)'D'] = "1101";
	mp[(int)'E'] = "1110";
	mp[(int)'F'] = "1111";

	mp2["000"] = 0;
	mp2["001"] = 1;
	mp2["010"] = 2;
	mp2["011"] = 3;
	mp2["100"] = 4;
	mp2["101"] = 5;
	mp2["110"] = 6;
	mp2["111"] = 7;

	cin >> str16;	
	for(auto ch : str16) 
		str2 += mp[(int)ch];
	int i = str2.length() - 1;
	stack<int> stk;
	for( ; i>=0; ) {
		string tmp = "000";
		for(int k=2; k>=0 && i>=0; k--, i--)
			tmp[k] = str2[i];
//		cout << mp2[tmp] << endl;
		stk.push(mp2[tmp]);
	}
	while(stk.size()>1 && stk.top()==0) stk.pop();
	while(!stk.empty()) {
		printf("%d", stk.top());
		stk.pop();
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




