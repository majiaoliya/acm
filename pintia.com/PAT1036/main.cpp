#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAXN 10086
using namespace std;

int n;

int main() {
	freopen("test", "r", stdin);
	string boy, girl, bid, gid;
	int bg, gg;
	cin >> n;
	ios::sync_with_stdio(false);
	for(int i=0; i<n; i++) {
		string name, id, sex;
		int g;
		cin >> name >> sex >> id >> g;
		if(sex == "M") {
			if(boy.empty()) { boy = name, bid = id, bg = g; continue ; }
			else if(bg > g) {
				bg = g;
				bid = id;
				boy = name;
			}
		} else if(sex == "F") {
			if(girl.empty()) { girl = name, gid = id, gg = g; continue ; }
			else if(gg < g) {
				gg = g;
				gid = id;
				girl = name;
			}
		}
	}
	if(girl.empty()) cout << "Absent" << endl;
	else
		cout << girl << " " << gid << endl;
	if(boy.empty()) cout << "Absent" << endl;
	else
		cout << boy << " " << bid << endl;
	if(!boy.empty() && !girl.empty())
		cout << (gg-bg) << endl;
	else
		cout << "NA" << endl;
	return 0;
}
























