#include <iostream>
#include <algorithm>
#include <set>
#include <string.h>
#include <stack>
#include <stdlib.h>
#include <vector>
#define MAXN 10000007
using namespace std;

string line;

int main(void) {
	freopen("test", "r", stdin);
	while(getline(cin, line), line[0] != 'E') {
		vector<int> nums;
		vector<char> fhs;
		char buf[1024];
		int i = 0, k = 0;
		while(i <= line.length()) {
			if(line[i]>='0' && line[i]<='9')
				buf[k++] = line[i];
			else {
				buf[k] = 0;
				nums.push_back(atoi(buf));
				k = 0;
				if(line[i])
					fhs.push_back(line[i]);
			}
			i ++;
		}
		stack<int> s1;
		stack<char> s2;
		s1.push(nums[0]);
		for(i=1, k=0; i<nums.size(); i++, k++) {
			s1.push(nums[i]);
			s2.push(fhs[k]);
			if(s2.top() == '*') {
				s2.pop();
				int x = s1.top();
				s1.pop();
				int y = s1.top();
				s1.pop();
				s1.push(x*y);
			}
		}

		while(!s2.empty()) {
			int x = s1.top(); s1.pop();
			int y = s1.top(); s1.pop();
			char c = s2.top(); s2.pop();
			if(c == '-') s1.push(y-x);
			else s1.push(y+x);
		}

		printf("%d\n", s1.top());
	}
	return 0;
}
