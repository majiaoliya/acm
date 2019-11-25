#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <stack>
#define MAXN 512

using namespace std;

vector<string> lines;

int main()
{
//    freopen("test", "r", stdin); 
    
    int n;
  	scanf("%d", &n);
	cin.ignore();
	for(string line; n--; ) {
		getline(cin, line);
		lines.push_back(line);
		if(line.empty()) {
			printf("nai\n");
			return 0;
		}
	}
	int cnt = 0;
	bool tag = true;
	char tc;
	stack<char> stk;
	
	while(tag) {
		bool tag2 = true;
		for(int i=0; i<lines.size(); i++) {
			int idx = lines[i].size() - 1 - cnt;
			if(idx < 0) { tag = tag2 = false; break; }
			if(i == 0) tc = lines[i][idx];
			else {
				if(tc != lines[i][idx]) {
					tag = false;
					tag2 = false;
					break;
				} 
			}
		}
		if(tag2) {
			stk.push(tc);
			cnt ++;
		} 
	}
	if(!cnt) printf("nai\n");
	else {
		while(!stk.empty()) {
			printf("%c", stk.top());
			stk.pop();
		}
	}
    return 0;
}

