#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n, t;

//double abs(double x) { return x > 0.00000 ? x : -x; }
/** 不用这么麻烦
struct Rect {
	double toplefX, toplefY, butrigX, butrigY;
	Rect(double tx, double ty, double bx, double by) {
		double xdist = abs(tx - bx), ydist = abs(ty - by);
		if(tx > bx) {
			toplefX = tx - xdist;
			butrigX = bx + xdist;
		} else {
			toplefX = tx, butrigX = bx;
		}
		toplefY = ty,butrigY = by;
	}
	
	double getw() { return abs(this->toplefX - this->butrigX); }
	double geth() { return abs(this->toplefY - this->butrigY); }
	
	double calc(Rect& other) {
		double rs = 0;
		Rect* a, *b; //a是靠左的矩形, b是靠右的矩形
		if(this->toplefX < other.toplefX) { //this靠左
			a = this, b = &other;
		} else {
			a = &other, b = this;
		}
		if(abs(a->toplefX-b->butrigX) < (a->getw() + b->getw()) && 
			abs(a->toplefY-b->butrigY) < (a->geth() + b->geth())) { //有交集
			double tw = abs(a->butrigX - b->toplefX);
			double th = abs()
		}
		return rs;
	}
};
*/

int main(void) {
	freopen("test", "r", stdin);
	return 0;
}
