#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	bool check(int mid, vector<vector<int> >& mtx, int k, int n) {
		int sum = 0;
	}

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
		int L = 0, R = matrix[n-1][n-1], ans = 0; // [L, R]
		while(L <= R) {
			int mid = (L + R) >> 1;
			if(check(mid, matrix, k)) {

			}
		}
    }
};

int main(void) {
	vector<int> v1 = { 1, 5, 9};
	vector<int> v2 = { 10, 11, 13};
	vector<int> v3 = { 12, 13, 15};
	vector<vector<int> > mtx = { v1, v2, v3 };
	return 0;
}
