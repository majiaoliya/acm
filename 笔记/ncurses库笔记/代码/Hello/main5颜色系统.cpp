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

void print_in_middle(
		WINDOW* win, int starty, int startx, int width, char* s) {
	int length, x, y;
	float tmp;
	win = win ? win : stdscr;
	getyx(win, y, x);
	x = startx, y = starty, width = 80;
	length = strlen(s);
	tmp = (width - length) / 2;
	x = startx + (int)tmp;
	mvwprintw(win, y, x, "%s", s);
	refresh();
}

int main() {
#ifdef debug
	clock_t stime = clock();
#endif
	initscr();
	if(!has_colors()) {
		endwin();
		printf("hav no color system\n");
		return 0;
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	print_in_middle(stdscr, LINES/2, 0, 0, "Viola !!! in color");
	attroff(COLOR_PAIR(1));












	refresh();
	getchar();
	endwin();








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

