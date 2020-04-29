#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif
#include <unistd.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <stdlib.h>
#define MAXN ((int)1e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

#include <pthread.h>

/**
 * 给定一个很大的数组arr[],用两个线程th1,th2
 * 用th1求前半部分的和
 * 用th2求后半部分的和
 * 输出总和sum
 */

int arr[MAXN];
int n = 1e6;

struct Node {
	int L, R, sum;
} ;

void* myfunc(void* arg) {
	Node* ptr = (Node*) arg;
	for(int i=ptr->L; i<=ptr->R; i++)
		ptr->sum += arr[i];
	return 0;
}

int main() {
#ifdef debug
//	freopen("test", "w", stdout);
	clock_t stime = clock();
#endif

	for(int i=1; i<=n; i++) arr[i] = rand() % 5;

	pthread_t th1, th2;
	Node node[2];
	node[0].L = 1, node[0].R = n>>1, node[0].sum = 0;
	node[1].L = (n>>1)+1, node[1].R = n, node[1].sum = 0;

	pthread_create(&th1, NULL, myfunc, node);
	pthread_create(&th2, NULL, myfunc, node+1);
	
	int sum = 0;
	for(int i=1; i<=n; i++) sum += arr[i];
	
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	
	printf("thread:%d\nmain:%d\n", node[0].sum+node[1].sum, sum);

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

