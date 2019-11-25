#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN (105*300)
using namespace std;

int cmp_col = 4;
struct Node {
	string name;
	int arr[5]; //arr[4]放成绩  arr[1][2][3]分别放答案的后面三个数
} nodes[MAXN];

int n;
int len[MAXN];
int cmp(Node& x, Node& y) {
	if(x.arr[cmp_col] == y.arr[cmp_col])
		return x.name < y.name;
	return x.arr[cmp_col] > y.arr[cmp_col];
}

int main() {
	
	freopen("test", "r", stdin);
	cin >> n;
	int cnt = 1, sum = 0;
	for(int i=1; i<=n; i++) {
		cin >> len[i];
		sum += len[i];
		int lef = cnt;
		for(int k=1; k<=len[i]; k++) {
			cin >> nodes[cnt].name >> nodes[cnt].arr[4];
			nodes[cnt].arr[2] = i; //记录属于第几个集合
			cnt ++;
		}
		int rig = cnt-1;
		sort(nodes+lef, nodes+rig+1, cmp);
		for(int k=lef, idx=2; k<=rig; k++) {
			if(k==lef) { nodes[k].arr[3] = 1; }
			else {
				int lst_g = nodes[k-1].arr[4];
				if(lst_g == nodes[k].arr[4]) {
					nodes[k].arr[3] = nodes[k-1].arr[3];
				} else {
					nodes[k].arr[3] = idx;
				}
				idx ++;
			}
		}
//		for(int k=lef; k<=rig; k++) {
//			cout << nodes[k].name << "-" << nodes[k].arr[4] << "-" << nodes[k].arr[3] << endl;
		}
//		cout << endl;
		sort(nodes+1, nodes+sum+1, cmp);
		cout << sum << endl;
		for(int k=1, idx=2; k<=sum; k++) {
			if(k==1) { nodes[k].arr[1] = 1; }
			else {
				int lst_g = nodes[k-1].arr[4];
				if(lst_g == nodes[k].arr[4]) {
					nodes[k].arr[1] = nodes[k-1].arr[1];
				} else {
					nodes[k].arr[1] = idx;
				}
				idx ++;
			}
			cout << nodes[k].name << " " << nodes[k].arr[1] << " " << nodes[k].arr[2] << " " << nodes[k].arr[3] << endl;
	}
	
	return 0;
}
