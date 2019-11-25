#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 4096
using namespace std;

struct User {
	int time, rs_time;
} arr[MAXN];

int n, m, k, q;

int cur_time[MAXN];
queue<User*> win[MAXN];
queue<User*> out_line;

void dsp() {
	for(int i=1; i<=n; i++) {
		for(; !win[i].empty(); win[i].pop()) {
			printf("%d->", win[i].front()->time);
		}
		printf("\n");
	}
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i=1; i<=k; i++) {
		scanf("%d", &arr[i].time);
		out_line.push(arr+i);
	}	
	
	int count = n*m;
	for( ; !out_line.empty(); ) {
		if(count == 0) break;
		for(int i=1; i<=n; i++) {
			if(win[i].size()<m && !out_line.empty()) {
				win[i].push(out_line.front());
				out_line.pop();
				count --;
			}
		}
	}
	int cnt = 0;
	while(cnt < k) {
		int min = 999999999;
		for(int i=1; i<=n; i++) 
			if(!win[i].empty() && min>win[i].front()->time)
				min = win[i].front()->time;
		for(int i=1; i<=n; i++) {
			cur_time[i] += min; //过去了min分钟
			if(win[i].empty()) continue ;
			User* u = win[i].front();
			u->time -= min;
			if(u->time == 0) { //这个窗口的人结束任务
				cnt ++;
				u->rs_time = cur_time[i];
				win[i].pop();
				if(!out_line.empty()) 
					win[i].push(out_line.front()), out_line.pop();
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int x;
		scanf("%d", &x);
		int t = arr[x].rs_time;
		if(t > 540) printf("Sorry\n");
		else {
			int hh = 8, mm = 0;
			hh += t/60;
			mm += t%60;
			printf("%02d:%02d\n", hh, mm);
		}
	}
	return 0;
}
























