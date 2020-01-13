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
#define MAXN ((int)5e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m;
string s1, s2;

string read_str(string& s, int& lef, int rig) {
	string tmp;
	while(lef<=rig && s[lef] != ':') tmp += s[lef ++];
	lef ++;
	return tmp;
}

int read_int(string& s, int& lef, int rig) {
	int ret = 0;
	while(lef<=rig && s[lef]>='0' && s[lef]<='9') 
		ret = ret * 10 + (s[lef] - '0'), lef ++;
	lef ++;
	return ret;
}

struct CmpKey {
	bool operator() (const string& sa, const string& sb) const {
		string ta = sa, tb = sb;
		if(ta.front()=='"' && tb.front()=='"') return ta < tb;
		if(ta.front()!='"' && tb.front()=='"') 
			return ta[0]-'0' < tb[1];
		if(ta.front()=='"' && tb.front()!='"') 
			return ta[1] < tb[0]-'0';
		return ta < tb;
	}
} ;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	/**
	string ts = "100:77,30:77";
	int a = 0, b = ts.length()-1;
	cout << (read_str(ts, a, b));
	cout << read_int(ts, a, b);
	cout << (read_str(ts, a, b));
	cout << read_int(ts, a, b);
	*/
	map<string, int, CmpKey> mp;
	getline(cin, s1); getline(cin, s2);
	for(auto x : s1) if(x == ':') n ++;
	for(auto x : s2) if(x == ':') m ++;
	int lef = 1, rig = s1.length() - 1;
	while(n --) {
		string str = read_str(s1, lef, rig);
		if(s1[lef] == ',' || s1[lef] == ':')lef ++;
		int cnt = read_int(s1, lef, rig);
		mp[str] += cnt;
	}
	lef = 1, rig = s2.length() - 1;
	while(m --) {
		string str = read_str(s2, lef, rig);
		if(s2[lef] == ',' || s2[lef] == ':')lef ++;
		int cnt = read_int(s2, lef, rig);
		mp[str] += cnt;
	}
	int caset = 0;
	cout << "{";
	for(auto x : mp) {
		cout << (caset ? "," : "");
		cout << x.first << ":" << x.second;
		caset ++;
	}
	cout << "}";

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


