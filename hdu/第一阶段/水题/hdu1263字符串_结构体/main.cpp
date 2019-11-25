#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>
#define MAXN 3005
using namespace std;

int m;

struct F {
	string name;
	int sum;
	F() : name(string()), sum(0) { }
	F(string& n) : name(n), sum(0) { }
} arr[MAXN];

int cmp(F* x, F* y) { return x->name < y->name; }

map<string, vector<F*>> mp; //地址映射F

void add_sum(string& name, string& addr, int& cnt, int sum) {	
	vector<F*>& fs = mp[addr];
	bool have = false;
	for(int i=0; i<fs.size(); i++) {
		if(fs[i]->name == name) {
			fs[i]->sum += sum;
			have = true;
			break;
		}
	}
	if(!have) { //向addr添加水果
		arr[++cnt].name = name;
		arr[cnt].sum = 0;
		arr[cnt].sum += sum;
		fs.push_back(arr+cnt);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t); 
	for( ; t--; ) {
		mp.clear();
		cin >> m;
		string name, addr;
		
		int sum = 0, cnt = 0;
		for(int i=1; i<=m; i++) {
			cin >> name >> addr >> sum;
			add_sum(name, addr, cnt, sum);
		}
		map<string, vector<F*>>::iterator it = mp.begin();
		for( ; it!=mp.end(); it++) {
			printf("%s\n", (it->first).data());
			vector<F*>& tv = it->second;
			sort(tv.begin(), tv.end(), cmp);
			for(int i=0; i<tv.size(); i++) {
				printf("   |----%s(%d)\n", (tv[i]->name).data(), tv[i]->sum);
			}
		}
		if(t) printf("\n");
	}
	return 0;
}
