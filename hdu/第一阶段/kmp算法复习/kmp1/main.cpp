#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void get_next(char p[], int nxt[], int n) {
	nxt[0] = 0;
	int len = 0;
	int i = 1;
	while(i<n) {
		if(p[i] == p[len]) {
			len ++;
			nxt[i] = len;
			i++;
		} else {
			if(len>0)
				len = nxt[len-1];
			else 
				nxt[i] = len;
		}
	}
}

int main(void) {

	char pattern[] = "ababcabaa";
	int next[9];
	int n = 9;
	get_next(pattern, next, n);
	for(int i=0; i<n; i++)
		printf("%d,", next[i]);
	return 0;
}
