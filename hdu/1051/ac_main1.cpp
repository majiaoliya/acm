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
};

bool cmp(Wood& w1, Wood& w2) {
	if(w1.x == w2.x)
	  return w1.y < w2.y;
	else 
	  return w1.x < w2.x;
}

Wood arr[5050];

int main(void) {

	int n;
	cin >> n;
	for( ; n--; ) {
		int wn;
		cin >> wn;
		int rs = 0;
		for(int i=0; i<wn; i++) {
			int x, y;
			cin >> x, cin >> y;
			Wood tw(x, y);
			arr[i] = tw;
		}
		std::sort(arr, arr+wn, cmp);
		for(int i=0; i<wn; i++) {
			if(arr[i].visit == false) {
				rs ++;
				arr[i].visit = true;
				int cur = i;
				for(int k=cur+1; k<wn; k++) {
					if(arr[k].visit == false && arr[cur].y <= arr[k].y) {
						arr[k].visit = true;
						cur = k;
					}
				}
			}
		}
		cout << rs << endl;
	}

	return 0;
}
