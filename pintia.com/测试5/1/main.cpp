#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 16
using namespace std;

char mtx[MAXN][MAXN];
int n;

void dsp() {
	for(int i=1; i<=2*n; i++) {
		for(int k=1; k<=2*n; k++) {
			if(k!=1) printf(" ");
			printf("%c", mtx[i][k]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	for(int i=1; i<=2*n; i++) {
		for(int k=1; k<=2*n; k++) {
			cin >> mtx[i][k];
		}
	}
	int t, x1, y1, x2, y2, wa_cnt = 0, cnt = 0;
	cin >> t;
	for( ; t--; ) {
		cin >> x1 >> y1 >> x2 >> y2;
		if(mtx[x1][y1] == mtx[x2][y2] && mtx[x1][y1]!='*') {
			mtx[x1][y1] = mtx[x2][y2] = '*';
			cnt += 2;
			if(cnt == 2*n*2*n) {
				printf("Congratulations!\n");
				return 0;
			} 
			dsp();
		} else {
			printf("Uh-oh\n");
			wa_cnt ++;
			if(wa_cnt == 3) {
				printf("Game Over\n");
				return 0;
			}
		}
	}
	
	return 0;
}

