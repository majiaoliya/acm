// 尺取法
#include <iostream>

using namespace std;

const int MAXN = 1e5+7;
int n, m, arr[MAXN], psum[MAXN], tmax, tmaxl, tmaxr;

#define abs(x)  ( x > 0 ? x : -x )

void slove(int tag) {
	if(tag > tmax) {
		printf("%d %d %d\n", tmax, tmaxl, tmaxr);
		return ;
	}
	int s = 0, t = 0;
	while(true) {

	}
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m) && (n+m)) {
		for(int i=0; i<n; i++) {
			scanf("%d", arr+i);
			psum[i] = psum[i-1] + arr[i];
			if(i == 0) {
				tmax = abs(arr[i]);
				tmaxl = tmaxr = i;
			} else {
				if(tmax < abs(psum[i])) {
					tmax = abs(psum[i]);
					tmaxl = 0, tmaxr = i;
				}
			}
		}
		while(true) {
			int tag;
			scanf("%d", &tag);
			slove(tag);
			char c = getchar();
			if(c == '\n') break;
		}
	}
	return 0;
}


