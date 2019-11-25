#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 60005

int size;

string cmd;

struct Node {
	string str;
	int val, idx, w;
	friend bool operator < (Node a, Node b) {
		if(a.w != b.w) return b.w < a.w;
		return b.idx < a.idx;
	}
} ;

std::priority_queue<Node> q;

int main(void) {
	freopen("test", "r", stdin);
	int idx = 0;
	while( cin>>cmd ) {
		if(cmd == "GET") {
			if(q.empty()) {
				cout << "EMPTY QUEUE!" << endl;
				continue ;
			}
			Node t = q.top();
			q.pop();
			cout << t.str << " " << t.val << endl;
		} else {
			Node t;
			cin >> t.str >> t.val >> t.w;
			t.idx = idx++;
			q.push(t);
		}
	}
	return 0;
}



