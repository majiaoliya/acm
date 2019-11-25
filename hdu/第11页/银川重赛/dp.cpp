#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 10005
using namespace std;

int n, q, arr[MAXN];

int query(int L, int R) {
	int sum = 0;
	for(int i=L; i<=R; i++) sum += arr[i];
	return sum;
}

int main(void) {
	freopen("test", "r", stdin);
	printf("%d %d %d\n", 9^0, 9|0, 9^0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", arr+i);
	scanf("%d", &q);
	int cmd;
	while(q--) {
		scanf("%d", &cmd);
		int L, R, x;
		switch(cmd) {
			case 1:
				scanf("%d %d", &L, &R);
				printf("%d\n", query(L, R));
				break;
			case 2:
				scanf("%d %d %d", &L, &R, &x);
				for(int i=L; i<=R; i++)
					arr[i] ^= x;
				break;
			case 3:
				scanf("%d %d %d", &L, &R, &x);
				for(int i=L; i<=R; i++)
					arr[i] |= x;
				break;
			case 4:
				scanf("%d %d %d", &L, &R, &x);
				for(int i=L; i<=R; i++)
					arr[i] &= x;
				break;
		}
	}
	return 0;
}
