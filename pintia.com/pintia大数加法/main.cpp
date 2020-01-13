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

string str, a, b, bina, binb;
int n, m, mp[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> str >> a >> b;
	m = str.length();
	for(int i=0; i<(int)str.length(); i++) mp[(int)str[i]] = i;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0, flag = false;
	vector<int> ans;
	for( ; i<(int)a.length() && i<(int)b.length(); i++) {
		int ta = mp[(int)a[i]], tb = mp[(int)b[i]];
		int tsum = ta + tb + flag;
		flag = false;
		if(tsum >= m) tsum -= m, flag = true;
		ans.push_back(tsum);
	}
	for( ; i<(int)a.length(); i++) {
		int tsum = mp[(int)a[i]] + flag;
		flag = false;
		if(tsum >= m) tsum -= m, flag = true;
		ans.push_back(tsum);
	}
	for( ; i<(int)b.length(); i++) {
		int tsum = mp[(int)b[i]] + flag;
		flag = false;
		if(tsum >= m) tsum -= m, flag = true;
		ans.push_back(tsum);
	}
	if(flag) ans.push_back(flag);
#ifdef debug
	forvec(ans);
#endif
	for(int i=ans.size()-1; i>=0; i--)
		printf("%c", str[ans[i]]);
	printf("\n");
#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


