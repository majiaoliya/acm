#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 45
using namespace std;

int n, arr[MAXN], t, m;
bool vis[MAXN];

int cmp(int x, int y) { return x > y; }

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		sort(arr+1, arr+1+n, cmp);
		int maxt = max(100, arr[1]), mint = arr[n];
		printf("%d\n", (maxt-mint)*(maxt-mint));
	}
	return 0;
}

/**
#include<iostream>  
#include<algorithm>  
using namespace std;  
int main()  
{  
	freopen("test", "r", stdin);
    int T, m, n, a[45];  
    cin >> T;  
    while (T--)  
    {  
        cin >> n >> m;  
        for (int i = 0; i < n; i++)  
            cin >> a[i];  
        sort(a, a + n);  
        int sum=0;  
        sum += (100 - a[0])*(100 - a[0]);  
        cout << sum << endl;  
    }  
    return 0;  
}  
*/
