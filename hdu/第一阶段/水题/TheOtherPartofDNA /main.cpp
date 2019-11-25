#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	string str;
	int t;
	for(cin >> t; t--; ) {
		cin>>str;
		for(int i=0; i<str.length(); i++)
			if(str[i] == 'A') str[i] = 'T';
			else if(str[i] == 'T') str[i] = 'A';
			else if(str[i] == 'C') str[i] = 'G';
			else if(str[i] == 'G') str[i] = 'C';
		cout << str << endl;
	}
	return 0;
}
