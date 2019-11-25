#include <iostream>
#include <string.h>
using namespace std;
string str, text;

int main(void) {
	freopen("test", "r", stdin);
	
	for( ; getline(cin, str) && getline(cin, text); ) {	
		int count = 0, idx = -1;
		for(int i=0; i<=text.length()-str.length(); i++) {
			int k = 0;
			for( ; k<str.length(); ) {
				if(text[i+k]==str[k] || text[i+k]==(str[k]+'a'-'A')) {
					k++;
				} else {
					break;
				}
			}
			if(k == str.length()) {
				if(count == 0) idx = i;
				count ++;
			}
		}
		if(count) {
			printf("%d %d\n", count, idx);
		} else {
			printf("%d\n", -1);
		}
	}
	
	return 0;
}
