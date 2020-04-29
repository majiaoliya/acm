#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


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

void* func(void* arg) {
	for(int i=0; i<1024; i++)
		printf("%s\n", arg);
	return &str;
}

int main() {
#ifdef debug
//	freopen("test", "w", stdout);
	clock_t stime = clock();
#endif

	pthread_t th1, th2;
	pthread_create(&th1, NULL, func, (void*)"thread 1");
	pthread_create(&th2, NULL, func, (void*)"thread 2");

	void* ptr = 0;
	pthread_join(th1, &ptr);
	pthread_join(th2, NULL);
	printf("%s\n", ((string*)ptr)->data());


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

