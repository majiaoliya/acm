#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, t, m;

int main(void) {
	freopen("test", "r", stdin);
	
	for(cin>>t; t--; ) {
		string str, tag;
		int x;
		cin >> m >> str;
		if(str[2] == 'F') { //FIFO
			queue<int> q;
			while(m--) {
				cin >> tag;
				if(tag=="IN") {
					cin >> x;
					q.push(x);
				} else {
					if(q.empty()) {
						cout << "None" << endl;
						continue;
					}
					cout << q.front() << endl;
					q.pop();
				}
			}
		} else { //FILO
			stack<int> stk;
			while(m--) {
				cin >> tag;
				if(tag=="IN") {
					cin >> x;
					stk.push(x);
				} else {
					if(stk.empty()) {
						cout << "None" << endl;
						continue;
					}
					cout << stk.top() << endl;
					stk.pop();
				}
			}
		}
	}

	return 0;
}
