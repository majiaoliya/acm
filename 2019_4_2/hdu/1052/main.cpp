#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

/**
  * https://www.cnblogs.com/DOLFAMINGO/p/7538779.html
  */
class House {
	public :
		int v, vsId;
		
		House() : v(0), vsId(0) { }
		House(int _v, int _vsId) : v(_v), vsId(_vsId) { }
		
		bool operator > (House& o) { return this->v > o.v; }
		bool operator < (House& o) { return this->v < o.v; }
		bool operator == (House& o) { return this->v == o.v; }
		bool operator <= (House& o) { return this->v <= o.v; }
		
		int compareTo(House& other) {
			return this->v > other.v ? 1 : this->v < other.v ? -1 : 0;
		}
};

bool cmp(House& h1, House& h2) { return h1.v > h2.v; }

House tv[1005];
House kv[1005];

int main(void) {
	
	int n;
	for( ; cin>>n, n; ) {
		int tFast = 0, tLow = n-1; //tian fast's and low's
		int kFast = 0, kLow = n-1; //king fast's and low's
		for(int i=0; i<n; i++) cin >> tv[i].v;
		for(int i=0; i<n; i++) cin >> kv[i].v;

		std::sort(tv, tv+n, cmp);
		std::sort(kv, kv+n, cmp);

		int win = 0;
		for( ; tFast <= tLow; ) {
			if(tv[tLow] > kv[kLow]) { //田弱赢齐弱
				win ++;
				tLow --, kLow --;
			} else if(tv[tLow] < kv[kLow]) { //田弱输齐弱
				win --;
				tLow --, kFast ++;
			} else { //田弱持平齐弱
				if(tv[tFast] > kv[kFast]) { //田强能赢齐强
					win ++; //赢掉它
					tFast ++, kFast ++;
				} else if(tv[tFast] < kv[kFast]) { //田强输齐强
					win --;
					tLow --, kFast ++; //用弱的拖强的下水

				/**
				 * 田强持平齐强时: 用弱马去拖(可能输,可能平) 输不要紧,因为田强可能会战胜后面的齐弱(相当于不赢不输)
				 */
				} else if(tv[tFast] == kv[kFast]) { //田强持平齐强 还是用弱的去拖(但田弱的可能持平齐强)
					if(tv[tLow] > kv[kFast]) { 
						win ++;
					} else if(tv[tLow] < kv[kFast]) {
						win --;
					}
					tLow --, kFast ++;
				}
			}
		}

		int rs = win*200;
		cout << rs << endl;
	}

	return 0;
}
