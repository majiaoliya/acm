/** 
#include <iostream>
#include <string.h>
#define MAXN 25
using namespace std;
int sum = 0; //周长

int arr[MAXN];
bool vis[MAXN];
int count = 0;
bool is_find = false;

void dfs(int i, int n, int cur_value) {
	if(i > n || is_find) return; 
	if(cur_value == sum/4) { count ++; } //找到一条新边
	if(count == 4) {
//		printf("find\n");
		is_find = true;
		return ;
	}
	if(!vis[i] && !is_find) {
		int t = cur_value + arr[i];
		vis[i] = true;
		if(cur_value <= sum/4) {
			dfs(i+1, n, t); //向左
		}
		vis[i] = false;
		dfs(i+1, n, cur_value); //向右
	} 
}

int main(void) {
	freopen("test", "r", stdin);
	
	int t;
	scanf("%d", &t);
		
	for( ; t--; ) {
		int n;
		scanf("%d", &n);
		sum = 0, count = 0, is_find = false;
		memset(vis, false, n);
		for(int i=0; i<n; i++) {
			scanf("%d", arr+i);
			sum += arr[i];
		}
		
		if(sum%4 != 0) //周长不是4的倍数
			is_find = false;
		else 
			dfs(0, n, 0);
		printf("%s\n", is_find ? "yes" : "no");
		
	}
	return 0;
}
*/








/**
#include <iostream>
#include <string.h>
#define MAXN 25
using namespace std;
int sum = 0; //周长

int arr[MAXN];
bool vis[MAXN];
int count = 0;
bool is_find = false;

void dfs(int i, int n, int& cur_len) {
	
	
	
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
		
	for( ; t--; ) {
		int n;
		scanf("%d", &n);
		sum = 0, count = 0, is_find = false;
		memset(vis, false, n);
		for(int i=0; i<n; i++) {
			scanf("%d", arr+i);
			sum += arr[i];
		}
		int cur_len = 0;
		if(sum%4 != 0)
			is_find = false;
		else 
			dfs(0, n, cur_len);
		printf("%s\n", is_find ? "yes" : "no");
	}
	return 0;
}
*/










#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 25
using namespace std;

int arr[MAXN]; 
bool vis[MAXN];
int edge = 0, sum = 0;
int cnt = 0;
bool is_find = false; 

void dfs(int i, int cur_len) {
	if(i<0) return;
	if(cnt == 4) {
		is_find = true;
		return ;
	}
	if(cur_len == edge) {
		cnt ++;
		return ;
	}
	if((cur_len + arr[i]) == edge) {
		cnt ++;
	} else if((cur_len+arr[i] < edge)) {
		vis[i] = true;
		for(int k=i; k>=0; k--) {
			if(!vis[k])
				dfs(k, cur_len+arr[i]);
		}
		vis[i] = false;
	}
}

int main()
{
	freopen("test", "r", stdin);
    int t;
    scanf("%d", &t);
    for( ; t--; ) {
    	int n;
    	edge = 0, cnt = 0, sum = 0, is_find = false;
    	scanf("%d", &n);
    	for(int i=0; i<n; i++) {
    		scanf("%d", arr+i);
    		sum += arr[i];
    	}
    	if(sum%4 != 0) is_find = false;
    	else {
    		edge = sum / 4;
    		dfs(n-1, 0);
    	}
    	printf("%s\n", is_find ? "yes":"no");
    }
 
    return 0;
}







