#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int x;
} nodes[32];

bool cmp(Node& x, Node& y) {
	return x.x > y.x;
}

int main(void) {
	freopen("test", "r", stdin);
	int n = 11;
	int arr[] = {323, 432, 32, 43, 52, 93, 538, 3, 5, 1, 0};
	vector<int> v;
	for(int i=0; i<n; i++)
		v.push_back(arr[i]);
	for(int i=0; i<n; i++)
		nodes[i].x = arr[i];
	std::make_heap(arr, arr+11);
	std::make_heap(v.begin(), v.end());
//	pop_heap(v.begin(), v.end()); //pop_heap把arr[0]丢到屁股后头去了
	pop_heap(arr, arr+n);
	printf("size:%d\n", v.size());
	for(int i=0; i<v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	while(n) {
		printf("%d ", arr[0]);
		std::pop_heap(arr, arr+n);
		n --;
	}

	// 结构体建堆
	n = 11;
	printf("\n");
	std::make_heap(nodes, nodes+n, cmp);
	while(n) {
		printf("%d ", nodes[0].x);
		std::pop_heap(nodes, nodes+n, cmp);
		n --;
	}
	return 0;
}
