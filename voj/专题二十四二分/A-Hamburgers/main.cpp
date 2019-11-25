#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAXN 105
#define ll long long int
using namespace std;

ll cnt[312];

ll b, s, c, len;
ll one_cost[4], hav[4], money;
char str[312];

ll check(ll mid) {
	ll needb = cnt['B']*mid, needs = cnt['S']*mid, needc = cnt['C']*mid;
	ll tmon = money;
//	cout << needb-hav[1] << "\t" << needs-hav[2] << "\t" << needc-hav[3] << endl;
	if(needb-hav[1] > 0) tmon -= (needb-hav[1])*one_cost[1];
	if(needs-hav[2] > 0) tmon -= (needs-hav[2])*one_cost[2];
	if(needc-hav[3] > 0) tmon -= (needc-hav[3])*one_cost[3];
	return tmon;
}

int main(void) {
	freopen("test", "r", stdin);
	cin >> str;
	for(int i=1; i<=3; i++)
		cin >> hav[i];
	for(int i=1; i<=3; i++)
		cin >> one_cost[i];
	len = strlen(str);
	for(int i=0; i<len; i++)
		cnt[str[i]] ++;
	cin >> money;
	ll lef = 0, rig = (ll)10e12+3, mid, rs;
	while(lef<=rig) {
		mid = (lef+rig) >> 1;
		ll tag = check(mid);
		if(tag >= 0) { //够做mid个
			rs = mid;
			lef = mid+1;
		} else if(tag < 0) { //不够做mid个
			rig = mid-1;
		}
	}
	cout << rs << endl;
	return 0;
}
