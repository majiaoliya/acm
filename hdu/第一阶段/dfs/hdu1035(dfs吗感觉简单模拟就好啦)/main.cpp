#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#define MAXN 30
using namespace std;

int r, c, m;

char mtx[MAXN][MAXN];
int step[MAXN][MAXN];

//int w[] = {-1, 0}, s[] = {0, 1}, e[] = {1, 0}, n[] = {0, -1};
int w[] = {0, -1}, s[] = {1, 0}, e[] = {0, 1}, n[] = {-1, 0};

int main()
{
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d %d", &r, &c), (r+c); ) {
		scanf("%d", &m);
		memset(step, false, sizeof(step));
		for(int i=1; i<=r; i++) 
			scanf("%s", mtx[i]+1);
		int cur_row = 1, cur_col = m, cur_step = 1;
		for( ; true; ) {
			if(cur_row<1 || cur_row>r || cur_col<1 || cur_col>c) {
				printf("%d step(s) to exit\n", cur_step-1);
				break;
			} else if(step[cur_row][cur_col] == 0) {
				step[cur_row][cur_col] = cur_step ++;
				if(mtx[cur_row][cur_col] == 'W')
					cur_row+=w[0], cur_col+=w[1];
				else if(mtx[cur_row][cur_col] == 'S')
					cur_row+=s[0], cur_col+=s[1];
				else if(mtx[cur_row][cur_col] == 'E')
					cur_row+=e[0], cur_col+=e[1];
				else if(mtx[cur_row][cur_col] == 'N')
					cur_row+=n[0], cur_col+=n[1];
			} else if(step[cur_row][cur_col] != 0) { //出现循环
				printf("%d step(s) before a loop of %d step(s)\n", 
					step[cur_row][cur_col]-1, cur_step-step[cur_row][cur_col]);
					break;
			}
		}
	}
	
	return 0;
}

