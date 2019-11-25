#include <iostream>
#include <stdio.h>
using namespace std;

double fun(int i) {
	if(i == 0) {
		return 1;
	} else {
		return i* fun(i-1);
	}
}

int main(void) {

	cout << "n e" << endl;
	cout << "- -----------" << endl;
	double arr[11];
	arr[0] = 0;
	cout << "0 1" << endl;
	cout << "1 2" << endl;
	cout << "2 2.5" << endl;
	for(int i=1; i<=10; i++) {
		arr[i] = arr[i-1] + 1/fun(i-1);
		if(i > 3)
			printf("%d %.9f\n", i-1, arr[i]);
	}

	return 0;
}
