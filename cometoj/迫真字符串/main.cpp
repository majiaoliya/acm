#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

string str;
int cnt[6];

int main(void) {
	freopen("test", "r", stdin);
	for( ; cin>>str; ) {
		int rs = 0;
		memset(cnt, false, sizeof(cnt));
		for(int i=0; i<str.length(); i++) {
			int t;
			if(str[i] == '1') {
				cnt[1] ++;
			} else if(str[i] == '4') {
				cnt[4] ++;
			} else if(str[i] == '5') {
				cnt[5] ++;
			}
		}
		rs = min(cnt[1]/3, cnt[4]/2);
		rs = min(cnt[5], rs);
		printf("%d\n", rs);
	}
	return 0;
}





























