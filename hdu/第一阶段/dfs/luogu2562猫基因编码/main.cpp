#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n;
char buf[MAXN];

string dfs(int lef, int rig) {
	if(lef > rig) return "";
	if(lef == rig)
		return buf[lef] == '0' ? "A" : "B";
	string ret = "";
	bool tag0 = 0, tag1 = 0;
	for(int i=lef; i<=rig; i++)
		if(buf[i]=='0') tag0 = true;
		else if(buf[i]=='1') tag1 = true;
	if(!tag0 && tag1) return "B";
	if(tag0 && !tag1) return "A";
	ret += "C";
	int mid = (rig+lef) >> 1;
	ret += dfs(lef, mid);
	ret += dfs(mid+1, rig);
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%s ", buf+1);
	n = strlen(buf+1);
	string ans = dfs(1, n);
	cout << ans << endl;





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

