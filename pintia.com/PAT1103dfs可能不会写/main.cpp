#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <set>
#define MAXN 16
using namespace std;

int n, k, p;

int arr[MAXN], rs[MAXN];

void dfs(int x, int sum) {
	if(sum > n) return ; //减掉不合适的
	if(x == n+1) { //搜索到一个结果
		
	}
}



int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d %d", &n, &k, &p);
	if()
	return 0;
}





//struct Node {
//	int val;
//	Node* next;
//	Node(int v) : val(v), next(nullptr) { }
//} ;

//struct LinkedQueue {
//	Node* front, rear;
//	int size;
//};

//void push(LinkedQueue* q, int val) { //新元素val入队列
//	Node* new_node = new Node(val);
//	q->rear->next = new_node; //原来的队尾指向新的元素的地址
//	q->rear = new_node; // 新元素设置为 尾指针
//}



























