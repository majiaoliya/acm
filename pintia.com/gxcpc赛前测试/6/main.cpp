#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

string big_add(string x, string y) {
	int ix = x.length()-1, iy = y.length()-1;
	int maxi = ix+1 > iy+1 ? ix+1 : iy+1;
	char rs[maxi+1];
	memset(rs, false, sizeof(rs));
	int tmaxi = maxi;
	int tag = 0;
	for( ; ix>=0 && iy>=0; ix--, iy--, maxi--) {
		rs[maxi] += (tag + x[ix]-'0' + y[iy]-'0');
		tag = 0;
		if(rs[maxi] > 9)
			tag = 1, rs[maxi] -= 10;
		rs[maxi] += '0';
	}
	for( ; maxi>=0; maxi--) {
		rs[maxi] += tag;
		if(ix>=0)
			rs[maxi] += x[ix--]-'0';
		if(iy>=0)
			rs[maxi] += y[iy--]-'0';
		rs[maxi] += '0';
	}
	bool ttag = false;
	string rs_str;
	for(int i=0; i<=tmaxi; i++) {
		if(rs[i]!='0' && rs[i]!=0) ttag = true;
		if(ttag) rs_str += rs[i];
	}
	return rs_str;
}

int main() {
	freopen("test", "r", stdin);
	string num;
	cin >> num;
	string dnum = big_add(num, num);
	map<int, char> mp1;
	for(int i=0; i<num.length(); i++) {
		mp1[num[i]] ++;
	}
	map<int, char> mp2;
	for(int i=0; i<dnum.length(); i++) {
		mp2[dnum[i]] ++;
	}
	map<int,char>::iterator it1=mp1.begin();
	map<int,char>::iterator it2=mp2.begin();
	while(it1!=mp1.end() && it2!=mp2.end()) {
		if(it1->first!=it2->first || it1->second!=it2->second) {
			cout << "No\n" << dnum << endl;
			return 0;
		}
		it1++, it2++;
	}
	if(it1==mp1.end() && it2==mp2.end())
		cout << "Yes\n" << dnum << endl;
	else
		cout << "No\n" << dnum << endl;
	return 0;
}

