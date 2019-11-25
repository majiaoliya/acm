#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

typedef priority_queue<int> MaxHeap;
typedef priority_queue<int, vector<int>, greater<int> > MinHeap;

int t, n, cases;

inline void swapit(MaxHeap& max_heap, MinHeap& min_heap) {
	int minv = min_heap.top(), maxv = max_heap.top();
	min_heap.pop(), max_heap.pop();
	max_heap.push(minv), min_heap.push(maxv);
}

#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &cases, &n);
		MaxHeap max_heap;
		MinHeap min_heap;
		int cnt = 0;
		vector<int> v;
		for(int i=1, x; i<=n; i++) {
			scanf("%d", &x);
			max_heap.push(x);
			while(max_heap.size() > min_heap.size()+1) {
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
			while(max_heap.size() && min_heap.size() && (min_heap.top()<max_heap.top())) swapit(max_heap, min_heap);
			if(i & 1) v.push_back(max_heap.top());
		}
		printf("%d %d\n", cases, v.size());
		for(int i=1; i<=v.size(); i++) {
			printf("%d ", v[i-1]);
			if(!(i%10) || i==v.size()) printf("\n");
		}
	}
	return 0;
}
#endif
