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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

#include <pthread.h>

string str = "hhh this is str;";

int arr[MAXN];

struct Node {
	ll lef, rig;
} ;

void* func(void* arg) {
	Node* ptr = (Node*) arg;
	for(ll i=ptr->lef; i<=ptr->rig; i++)
		arr[i%1024] = i;
	return &str;
}

int main() {
#ifdef debug
//	freopen("test", "w", stdout);
	clock_t stime = clock();
#endif

	pthread_t th1, th2;
	ll n = 1024*1024*1024*(ll)10;

#define use_thread_16
#ifdef use_thread_16
#define MX 32
	Node node[MX];
	ll block = n / MX;
	for(ll i=0; i<MX; i++)
		node[i].lef = i*block, node[i].rig = (i+1)*block;
	pthread_t th[MX] = { 0 };
	for(ll i=0; i<MX; i++)
		pthread_create(th+i, NULL, func, node+i);
	for(ll i=0; i<MX; i++)
		pthread_join(th[i], NULL);
	clock_t etime_ = clock();
	printf("rum time: %lf 秒\n",(double) (etime_-stime)/CLOCKS_PER_SEC);
	return 0;
#endif


#define use_thread
#ifdef use_thread
	Node a = { 1, n/2};
	Node b = { 1025, n};
	pthread_create(&th1, NULL, func, &a);
	pthread_create(&th2, NULL, func, &b);

	void* ptr = 0;
	pthread_join(th1, &ptr);
	pthread_join(th2, NULL);
//	printf("%s\n", ((string*)ptr)->data());
#else 
	for(ll i=1; i<=n; i++) arr[i%1024] = i;
#endif
//	forarr(arr, 1, n);

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

