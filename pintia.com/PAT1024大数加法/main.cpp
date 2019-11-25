#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAXN 1086

using namespace std;

int step;
string n;

bool check(string str) { //判断是否对称
	int len = str.length();
	for(int i=0; i<len; i++)
		if(str[i] != str[len-i-1]) return false;
	return true;
}

string big_add(string x, string y) { //大数加法
	int tag=0, ix=x.length()-1, iy=y.length()-1;
	int maxi = ix > iy ? ix : iy;
	char rs[(++maxi)+1];
	int tm = maxi;
	memset(rs, false, sizeof(rs));
	for( ; ix>=0 && iy>=0; ix--, iy--, maxi--) {
		rs[maxi] += tag + x[ix]-'0' + y[iy]-'0';
		tag = 0;
		if(rs[maxi] > 9)
			tag = 1, rs[maxi] -= 10;
		rs[maxi] += '0';
	}
	for( ; maxi>=0; maxi--) {
		rs[maxi] += tag;
		if(ix>=0) {
			rs[maxi] += x[ix]-'0';
			ix --;
		}
		if(iy>=0) {
			rs[maxi] += y[iy]-'0';
			iy --;
		}
		tag = 0;
		if(rs[maxi] > 9)
			rs[maxi] -= 10, tag = 1;
		rs[maxi] += '0';
	}
	int ttag = false;
	string trs;
	for(int i=0; i<=tm; i++) {
		if(rs[i] > '0' && rs[i] <= '9') ttag = true;
		if(ttag) trs += rs[i];
	}
	return trs;
}

string my_reverse(string x) { //翻转字符串
	for(int i=0; i<x.length()/2; i++)
		swap(x[i], x[x.length()-1-i]);
	return x;
}

int main()
{
    freopen("test", "r", stdin);
   	cin >> n >> step;
   	int i;
   	for(i=0; i<step; i++) {
   		if(check(n)) {
   			cout << n << "\n" << i << endl;
   			break;
   		} else {
   			n = big_add(n, my_reverse(n));
   		}
   	}
   	if(i==step) cout << n << "\n" << step << endl;
   	
    return 0;
}


