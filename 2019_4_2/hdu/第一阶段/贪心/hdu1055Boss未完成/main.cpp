#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#define M 1005
#define THE_MIN -9999
using namespace std;

class Node {
	public:
		int parent;
		double c; //平均权值
		int allC; //该节点集的所有节点的权重和
		int time; //该节点集涂完要多少时间 一个节点时为1
		bool vis;
		vector<int> childs;

		Node() : parent(-1), c(0), allC(0), time(1), vis(false) { }
		Node(int par, int _c) : parent(par), c(_c), allC(_c), time(1), vis(false) { }
		
		void mergeToPar(Node* arr, int n) {
			if(this->parent != -1) {
				arr[this->parent].allC += this->allC;
				arr[this->parent].time += this->time;
				this->vis = true;
				for(int i=0; i<this->childs.size(); i++) {
					arr[childs[i]].parent = this->parent;
				}
			}
		}
};

Node arr[M];

int findMax(int* arr, int n, int root) {
	int maxId = -1;
	int maxNum = THE_MIN;
	for(int i=1; i<=n; i++) {
		if(!arr[i].!vis && arr[i].c>maxNum) {
			maxNum = arr[i].c;
			maxId = i;
		}
	}
	return maxId;
}

int main(void) {

	int n, root;
	for( ; scanf("%d %d", &n, &root), n && root; ) {
		for(int i=1; i<=n; i++) { scanf("%d", &(arr[i].allC)); arr[i].c = arr[i].allC; }
		for(int i=1; i<=n-1; i++) {
			int par, chl;
			scanf("%d %d", &par, &chl);
			arr[chl].parent = par;
			arr[par].childs.push_back(par);
		}

		int maxId = -1;
		
		for( ; maxId=findMax(arr, n, root), maxId!=-1; ) {
			int par = arr[maxId].parent;
			
		}

	}

	return 0;
}
