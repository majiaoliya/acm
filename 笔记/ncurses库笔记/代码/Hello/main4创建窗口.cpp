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

WINDOW *create_newwin(int h, int w, int y, int x) {
	WINDOW* local_win = newwin(h, w, y, x);
	box(local_win, 0, 0);
//	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW* local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}

int main() {
#ifdef debug
	clock_t stime = clock();
#endif
	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	height = 3, width = 10;
	starty = (LINES-height) / 2;
	startx = (COLS-width) / 2;
	printw("Press 10 to exit\n");
	refresh();

	my_win = create_newwin(height, width, starty, startx);
	while((ch=getch()) != KEY_F(1)) {
		switch(ch) {
			case KEY_LEFT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty, --startx);
				break;
			case KEY_RIGHT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty, ++startx);
				break;
			case KEY_UP:
				destroy_win(my_win);
				my_win = create_newwin(height, width, --starty, startx);
				break;
			case KEY_DOWN:
				destroy_win(my_win);
				my_win = create_newwin(height, width, ++starty, startx);
				break;
		}
	}
	endwin();
	return 0;





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

