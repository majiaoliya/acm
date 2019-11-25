#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int max(int x, int y) { return x < y ? x : y; }
int abs(int x) { return x > 0 ? x : -1; }

int main(void) {
	freopen("test", "r", stdin);
	string str;
	for( ; getline(cin, str); ) {
		if(str.empty()) break;
		for(int i=0, lst=0; i<str.length(); i++) {
			if(str[i] == ' ' || i==str.length()-1) {
//				printf("[%c]", str[lst]);
				str[lst] = max(str[lst], str[lst]-abs('a'-'A'));
				lst = i+1;
			}
		}
		cout << str << endl;
	}
	return 0;
}
