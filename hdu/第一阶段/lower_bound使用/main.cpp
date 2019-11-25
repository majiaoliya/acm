#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	
	vector<int> v1 = {2, 34, 4, 5, 89, 31, 1};
	vector<int> v2;
	for(int i=0; i<v1.size(); i++) {
		// lower_bound(iterator begin, iterator end, T val)
		// 可以取到[begin, end] 适合val的位置 相当于插入排序
		vector<int>::iterator mid = lower_bound(v2.begin(), v2.end(), v1[i]);
		v2.insert(mid, v1[i]);
	}
	for(int i=0; i<v2.size(); i++)
		printf("%d,", v2[i]);
	return 0;
}
