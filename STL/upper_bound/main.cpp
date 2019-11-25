#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> G[10];

int main() {
	vector<int> v = {91, 92, 93, 94, 95};
	
	int val = upper_bound(v.begin(), v.end(), 93) - v.begin();
	cout << val << endl;
	return 0;
}

