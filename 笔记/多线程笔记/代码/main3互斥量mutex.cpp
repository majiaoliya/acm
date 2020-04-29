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

int sum = 0;
pthread_mutex_t lock;

void* myfunc(void* arg) {
	int i = 0;
#define use_mutex
#ifdef use_mutex
	pthread_mutex_lock(&lock);
	for( ; i<1000000; i++) {
		sum ++;
	}
	pthread_mutex_unlock(&lock);
#else 
	for( ; i<1000000; i++) {
		sum ++;
	}
#endif
	return 0;
}

int main() {
#ifdef debug
//	freopen("test", "w", stdout);
	clock_t stime = clock();
#endif
	pthread_t th1, th2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&th1, NULL, myfunc, NULL);
	pthread_create(&th2, NULL, myfunc, NULL);
	
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	printf("%d\n", sum);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

