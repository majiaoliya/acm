#include <iostream>
#include <map>
#define MAXN 1024
using namespace std;

struct Node {
	int xishu; //系数
	int mi; //指数
	Node() : xishu(0), mi(0) { }
	bool operator < (const Node& other) const {
		return this->mi < other.mi;
	}
};

map<int, Node, greater<int>> x, y; //x多项式和y多项式
map<int, Node, greater<int>> mul, add;

void mult(map<int, Node, greater<int>>& x, map<int, Node, greater<int>>& y, map<int, Node, greater<int>>& rs) {
	for(map<int, Node>::iterator xit=x.begin(); xit!=x.end(); xit++) {
		Node& rx = xit->second;
		for(map<int, Node>::iterator yit=y.begin(); yit!=y.end(); yit++) {
			Node& ry = yit->second;
			int mi = rx.mi + ry.mi;
			rs[mi].mi = mi;
			rs[mi].xishu += (rx.xishu*ry.xishu);
		}
	}
}

void addt(map<int, Node, greater<int>>& x, map<int, Node, greater<int>>& y, map<int, Node, greater<int>>& rs) {
	
//	for(map<int, Node>::iterator xit=x.begin(); xit!=x.end(); xit++) {
//		Node& rx = xit->second;
//		rs[rx.mi] = rx;
//	}
	rs = x;
	for(map<int, Node>::iterator yit=y.begin(); yit!=y.end(); yit++) {
		Node& ry = yit->second;
		rs[ry.mi].xishu += ry.xishu;
		rs[ry.mi].mi = ry.mi;
	}
}

int main() {
	
	freopen("test", "r", stdin);
	int n;
	scanf("%d", &n);
	for( ; n--; ) {
		Node node;
		scanf("%d %d", &node.xishu, &node.mi);
		x[node.mi] = node;
	}
	scanf("%d", &n);
	for( ; n--; ) {
		Node node;
		scanf("%d %d", &node.xishu, &node.mi);
		y[node.mi] = node;
	}
	
	mult(x, y, mul);
	addt(x, y, add);
	
	int c = 0;
	if(mul.empty()) { printf("0 0\n"); }
	else {
		for(map<int, Node>::iterator it=mul.begin(); it!=mul.end(); it++) {
			if(c++) printf(" ");
			Node& tn = it->second;
			if(tn.xishu != 0)
				printf("%d %d", tn.xishu, tn.mi);
		}
	}
	printf("\n");
	c = 0;
	if(add.empty()) { printf("0 0"); }
	else {
		for(map<int, Node>::iterator it=add.begin(); it!=add.end(); it++) {
			if(c++) printf(" ");
			Node& tn = it->second;
			if(tn.xishu != 0)
				printf("%d %d", tn.xishu, tn.mi);
		}
	}
	return 0;
}
