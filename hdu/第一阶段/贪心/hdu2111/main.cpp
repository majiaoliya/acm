#include <iostream>
#include <algorithm>
#include <string.h>
#define M 105
using namespace std;

class Good {
	public:
		int unitP; //单价 题目给出的p是单价
		int v; //体积

		Good() : unitP(0), v(0) { }
		Good(int p, int _v) : unitP(p), v(_v) { }

		bool operator < (Good& other) { return this->unitP < other.unitP; }
		bool operator > (Good& other) { return this->unitP > other.unitP; }
		bool operator == (Good& other) { return this->unitP == other.unitP; }
};

Good arr[M];
bool cmp(Good& g1, Good& g2) { return g1 > g2; }

int main(void) {

	for(int v, n; cin>>v>>n; ) {

		for(int i=0; i<n; i++) { cin >> arr[i].unitP >> arr[i].v; }
		std::sort(arr, arr+n, cmp);
		
		int max = 0;
		for(int i=0; i<n; i++) { //排好序后 挨个装就好了
			if(v >= arr[i].v) {
				v -= arr[i].v;
				max += arr[i].unitP*arr[i].v;
			} else {
				max += arr[i].unitP*v;
				break;
			}
		}
		cout << max << endl;
	}
	
	return 0;
}
