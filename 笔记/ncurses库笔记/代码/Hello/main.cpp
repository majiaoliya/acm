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


#include <ncurses.h>

using namespace std;


int main() {
#ifdef debug
	clock_t stime = clock();
#endif
	initscr();
	printw("Hello world!!!\n\n", 100, 100);
	refresh();
	getchar();
	endwin();








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

