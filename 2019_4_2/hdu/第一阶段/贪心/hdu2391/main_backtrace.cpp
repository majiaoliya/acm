#include <iostream>
#include <stdlib.h>
using namespace std;

bool check(int r, int c, int curR, int curC) { //检查位置是否合法
	bool ret = true;
	if(curR >= r || curC >= c) ret = false;
	return ret;
}

void bt(int* mtx, int row, int col, int curR, int curC, int curM, int& max) {
	if(check(row, col, curR, curC)) {
		int temp = curM + *(mtx+curR*col+curC);
//		cout << "bt : " << temp << " (" << curR << "-" << curC << ")" << " (row:" << row << "," << "col:" << col << ")" << endl;

		if(row-1==curR && col-1==curC) {
			if(temp > max) { max = temp; }
			cout << "find: " << temp << endl;
			return;
		}

		bt(mtx, row, col, curR, curC+1, temp, max);
		bt(mtx, row, col, curR+1, curC, temp, max);
		bt(mtx, row, col, curR+1, curC+1, temp, max);
	}
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
		bt(mtx, row, col, 0, 0, 0, max);
		cout << max << endl;

		free(mtx);
	}

	return 0;
}
