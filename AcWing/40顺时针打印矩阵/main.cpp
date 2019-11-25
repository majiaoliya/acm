#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 10005
#define debug

typedef vector<vector<bool> > vis;

class Solution {
public:
	int row, col;
 	bool check(int r, int c, vis& v) {
		return (r>=0 && r<row && c>=0 && c<col && !v[r][c]);
//		return (r<0 || r>=row || c<0 || c>=col || v[r][c]);
	}	
	vector<int> printMatrix(vector<vector<int> > matrix) {
		row = matrix.size(), col = matrix[0].size();
		int drow[] = { 0, 1, 0, -1 }, dcol[] = { 1, 0, -1, 0 };
		int cnt = row * col, r = 0, c = 0, i = 0;
		vector<int> ret;
		vis v(row, vector<bool>(col, false));
		while(cnt) {
//			printf("now:%d %d next:%d %d\n", r, c, r+drow[i], c+dcol[i]);
			ret.push_back(matrix[r][c]);
			v[r][c] = true;
			if(check(r+drow[i], c+dcol[i], v)) {
				r += drow[i], c += dcol[i];
			} else i = (i+1) % 4;
			cnt --;
		}
		return ret;
    }
};

#ifdef debug
int main(void) {
	vector<int> v = { 1, 2, 3, 4 };
	vector<int> v2 = { 5, 6, 7, 8 };
	vector<int> v3 = { 9, 10, 11, 12 };
	vector<vector<int> > mtx = {v, v2, v3};
	Solution s;
	vector<int> rs = s.printMatrix(mtx);
	for(auto i : rs)
		printf("%d ", i);
	return 0;
}
#endif
