#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 4096
using namespace std;

string n1, n2;
int tag, rad;

int table[512];

void init() { //打表
	for(int i='0', k=0; i<='9'; i++, k++)
		table[i] = k;
	for(int i='a', k=10; i<='z'; i++, k++)
		table[i] = k;
}

string parse(string num, int rnum, int r) { //把num转成r进制
	string rs;
	
	return rs;
}

int main() {
	freopen("test", "r", stdin);
	init();
	cin >> n1 >> n2 >> tag >> rad;
	if(tag == 2) {
		string temp = n1;
		n1 = n2;
		n2 = temp;
	}
	if(n1 == n2) { // 9,10测试点
		printf("%d\n", rad);
	} else {
		int i;
		for(i=2; i<=35; i++) {
			if(n2 == parse(n1, rad, i)) { printf("%d\n", i); break; }
		}
		if(i>35)
			printf("Impossible\n");
	}
	return 0;
}


