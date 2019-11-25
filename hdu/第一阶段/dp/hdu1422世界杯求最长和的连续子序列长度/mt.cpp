#include <bits/stdc++.h>
using namespace std;

#define random(x) (rand()%x)

int main(void) {
	freopen("test", "w", stdout);
	srand(time(0));
	int t = 10;
	for(int i=1; i<=t; i++) {
		int n = random(20);
		cout << n << endl;
		for(int k=1; k<=n; k++) {
			int w = random(n), v = random(n+5);
			cout << w << " " << v << " ";
		}
		cout << endl;
	}
	return 0;
}
