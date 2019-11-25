#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class Entry {
	public :
		string color;
		int count;
		
		Entry() : count(0) { }
		Entry(string _c) : color(_c), count(1) { }

		Entry(string _c, int _count) : color(_c), count(_count) { }
		~Entry() { }

		Entry operator + (int i) {
			Entry e(this->color);
			e.count = this->count + i;
		}

		bool operator == (string _color) {
			return this->color == _color;
		}
		bool operator > (Entry & other) {
			return this->count > other.count;
		}
		bool operator < (Entry & other) {
			return this->count < other.count;
		}
};

int main(void) {
	
	for(; ;) {
		
		int n;
		cin >> n; //n个
		if(!n) break;

		vector<Entry> es;
		int i = 0;
		for(; i<n; i++) {
			string color;
			cin >> color;
			int k;
			for(k=0; k<es.size(); k++) {
				if(es[k] == color) {
					es[k].count ++;
					break;
				}
			}
			if(k == es.size()) {
				Entry e(color);
				es.push_back(e);
				//cout << "push_back color " << color << endl;
			}
		}

		sort(es.begin(), es.end());
		int t = es[es.size() - 1].count;
		for(int k=es.size()-1; k>=0; k--) {
			if(es[k].count >= t) {
				cout << es[k].color << endl;
			}
		}
	}

	return 0;
}
