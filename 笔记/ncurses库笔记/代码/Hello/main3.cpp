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
/* i like eat shit */

#include <ncurses.h>

using namespace std;


int main() {
#ifdef debug
	clock_t stime = clock();
#endif

	FILE* fp = fopen("./main3.cpp", "r");
	int goto_prev = false, x, y;

	int ch, prev;
	initscr();

	prev = EOF;
	while((ch=fgetc(fp)) != EOF) {
		if(prev=='/' && ch=='*') {
			attron(A_BOLD);
			goto_prev = TRUE;
		}
		if(goto_prev) {
			getyx(stdscr, y, x);
			move(y, x-1);
			printw("%c%c", '/', ch);
			ch = 'a';
			goto_prev = false;
		} else
		   	printw("%c", ch);
		if(prev=='*' && ch=='/')
			attroff(A_BOLD);
		refresh();
	}

	refresh();
	getchar();
	endwin();








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

