#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 10005
using namespace std;

int n, m;

int main()
{
	freopen("test", "r", stdin);
	string a;
	int n, sum = 0;
	cin >> a >> n;
	string ta = a;
	for(int i=1; i<=n; i++) {
		sum += stoi(a);
		a += ta;
	}
	cout << "s = " << sum << endl;
	return 0;
}

