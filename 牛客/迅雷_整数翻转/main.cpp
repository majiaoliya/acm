#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

string str;

int main(void) {
	freopen("test", "r", stdin);
	cin >> str;
	if(str == "0" || str == "-0") {
		printf("0");
		return 0;
	}
	stack<char> stk;
	int m = 0;
	if(str[0] == '-') {
		printf("-");
		m ++;
	}
	bool tag = false;
	for(int i=str.length()-1; i>=m; i--) {
		if(str[i] != '0') tag = true;
		if(tag) printf("%c", str[i]);
	}
	return 0;
}
