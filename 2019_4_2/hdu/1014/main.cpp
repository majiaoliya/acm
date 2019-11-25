#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a, int b) { //辗转相除法求最大公约数
	if(a%b == 0) return b;
	else return gcd(b, a%b);
}

/*
 * 这道题step和mod的公约数不为1就是bad choice
 */
int main(void) {

	int step, mod;
	for( ; cin>>step, cin>>mod; ) {
		int cd = gcd(step, mod);
		if(cd == 1) {
			cout << setiosflags(ios::right) << setw(10) << step << setw(10) << mod << "    " << setiosflags(ios::left) << "Good Choice" << endl << endl;
		} else {
			cout << setiosflags(ios::right) << setw(10) << step << setw(10) << mod << "    " << setiosflags(ios::left) << "Bad Choice" << endl << endl;
		}
	}

	return 0;
}
