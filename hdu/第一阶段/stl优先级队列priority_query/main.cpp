#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	int arr[] = {323, 432, 32, 43, 52, 93, 538, 3, 5, 1, 0};
	
	priority_queue<int, vector<int>, greater<int> > pri_q;
	for(int i=0; i<11; i++)
		pri_q.push(arr[i]);
	for( ; !pri_q.empty(); ) {
		printf("%d,", pri_q.top());
		pri_q.pop();
	}
	
	return 0;
}
