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
	int ch;
	initscr();
	raw();

	keypad(stdscr, TRUE);
	noecho();
	printw("type any char to see it in bold\n");
	while((ch=getch()) != '!') {
		if(ch == KEY_F(1))
			printw("F1 pressed\n", 0, 0);
		else {
#ifdef test
			printw("The pressed key is ");
#endif
			attron(A_BOLD);
			printw("%c", ch);
			attroff(A_BOLD);
		}
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

