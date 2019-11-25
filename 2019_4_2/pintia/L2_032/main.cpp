#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
	freopen("test", "r", stdin);

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	for( ; k--; ) {
		int arr[n];
		for(int t=0; t<n; t++)
		  scanf("%d", arr+t);
		/**
		for(int t=0; t<n; t++)
		  printf("%d,", arr[t]);
		printf("\n");
		*/
		stack<int> stk;
		int color = 1, i = 0;
		while(true) {
			if(i>n || stk.size()>m) break;
			if(!stk.empty() && stk.top()==color) {
				color++, stk.pop();
				continue;
			}
			if(arr[i] == color) {
				color++, i++;
				continue;
			}
			stk.push(arr[i]);
			i++;
		}
		while(!stk.empty() && stk.top()==color)
			stk.pop(), color++;
		printf("%s\n", (color-1)==n ? "YES":"NO");
	}

	return 0;
}
