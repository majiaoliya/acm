#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#define MAXN 16
using namespace std;

int a, b;

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &a, &b);
	int num = a*b;
	string snum = to_string(num);
	bool tag = false;
	for(int i=snum.length()-1; i>=0; i--) {
		if(snum[i] != '0') tag = true;
		if(tag)
			printf("%c", snum[i]);
	}
	return 0;
}

