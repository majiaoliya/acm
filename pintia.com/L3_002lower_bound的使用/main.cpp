/**
 * L3_002  lower_bound的使用
 */ 

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#define MAX 100005

using namespace std;

int n;

int main(void) {
	//freopen("test", "r", stdin);
	scanf("%d", &n);
	stack<int> stk; //原数组
	vector<int> sort_arr; //排好序的数组
	char buf[32];
	for(int i=0; i<n; i++) {
		scanf("%s", buf);
		if(buf[1] == 'o') { // pop
			if(stk.empty()) {
				printf("Invalid\n");
				continue ;
			}
			int val = stk.top();
			stk.pop();
			vector<int>::iterator mid = lower_bound(sort_arr.begin(), sort_arr.end(), val);
			sort_arr.erase(mid);
			printf("%d\n", val);
		} else if(buf[1] == 'e') { // peek mid
			if(stk.empty()) {
				printf("Invalid\n");
				continue ;
			}
			if(sort_arr.size()%2 == 0) //偶
				printf("%d\n", sort_arr[(sort_arr.size()-1)/2]);
			else //奇
				printf("%d\n", sort_arr[sort_arr.size()/2]);
			
		} else if(buf[1] == 'u') { // push 
			int val;
			scanf("%d", &val);
			stk.push(val);
			vector<int>::iterator mid = lower_bound(sort_arr.begin(), sort_arr.end(), val);
			sort_arr.insert(mid, val);
//			printf("push %d\n", val);
		}
	}
//	printf("size:%d\n", sort_arr.size());
	return 0;
}
