#include <iostream>
using namespace std;
#define MAXN 10005
int t, n, m;
char s1[MAXN], s2[MAXN], s3[MAXN];

int main(void) {
	freopen("testC", "r", stdin);
	scanf("%d\n", &t);
	while(t--) {
		scanf("%d %d\n", &n, &m);
		scanf("%s\n%s\n%s\n", s1, s2, s3);
		char hsh[257];
		char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int num = s2[0] - s1[0];
		num = num < 0 ? 26+num : num;
		for(int i='A', k=0; i<='Z'; k++, i++) {
			hsh[i] = (num + k) > 26 ? (num+k)%26 : num+k;
			printf("%c ", hsh[]);
		}

//		for(int i=0; i<m; i++) 
//			printf("%c", hsh[s3[i]]);
		printf("\n");
	}
	return 0;
}
