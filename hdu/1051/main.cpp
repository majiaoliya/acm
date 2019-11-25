#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Wood {
	public:
		int x, y;
		bool visit;
		
		Wood() : x(0), y(0), visit(false) { }
		Wood(int _x, int _y) : x(_x), y(_y), visit(false) { }
		
		bool operator < (Wood& other) {
			if(this->x == other.x)
			  return this->y < other.y;
			else 
			  return this->x < other.x;
		}
};

int main(void) {

	int n;
	cin >> n;
	
	for( ; n--; ) {
		int wn, time = 0;
		std::vector<Wood>* pv = new std::vector<Wood>();
		std::vector<Wood>& v = *pv;
		cin >> wn;
		for(int i=0; i<wn; i++) {
			int x, y;
			cin >> x, cin >> y;
			Wood tw(x, y);
			v.push_back(tw);
		}

		std::sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++) {
			if(v[i].visit == false) {
				time ++;
				v[i].visit = true;
				int cur = i;
				for(int k=cur+1; k<v.size(); k++) {
					if(v[k].visit == false && v[cur].y <= v[k].y) {
						v[k].visit = true;
						cur = k;
					}
				}
			}
		}

		cout << time << endl;
		delete pv;
	}

	return 0;
}
