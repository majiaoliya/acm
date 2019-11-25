#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long int 
using namespace std;
#define MAXN ((int)1e6+5)

int t, n, m, r, c;
string stra[MAXN], strb[MAXN], tmp[MAXN];
int main(void) {
	freopen("test", "r", stdin);
	cin >> t;
	while(t--) {
		cin >> n >> m >> r >> c;
		int cnta = 0, cntb = 0, flag = 1;
		int flaga = 1, flagb = 1;
		for(int i=0; i<n; i++) {
			cin >> stra[i];
			tmp[i] = stra[i];
			for(int k=0; k<m; k++) {
				if(stra[i][k] == '1') cnta ++;
			}
		}
		for(int i=0; i<n; i++) {
			cin >> strb[i];
			for(int k=0; k<m; k++) {
				if(strb[i][k] == '1') cntb ++;
				if(stra[i][k] != strb[i][k]) flag = false;
			}
		}

		if(n==1 && ((cnta==n*m&&cntb==0) || (cnta==0&&cntb==n*m))) {
			cout << "Yes" << endl;
			continue;
		}

		if(flag) { 
			cout << "Yes" << endl;
			continue ;
		}
		if(cnta) cnta %= 2;
	   	if(cntb) cntb %= 2;
		if(cnta == cntb && r==1 && c==1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

