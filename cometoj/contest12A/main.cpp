#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long int 
using namespace std;
#define MAXN ((int)5e5+5)

int t, n;
string str[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	cin >> t;
	while(t--) {
		cin >> n;
		bool ok = true;
		for(int i=0; i<n; i++) {
			cin >> str[i];
			for(int k=0; k<i; k++) {
				if(str[i][0]==str[k][0] && str[i][1]==str[k][1]
						&& str[i][2]==str[k][2]) {
					ok = false;
				}
			}
		}
		cout << (ok ? "Yes" : "No") << endl;
	}
	return 0;
}
