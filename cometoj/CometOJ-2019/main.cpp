#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long int
const int MAXN = 100005;

int t, a, b, c, d;

bool func(int x, int y) { //判断同号
	return (x>=0&&y>=0) || (x<=0&&y<=0);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
//		printf("%d %d %d %d ", a, b, c, d);
		if(a<0 && c>0 && b<0 && d>0) printf("8\n");
		else if(a>=0 && b>=0 && c>=0 && d>=0) printf("5\n");
		else if(a>=0 && b<=0 && c>=0 && d<=0) printf("5\n");
		else if(a<=0 && b<=0 && c<=0 && d<=0) printf("5\n");
		else if(a<=0 && b>=0 && c<=0 && d>=0) printf("5\n");
		else printf("6\n");
	}
	return 0;
}
