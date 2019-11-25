#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

class House {
	public :
		int v;

		House() : v(0) { }
		House(int _v) : v(_v) { }

		bool operator < (House& other) {
			return this->v < other.v;
		}

		int compareTo(House& other) {
			return this->v > other.v ? 1 : this->v < other.v ? -1 : 0;
		}
};

bool cmpt(House& h1, House& h2) { return !(h1.v < h2.v); }

House tv[1005];
House kv[1005];

int main(void) {

	memset(tv, 0, sizeof(tv));
	memset(kv, 0, sizeof(kv));

	int n;
	for( ; cin>>n, n; ) {
		int rs = 0;
		for(int i=0; i<n; i++) cin >> tv[i].v;
		for(int i=0; i<n; i++) cin >> kv[i].v;
		std::sort(tv, tv+n, cmpt);
		std::sort(kv, kv+n, cmpt);

		int win = 0, fail = 0, equal = 0;

		for(int i=0, cur=0; i<n, cur<n; i++) {
			for( ; cur<n; ) {
				int cmp = tv[i].compareTo(kv[cur]);
				cur ++;
				if(cmp == 1) {
					win ++;
					break;
				} else if(cmp == -1) {

				} else if(cmp == 0){
					equal ++;
					break;
				}
			}
		}

		fail = n - win - equal;
		rs = win*200 - fail*200;
		cout << rs << endl;
	}

/**
	int n;
	for( ; cin>>n, n; ) {
		int rs = 0;
		std::vector<House>* ptv = new std::vector<House>(); // Tian's houses
		std::vector<House>* pkv = new std::vector<House>(); //king's houses
		std::vector<House>& tv = *ptv;
		std::vector<House>& kv = *pkv;
		for(int i=0; i<n; i++) { //田忌的马
			int v; 
			cin >> v;
			House h(v);
			tv.push_back(v);
		}
		for(int i=0; i<n; i++) { //王的马
			int v;
			cin >> v;
			House h(v);
			kv.push_back(v);
		}

		std::sort(tv.begin(), tv.end(), cmpt);
		std::sort(kv.begin(), kv.end(), cmpt);
		int win = 0, fail = 0, equal = 0; //胜场 败场 平局
		for(int i=0, cur=0; i<tv.size(), cur<kv.size(); i++) {
			for( ; cur<kv.size(); ) {
				int cmp = tv[i].compareTo(kv[cur]);
				cur ++;
				if(cmp == 1) {
					win ++;
					break;
				} else if(cmp == -1) {

				} else if(cmp == 0) {
					equal ++;
					break;
				}
			}
		}
		fail = n-equal-win;
		rs = win*200 - fail*(200);
		cout << rs << endl;
	}
*/

	return 0;
}
