#include <iostream>
using namespace std;

int main(void) {

	int n;
	for( ; cin>>n, n; ) {
		int start = 0;
		int end = 0;
		int sum = 0;
		for(int i=1; i<=n; i++) {
			cin >> end;
			int sub = end - start;
			int abs = end > start ? end - start : start - end;
			if(sub > 0) { //向up
				sum += abs*6 + 5;
			} else { //向down
				sum += abs*4 + 5;
			}
			start = end;
		}
		cout << sum << endl;
	}

	return 0;
}
