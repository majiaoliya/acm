#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#define MAXN 100005
using namespace std;

int arr[MAXN];

int main()
{
	freopen("test", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	vector<int> temp, rs;
	
	for(int i=0; i<n; i++) {
		if(temp.empty()) {
			temp.push_back(arr[i]);
			i++;
		} else {
			if(arr[i] <= temp.back()) {
				if(rs.size() < temp.size()) {
					rs = temp;
				} else {
					temp.clear();
				}
			} else {
				temp.push_back(arr[i]);
				i++;
			}
		}
	}
	
	for(int i=0; i<rs.size(); i++) {
		if(i) printf(" ");
		printf("%d", rs[i]);
	}
	
	
//	vector<int> rs, fst_rs;
//	int cnt = 0, n, x, max_cnt = 0, lst;
//	for(int i=0; i<n; i++) {
//		scanf("%d", &x);
//		if(rs.size() == 0) {
//			rs.push_back(x);
//			lst = x;
//		} else {
//			if(x > lst) {
//				rs.push_back(x);
//				lst = x;
//			} else {
//				if(rs.size() > fst_rs.size()) {
////					printf("rs:%d  fst:%d\n", rs.size(), fst_rs.size());
//					fst_rs = rs;
//				}
//				rs.clear();
//				rs.push_back(x);
//				lst = x;
//			}
//		}
//	}
//	
//	for(int i=0; i<fst_rs.size(); i++) {
//		if(i) printf(" ");
//		printf("%d", fst_rs[i]);
//	}
	
	return 0;
}

