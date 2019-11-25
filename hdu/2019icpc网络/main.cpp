/**
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 10005
#define ll long long int

int t, n, m;

char s1[MAXN], s2[MAXN], s3[MAXN];
int cases;
int hs[512];

int main() {
    freopen("test", "r", stdin);
	scanf("%d\n", &t);
	while(t--) {
		printf("Case #%d: ", ++cases);
		scanf("%d %d\n", &n, &m);
		scanf("%s\n", s1);
		scanf("%s\n", s2);
		scanf("%s\n", s3);
		int num = s2[0] - s1[0];
		for(int i='A'; i<='Z'; i++)
			hs[i] = s3
		for(int i=0; i<m; i++)
			printf("%c", s3[i]-num < 'A' ? s3[i]-num+26 : s3[i]-num);
		printf("\n");
	}	
    return 0;
}
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 100005
#define ll long long int

int t, n, m;

struct Node {
	int hp, atk, cnt, b;
} arr[MAXN];

int cmp(Node& a, Node& b) {
	return a.atk*b.hp < b.atk*a.hp;
}

int main() {
    freopen("testH", "r", stdin);
	scanf("%d\n", &t);
	while(t--) {
		scanf("%d", &n);
		int sum = 0;
		for(int i=1; i<=n; i++)
			scanf("%d %d", &arr[i].hp, &arr[i].atk), sum += arr[i].atk, arr[i].cnt = 0, ;
		sort(arr+1, arr+1+n, cmp);
		int ans = 0, gj = 0;
		
		printf("%d\n", ans);
	}
    return 0;
}


