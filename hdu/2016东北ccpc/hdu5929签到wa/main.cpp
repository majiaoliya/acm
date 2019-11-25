#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long int
#define REVERSE { neg = !neg; }
using namespace std;

const int MAXN = 400005;

int t, n, size;
bool arr[MAXN], neg;
int lef, rig, nand;

void init() {
	size = 0;
	neg = false; //初始化为正序
	lef = rig = (MAXN>>1);
}

void push(int x) {
	if(size == 0) nand = x;
	else {
		if(nand == 0 && x == 0) nand = 1;
		if(nand == 0 && x == 1) nand = 1;
		if(nand == 1 && x == 0) nand = 1;
		if(nand == 1 && x == 1) nand = 0;
	}
	if(!neg) //正序
		arr[++rig];
	else  //倒序
		arr[--lef];
	size ++;
}

void pop() {
	if(size == 0) {
		return ;
	}
	int x;
	if(!neg) { //正序
		x = arr[rig];
		rig --;
	} else { //倒序
		x = arr[lef];
		lef --;
	}
	if(nand == 0 && x == 0) nand = 1;
	if(nand == 0 && x == 1) nand = 1;
	if(nand == 1 && x == 0) nand = 1;
	if(nand == 1 && x == 1) nand = 0;
	size --;
}

void query() {
	if(size == 0) { printf("Invalid.\n"); return; }
	printf("%d\n", nand);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	char cmd[16];
	for(int i=1, x; i<=t; i++) {
		printf("Case #%d:\n", i);
		init();
		scanf("%d", &n);
		while(n--) {
			scanf("%s", cmd);
			switch(cmd[2]) {
				case 'S': //push
					scanf("%d", &x);
					push(x);
					break;
				case 'P': //pop
					pop();
					break;
				case 'V': //reverse
					REVERSE;
					break;
				case 'E': //query
					query();
					break;
			}
		}
	}
	return 0;
}
