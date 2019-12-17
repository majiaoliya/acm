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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n;
priority_queue<string, vector<string>, greater<string> > q;

bool check(string& x, string& T) {
	if(x.length() < T.length()) return false;
	for(int i=0; i<x.length() && i<T.length(); i++)
		if(x[i] != T[i]) return false;
	return true;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> n;
	string str;
	for(int i=1; i<=n; i++) {
		cin >> str;
		q.push(str);
	}
	string T;
	cin >> T;
	for( ; !q.empty(); q.pop()) {
		string x = q.top();
		if(check(x, T)) cout << x << endl;
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


