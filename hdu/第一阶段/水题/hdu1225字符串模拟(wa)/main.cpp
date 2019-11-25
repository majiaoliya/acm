#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#define MAXN 200005
#define STR_LEN 64
using namespace std;

struct Node {
	string name;
	int win, loss, fen;
} arr[MAXN];

int cmp(Node& x, Node& y) {
	if(x.fen == y.fen) {
		int sub1 = x.win - x.loss, sub2 = y.win - y.loss;
		if(sub1 == sub2) {
			if(x.win == y.win)
				return x.name > y.name;
			return x.win > y.win;
		}
		return sub1 > sub2;
	}
	return x.fen > y.fen;
}

int main(void) {
	freopen("test", "r", stdin);
	int t, v1, v2;
	for( ; EOF != scanf("%d", &t); ) {
		char name1[50], name2[50];
		map<string, int> mp;
		int cnt = 0;
		for(int i=1; i<=(t<<1); i++) {
			scanf("%s VS %s %d:%d", name1, name2, &v1, &v2);
			int& id1 = mp[name1];
			int& id2 = mp[name2];
			if(id1 == 0) {
				id1 = ++cnt;
				arr[id1].name = name1;
			}
			if(id2 == 0) {
				id2 = ++cnt;
				arr[id2].name = name2;
			}
			arr[id1].win += v1, arr[id1].loss += v2;
			arr[id2].win += v2, arr[id2].loss += v1;
			
			if(v1 > v2) arr[id1].fen += 3;
			else if(v1 < v2) arr[id2].fen += 3;
			else 
				arr[id1].fen += 1, arr[id2].fen += 1;
		}
		sort(arr+1, arr+t+1, cmp);
		for(int i=1; i<=t; i++) {
			printf("%s %d\n", arr[i].name.data(), arr[i].fen);
		}
	}
	
	return 0;
}
