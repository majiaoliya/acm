/**
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 3002
using std::sort;

int arr[maxn];
bool vis[maxn];

bool cmp(int a, int b){
	return a > b;
}

int main()
{
	int n, i, j, tmp, ans;
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i)
			scanf("%d", arr + i);
		sort(arr, arr + n, cmp);
		memset(vis, 0, sizeof(vis));
		for(i = 0, ans = n; i < n; ++i){
			if(vis[i]) continue;
			tmp = arr[i];
			for(j = i + 1; j < n; ++j){
				if(vis[j]) continue;
				if(tmp > arr[j]){
					tmp = arr[j]; --ans;
					vis[j] = 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
*/


#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#define M 3005
using namespace std;

bool cmp(int x, int y) { return x > y; }

int arr[M];
bool vis[M];

int main(void) {

	int n;
	for( ; scanf("%d", &n) != EOF; ) {
		/**
		  for(int i=0; i<n; i++) cin >> arr[i];
		  如果使用cin会超时....
		*/
		for(int i=0; i<n; i++) scanf("%d", arr+i);
		sort(arr, arr+n, cmp);
		memset(vis, false, n);

		int cur, count=0;
		for(int i=0; i<n; i++) {
			if(!vis[i]) {
				vis[i] = true;
				cur = arr[i];
				count ++;
				for(int k=i+1; k<n; k++) {
					if(!vis[k] && cur>arr[k]) {
						cur = arr[k];
						vis[k] = true;
					}
				}
			}
		}

		cout << count << endl;
	}

/**

    int n, i, j, tmp, ans;
    while(scanf("%d", &n) == 1){
		int arr[n];
		int vis[n];
		for(i = 0; i < n; ++i)
            scanf("%d", arr + i);
        sort(arr, arr + n, cmp);
        memset(vis, 0, sizeof(vis));
        for(i = n-1, ans = n; i >= 0; --i){
            if(vis[i]) continue;
            tmp = arr[i];
            for(j = i-1; j>=0; j--){
                if(vis[j]) continue;
                if(tmp > arr[j]){
                    tmp = arr[j]; --ans;
                    vis[j] = 1;
                }
            }
        }
        printf("%d\n", ans);
    }
*/
	return 0;
}


