#include <iostream>

using namespace std;

int main() {
	freopen("test", "r", stdin);
	int n;
	cin >> n;
	string str;
	for( ; n--; ) {
		cin >> str;
		int lef = 0, rig = 0;
		for(int i=0; i<3; i++)
			lef += str[i];
		for(int i=3; i<str.length(); i++)
			rig += str[i];
		cout << (lef==rig ? "You are lucky!":"Wish you good luck.") << endl;
	}
	return 0;
}
