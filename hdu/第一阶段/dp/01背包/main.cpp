
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 5005
using namespace std;

int w[] = {0, 2, 3, 4, 5, 9};
int v[] = {0, 3, 4, 5, 8, 10};
int dp[6][21];

int max(int x, int y) { return x > y ? x : y; }

int main()
{
	for(int i=1; i<6; i++) {
		for(int cap=1; cap<21; cap++) {
			if(w[i] > cap) {
				dp[i][cap] = dp[i-1][cap];
			} else {
				int v1 = dp[i-1][cap-w[i]] + v[i];
				int v2 = dp[i-1][cap];
				dp[i][cap] = max(v1, v2);
			}
		}
	}
	printf("%d\n", dp[5][20]);
	for(int i=0; i<6; i++) {
		for(int cap=0; cap<=20; cap++) {
			printf("%d ", dp[i][cap]);
		}
		printf("\n");
	}
	
	return 0;
}



