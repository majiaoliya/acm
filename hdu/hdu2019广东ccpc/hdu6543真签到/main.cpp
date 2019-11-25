#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int cnt1[130], cnt2[130];

int main(void) {
	freopen("test", "r", stdin);
	ios::sync_with_stdio(false);
	string s1, s2;
	for( ; cin>>s1>>s2; ) {
		if(s1 == s2) {
			cout << "Equal\n";
		} else {
			if(s1.length() != s2.length()) {
				cout << "No\n";
				continue;
			}
			memset(cnt1, false, sizeof(cnt1));
			memset(cnt2, false, sizeof(cnt2));
			for(int i=0, k=0; (i!=s1.length() && k!=s2.length()); ) {
				if(i<s1.length()) 
					cnt1[s1[i]] ++, i++;
				if(k<s2.length())
					cnt2[s2[k]] ++, k++;
			}
			bool ok = true;
			for(int i=0; i<130; i++) {
				if(cnt1[i] != cnt2[i]) {
					ok = false;
					break;
				}
			}
			if(s1[0]!=s2[0] || s1.back()!=s2.back())
				ok = false;
			cout << (ok ? "Yes\n" : "No\n");
		}
	}
	return 0;
}
