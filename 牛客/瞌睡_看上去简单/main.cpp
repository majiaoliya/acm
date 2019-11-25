#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#define MAXN 100005

using namespace std;

int n, m, arr[MAXN], sum, vis[MAXN], psum[MAXN];

int main() {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d %d", &n, &m)) {
		memset(psum, false, sizeof(psum));
		for(int i=1; i<=n; i++) 
			scanf("%d", arr+i);
		sum = 0;
		for(int i=1, tag; i<=n; i++) {
			scanf("%d", &tag);
			vis[i] = tag;
			if(tag) sum += arr[i];
			psum[i] = tag == 0 ? psum[i-1] + arr[i] : psum[i-1];
		}
		int rs = sum;
#ifdef debug
		for(int i=1; i<=n; i++)
			printf("%d ", psum[i]);
		printf("\n");
#endif
		for(int i=1; i<=n; i++) {
			int temp = sum;
			if(!vis[i]) {
				/** 这里的O(n)太费时, 改用前缀和优化
				for(int k=i, cnt=1; k<=n && cnt<=m; k++, cnt++)
					if(!vis[k]) temp += arr[k];
				*/
				{ //反而WA了 wdnmd cnmlgcb ??!
					int lef = psum[i-1], rig = (i+m-1) <= n ? psum[i+m-1] : psum[n];
					temp += (rig - lef);
				}
			}
			rs = max(temp, rs);
//			printf("%d 从%d叫醒 get %d\n", sum, i, rs);
		}
		printf("%d\n", rs);
	}
	
	return 0;
}

