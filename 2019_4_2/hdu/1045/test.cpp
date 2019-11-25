#include <iostream>
using namespace std;

void fun(char* line) {
	for(int i=0; i<10; i++)
	  cout << (int) line[i] << '\t';
	cout << endl;
}

int main(void) {

	char mtx[10][10];
	for(int i=0; i<10; i++) {
		for(int k=0; k<10; k++) 
		  mtx[i][k] = k+i*10;
	}

	for(int i=0; i<10; i++)
	  fun(mtx[i]);

	return 0;
}
