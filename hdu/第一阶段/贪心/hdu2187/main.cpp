#include <iostream>
#include <algorithm>
#define M 1005
using namespace std;

class Mi {
	public:
		double unitP; //单价
		double w; //重量

		Mi() : unitP(0), w(0) { }
		Mi(double p, double _w) : unitP(p), w(_w) { }
		bool operator < (Mi& other) { return this->unitP < other.unitP; }
};

Mi arr[M];

int main(void) {

	int n;
	cin >> n;
	for( ; n--; ) {
		double money; //经费
		int m; //m种大米
		scanf("%lf %d", &money, &m);
		for(int i=0; i<m; i++) { scanf("%lf %lf", &(arr[i].unitP), &(arr[i].w)); }
		std::sort(arr, arr+m);

		/**
		  * 排好序后花光所有钱买
		  */
		double rs = 0;
		for(int i=0; i<m && money>0; i++) {
			if(money >= arr[i].w*arr[i].unitP) {
				rs += arr[i].w;
				money -= arr[i].w*arr[i].unitP;
			} else {
				rs += money/arr[i].unitP;
				break;
			}
		}
		printf("%.2f\n", rs);
	}


	return 0;
}
