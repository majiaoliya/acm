#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> G[10];

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	string s = "12345";
	reverse(s.begin(), s.end());
	cout << s << endl;
//	reverse(v.begin(), v.end());
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << ",";
	}
	vector<int>::iterator it = v.begin();
	cout << "it:" << *++it << endl;
	return 0;
}

