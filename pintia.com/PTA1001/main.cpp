#include <iostream>
#include <stack>

using namespace std;

int main() {
	freopen("test", "r", stdin);
	int a, b;
	for( ; EOF != scanf("%d %d", &a, &b); ) {
		int rs = a + b;
		int trs = abs(rs);
		if(rs == 0) printf("0\n");
		else {
			stack<int> s;
			int count = 0;
			while(trs) {
				s.push((trs%10) + '0');
				trs /= 10;
				if(++count % 3 == 0) s.push(',');
			}
			if(rs<0 && rs!=0) printf("-");
			bool tag = false;
			while(!s.empty()) {
				if(s.top() != ',') tag = true;
				if(tag) {
					printf("%c", s.top());
				}
				s.pop();
			}
			printf("\n");
		}
	}
	return 0;
}
