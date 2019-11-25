#include <iostream>
#include <set>
#include <vector>
#include <queue>
#define MAXN 9999999
using namespace std;

int n, x;
queue<int> a, b;

int main(void) {
	freopen("test", "r", stdin);
	char c = 'a';
	while(c != '\n') {
		scanf("%d", &x);
		a.push(x);
		c = getchar();
	}
	a.push(MAXN);
	c = 'a';
	int tc = 0;
	while(true) {
		if(b.empty()) {
			if(scanf("%d", &x) != EOF) b.push(x);
			c = getchar();
		}
		if(tc++) printf(",");
		if(a.front() < b.front()) {
			printf("%d", a.front());
			a.pop();
		} else {
			printf("%d", b.front());
			b.pop();
		}
		printf("this ?");
	}
	while(a.size() > 1) {
		if(tc++) printf(",");
	 	printf("%d", a.front());
		a.pop();
	}
	return 0;
}
