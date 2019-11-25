#include <iostream>
#include <stdlib.h>
using namespace std;

bool check(int r, int c, int curR, int curC) { //检查位置是否合法
	bool ret = true;
	if(curR >= r || curC >= c) ret = false;
	return ret;
}

int main(void) {

	int n; cin >> n;
	for( ; n--; ) {
		int row, col;
		scanf("%d %d", &row, &col);

		int* mtx = (int*) malloc(sizeof(int)*row*col);
		for(int i=0; i<row; i++) {
			for(int k=0; k<col; k++) 
			  scanf("%d", mtx+col*i+k);
		}
//#define DEBUG_OUTPUT
#ifdef DEBUG_OUTPUT
		for(int i=0; i<row; i++) {
			for(int k=0; k<col; k++) {
				cout << *(mtx+col*i+k) << " ";
			}
			cout << endl;
		}
#endif

		int max = 0;
		cout << max << endl;

		free(mtx);
	}

	return 0;
}
