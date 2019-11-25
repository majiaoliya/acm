#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024
#define Pi 3.1415926535
using namespace std;

double fun1(double r) { //圆
	return (4*Pi*r*r*r)/3;
}

double fun2(double r, double h) { //圆柱
	return Pi*r*r*h;
}

double fun3(double r, double h) { //圆锥
	return (Pi*r*r*h)/3;
}

int main() {
	freopen("test", "r", stdin);
	string pstr = "1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:";
	int n;
	for( ; ; ) {
		cout << pstr << endl;
		cin >> n;
		if(n==1) {
			cout << "Please enter the radius:" << endl;
			double r;
			cin >> r;
			printf("%.2lf\n", fun1(r));
		} else if(n==2) {
			cout << "Please enter the radius and the height:" << endl;
			double r, h;
			cin >> r >> h;
			printf("%.2lf\n", fun2(r, h));
		} else if(n==3) {
			cout << "Please enter the radius and the height:" << endl;
			double r, h;
			cin >> r >> h;
			printf("%.2lf\n", fun3(r, h));
		} else {
			break;
		}
	}
	return 0;
}
























