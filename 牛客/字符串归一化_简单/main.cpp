#include <iostream>
#include <set>
#include <vector>
#define MAXN 9999999
using namespace std;

int n, m, cnt[256];
char buf[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%s", buf);
	for(char* ptr=buf; *ptr; ptr++) 
		cnt[*ptr] ++;
	for(int i='a'; i<='z'; i++) {
		if(cnt[i] == 0) continue;
		printf("%c%d", i, cnt[i]);
	}
	return 0;
}
