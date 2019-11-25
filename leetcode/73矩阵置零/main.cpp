#define ll long long int
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& mtx) {
        int row = mtx.size();
		if(!row || mtx[0].empty()) return ;
		int col = mtx[0].size();
		bool flag_col = false; //判断是否清除第一列
		bool flag_row = false; //判断是否清除第一行
		printf("row:%d col:%d\n", row, col);
		for(int i=0; i<row; i++) {
			for(int k=0; k<col; k++) {
				if(i==0 && mtx[i][k]==0) flag_row = true;
				if(k==0 && mtx[i][k]==0) flag_col = true;
				if(!mtx[i][k]) mtx[i][0] = mtx[0][k] = 0;
			}
		}
		for(int i=1; i<row; i++) {
			for(int k=1; k<col; k++) {
				if(!mtx[i][0] || !mtx[0][k]) mtx[i][k] = 0;
			}
		}
		if(flag_row) //清除第一行
			for(int i=0; i<col; i++) mtx[0][i] = 0;
    	if(flag_col) //清除第一列
			for(int i=0; i<row; i++) mtx[i][0] = 0;
	}
};

#define debug
#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	int row, col;
	while(~scanf("%d %d", &row, &col)) {
		vector<vector<int> > mtx(row, vector<int>(col, 0));
		for(int i=0; i<row; i++)
			for(int k=0; k<col; k++)
				cin >> mtx[i][k];
		Solution s;
		s.setZeroes(mtx);
		for(int i=0; i<row; i++) {
			for(int k=0; k<col; k++) {
				printf("%d ", mtx[i][k]);
			}
			printf("\n");
		}

		printf("\n");
	}
	return 0;
}
#endif
