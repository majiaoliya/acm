#include <iostream>
#include <string.h>
#include <limits>
using namespace std;

#define X 
#define T '*'

//https://blog.csdn.net/wangmengfuu/article/details/80941225
int myMax; //标记最大
int mapMin; //数字矩阵中最小的值
int n; //n*n的矩阵

int minRow; //数字矩阵最小值的行和列
int minCol;

void paser(char* mtx, char* mtx_map) { //将原地图化为数字地图
	int row = 0, col = 0;
	for(row=0; row<n; row++) {
		for(col=0; col<n; col++) {
			char* t = mtx+n*row+col;
			if(*t == 'X') {
				*(mtx_map+n*row+col) = 'X';
			} else if(*t == '.') {
				char* mt = mtx_map+n*row+col;
				for(int i=row-1; i>=0 && (*(mtx+n*i+col) != 'X'); i--) { (*mt) ++; }
				for(int i=row+1; i<n && (*(mtx+n*i+col) != 'X'); i++) { (*mt) ++; }
				for(int i=col-1; i>=0 && (*(mtx+n*row+i) != 'X'); i--) { (*mt) ++; }
				for(int i=col+1; i<n && (*(mtx+n*row+i) != 'X'); i++) { (*mt) ++; }
			}
			if(*(mtx_map+n*row+col) < mapMin) {
				mapMin = *(mtx_map+n*row+col);
				minRow = row, minCol = col;
			}
		}
	}
}

void display(char* mtx) {
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			cout << (int)*(mtx+n*i+k) << "\t";
		}
		cout << endl;
	}
}

/**
bool can(char* mtx, int row, int col) { //判断该位置是否可以放炮台
	bool ret = true;
	do {
		if(*(mtx+n*row+col) == 'X') {
			ret = false; break;
		}
		if(!ret) break;

		for(int i=row-1; i>=0 && *(mtx+n*i+col) != 'X'; i--) {
			if(*(mtx+n*i+col) == '*') {
				ret = false; break;
			}
		}
		if(!ret) break;

		for(int i=row+1; i<n && *(mtx+n*i+col) != 'X'; i++) {
			if(*(mtx+n*i+col) == '*') {
				ret = false; break;
			}
		}
		if(!ret) break;

		for(int i=col-1; i>=0 && *(mtx+n*row+col) != 'X'; i--) {
			if(*(mtx+n*row+i) == '*') {
				ret = false; break;
			}
		}
		if(!ret) break;

		for(int i=col+1; i<n && *(mtx+n*row+col) != 'X'; i++) {
			if(*(mtx+n*row+i) == '*') {
				ret = false; break;
			}
		}
	} while(0);

	return ret;
}

void bt(char* mtx, int row, int col) { //回溯放置炮台
	char* t = mtx+n*row+col;
	cout << "bting" << endl;
	if(can(mtx, row, col)) {
		*t = '*'; //放置

		int l = col-1, up = row-1, r = col+1, down = row+1;
		if(l>=0 && up>=0) { bt(mtx, l, up); } //回溯左上 
		if(r<n && up>=0) { bt(mtx, r, up); } //回溯右上
		if(l>=0 && down<n) { bt(mtx, l, down); } //回溯左下
		if(r<n && down<n) { bt(mtx, r, down); } //回溯右下
		
		*t = '.'; //复原
	}
}
*/

int minId(char* line) {
	int min = *line;
	int i, ret = 0;
	for(i=0; i<n; i++) {
		if(min > line[i]) {
			min = line[i];
			ret = i;
		}
	}
	return ret;
}

int main(void) {

	for(; cin>>n, n; ) {
		char mtx[n][n]; //地图
		char mtx_map[n][n]; //新统计出来的地图数字越小能装越多
		memset(mtx, 0, n*n);
		memset(mtx_map, 0, n*n);
		for(int i=0; i<n; i++) //输入矩阵
		  cin >> mtx[i];
		myMax = 0; //初始化当前最大
		mapMin = 'X', minRow = 0, minCol = 0;
		paser((char*)mtx, (char*)mtx_map); //得到数字地图
		for(int i=0; i<n; i++) {
			int c;
			char* mt = (char*) mtx_map;
			while(c=minId(mtx_map[i]), mtx_map[i][c] != 'X') {
				myMax ++;
				mtx_map[i][c] = 'X';
				for(int k=i-1; k>=0; k--) {
					if(*(mt+n*k+c) == 'X') break;
					*(mt+n*k+c) = 'X';
				}
				for(int k=i+1; k<n; k++) {
					if(*(mt+n*k+c) == 'X') break;
					*(mt+n*k+c) = 'X';
				}
				for(int k=c-1; k>=0; k--) {
					if(*(mt+n*i+k) == 'X') break;
					*(mt+n*i+k) = 'X';
				}
				for(int k=c+1; k<n; k++) {
					if(*(mt+n*i+k) == 'X') break;
					*(mt+n*i+k) = 'X';
				}

			}
		}

		cout << myMax << endl;
	}

	return 0;
}       
