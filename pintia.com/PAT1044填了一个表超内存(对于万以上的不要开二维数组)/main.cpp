//超内存
//#include <iostream>
//#include <vector>
//#include <set>
//#define MAXN 10005
//using namespace std;

//int mtx[MAXN][MAXN];
//int arr[MAXN], n, m;

//struct Node {
//	int row, col;
//	Node(int r, int c) : row(r), col(c) { }
//	Node() : row(0), col(0) { }
//	bool operator < (const Node& other) const {
//		if(row == other.row)
//			return col < other.col;
//		return row < other.row;
//	}
//};

//set<Node> rs;

//int main()
//{
//	freopen("test", "r", stdin);
//	scanf("%d %d", &n, &m);
//	for(int i=1; i<=n; i++)
//		scanf("%d", arr+i);
//	int min_abs = 99999999, tag = false;
//	
//	for(int i=1; i<=n; i++) {
//		for(int k=1; k<=i; k++) {
//			if(k == i) mtx[i][k] = arr[i];
//			mtx[k][i] = mtx[k][i-1] + arr[i];
//			if(mtx[k][i] == m) { //找刚好相等的 没有就找绝对值最近的
//				if(tag == false) rs.clear();
//				tag = true;
//				rs.insert(Node(k, i));
//			} else if(!tag) {
//				int tabs = abs(m - mtx[k][i]);
//				if(tabs > min_abs || mtx[k][i] < m) continue ;
//				if(tabs < min_abs) {
//					min_abs = tabs;
//					rs.clear();
//				}
//				rs.insert(Node(k, i));
//			}
//		}
//	}
//	set<Node>::iterator it = rs.begin();
//	while(it != rs.end()) {
//		printf("%d-%d\n", (*it).row, (*it).col);
//		it ++;
//	}
//	for(int k=1; k<=n; k++) {
//		printf("%d\t", k);
//	}
//	printf("\n");
//	for(int k=1; k<=n; k++) {
//		printf("%d\t", arr[k]);
//	}
//	printf("\n\n");
//	for(int i=1; i<=n; i++) {
//		for(int k=1; k<=n; k++) {
//			printf("%d\t", mtx[i][k]);
//		}
//		printf("\n");
//	}
//	return 0;
//}




//减少了下三角的无用搜索 依然超时.....
//#include <iostream>
//#include <vector>
//#include <set>
//#define MAXN 100005
//using namespace std;

//int n, m;
//int arr[MAXN], sum[MAXN];

//int binsearch(int arr[], int lef, int rig, int key) {
//	int mid, idx = -1;
//	while(lef <= rig) {
//		mid = (lef+rig) >> 1;
//		if(key > arr[mid])
//			lef = mid + 1;
//		else if(key < arr[mid])
//			rig = mid - 1;
//		else {
//			idx = mid;
//			break;
//		}
//	}
//	return idx;
//}

//struct Node {
//	int row, col;
//	Node(int r, int c) : row(r), col(c) { }
//	Node() : row(0), col(0) { }
//	bool operator < (const Node& other) const {
//		if(row == other.row)
//			return col < other.col;
//		return row < other.row;
//	}
//};

//set<Node> rs;

//int main()
//{
//	freopen("test", "r", stdin);
//	scanf("%d %d", &n, &m);
//	for(int i=1; i<=n; i++) {
//		scanf("%d", arr+i);
//		sum[i] = arr[i] + sum[i-1];
//	}
//	int min_abs = 1e8+9;
//	bool find_equal = false; //题目说如果没有(x==m) 就找x>m && abs(m-x)最小
//	for(int i=1; i<=n; i++) { //上三角 n 行全部查找 m 
//		for(int k=i; k<=n; k++) {
//			if(!find_equal && sum[k] == m) {
//				rs.clear();
//				find_equal = true;
//			}
////			printf("%d,", sum[k]);
//			if(!find_equal) {
//				int tabs = abs(sum[k] - m);
//				if(tabs < min_abs && sum[k] > m) {
//					rs.clear();
//					min_abs = tabs;
//					rs.insert(Node(k, i));
//				} else if(tabs == min_abs && sum[k] > m) {
//					rs.insert(Node(k, i));
//				} 
//			} else {
//				if(sum[k] == m) 
//					rs.insert(Node(k, i));
//			}
//			sum[k] -= arr[i];
//		}
////		printf("\n");
//	}
//	set<Node>::iterator it = rs.begin();
//	while(it != rs.end()) {
//		int mini = min((*it).col, (*it).row);
//		int maxi = max((*it).col, (*it).row);
//		printf("%d-%d\n", mini, maxi);
//		it ++;
//	}
//	return 0;
//}





#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, m;
int arr[MAXN], sum[MAXN];

int binsearch(int arr[], int lef, int rig, int key) {
	int mid, idx = -1;
	while(lef <= rig) {
		mid = (lef+rig) >> 1;
		if(key > arr[mid])
			lef = mid + 1;
		else if(key < arr[mid])
			rig = mid - 1;
		else {
			idx = mid;
			break;
		}
	}
	//这题的二分不太一样,题目要求如果没有(x==m) 就找x>m && abs(m-x)最小
	if(idx == -1) return rig+1; 
	return idx;
}

struct Node {
	int row, col;
	Node(int r, int c) : row(r), col(c) { }
	Node() : row(0), col(0) { }
	bool operator < (const Node& other) const {
		if(row == other.row)
			return col < other.col;
		return row < other.row;
	}
};

vector<Node> rs;

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", arr+i);
		sum[i] = arr[i] + sum[i-1];
	}
	int min_abs = 1e8+9;
	bool find_equal = false; //题目说如果没有(x==m) 就找x>m && abs(m-x)最小
	int key = m;
	sum[0] = sum[n+1] = min_abs;
	for(int i=1; i<=n; i++) { //上三角 n 行全部二分查找 m
		key += arr[i-1];
		int idx = binsearch(sum, 1, n, key);
		int tabs = abs(key-sum[idx]);
		if(tabs < min_abs) {
			rs.clear();
			rs.push_back(Node(i, idx));
			min_abs = tabs;
//			printf("min_abs=%d\n", min_abs);
		} else if(tabs == min_abs) {
			rs.push_back(Node(i, idx));
//			printf("min_abs=%d\n", min_abs);
		}
//		printf("key=%d  sum[%d]=%d\n", key, idx, sum[idx]);
	}
	for(int i=0; i<rs.size(); i++)
		printf("%d-%d\n", rs[i].row, rs[i].col);
//	set<Node>::iterator it = rs.begin();
//	while(it != rs.end()) {
//		int mini = min((*it).col, (*it).row);
//		int maxi = max((*it).col, (*it).row);
//		printf("%d-%d\n", mini, maxi);
//		it ++;
//	}
	return 0;
}

