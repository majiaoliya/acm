#include <bits/stdc++.h>
#define random(x) (rand()%x)
using namespace std;

int main(void) {
	freopen("test", "w", stdout);

	int t = 1;
	cout << t << endl;
	int n = 13, q = 20; 
	cout << n << " " << q << endl;
	for(int i=1; i<=n; i++)
		cout << random(n) << " ";
	cout << endl;	
	for(int i=1; i<=q; i++) {
		int lef = random(n) + 1, rig = random(n) + 1, k = random(n) + 1;
		cout << min(lef, rig) << " " << max(lef, rig) << " " << k << endl;
	}
	return 0;
}

