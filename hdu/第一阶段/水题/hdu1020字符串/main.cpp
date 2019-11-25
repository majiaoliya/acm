#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAXN 10005
using namespace std;

int t, len;
string str;

int main(void) {
	freopen("test", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> str;
		len = str.length();
		for(int i=0, cnt; cnt=1, i<len; i++) {
			char c = str[i];
			for(int k=i+1; k<len; k++) {
				if(str[k] != c) break;
				cnt ++;
				i = k;
			}
			if(cnt != 1) cout << cnt;
			cout << c;
		}
		cout << endl;
	}
	return 0;
}





