/**
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 1006
using namespace std;

int t, n, m, arr[MAXN];
vector<string> input, output;

bool check() {
	bool ret = true;
	for(int i=1; i<input.size() && ret; i++) {
		for(int k=1; k<input[i].size() && ret; k++) {
			if(input[i][k] != output[i][arr[k]]) ret = false;
		}
	}
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		input.clear(), output.clear();
		for(int i=1; i<n; i++) {
			string a, b;
			cin >> a >> b;
			input.push_back(a), output.push_back(b);
		}
		bool ok = false;
		for(int i=1; i<52; i++)
			arr[i] = i;
		do {
			if(check()) { ok = true; break; }			
		} while(next_permutation(arr, arr+m));
		if(ok) {
			for(int i=1; i<m; i++) {
				if(i) printf(" ");
				printf("%d", arr[i]+2);
			}
			printf("\n");
		} else {
			printf("0\n");
		}
	}
	return 1;
}
*/



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 106
using namespace std;

int t, n, m, arr[MAXN];
vector<string> input, output;
int pn[MAXN], mtx[MAXN][MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		input.clear(), output.clear();
		for(int i=0; i<n; i++) {
			string a, b;
			cin >> a >> b;
			input.push_back(a), output.push_back(b);
		}
		memset(pn, false, sizeof(pn));
		memset(mtx, false, sizeof(mtx));
		bool ok = false;
		for(int i=0; i<n; i++) {
			for(int k=0; k<m; k++) {
				for(int z=0; z<m; z++) {
//					printf("i:%d k:%d %c %c\n", i, k, input[i][k], output[i][z]);
					if(input[i][k] == output[i][z]) mtx[pn[k]++][i] = z;
				}
			}
		}
		for(int i=0; i<m; i++) {
			for(int k=0; k<m; k++) {
				printf("%d ", mtx[i][k]+1);
			}
			printf("\n");
		}
		printf("\n");
		/**
		for(int i=0; i<m; i++) {
			printf("%d: ", i);
			for(int k=0; k<mtx[i].size(); k++) {
				printf("%d ", mtx[i][k]);
			}
			printf("\n");
		}
		*/
		printf("\n");
	}
	return 1;
}

