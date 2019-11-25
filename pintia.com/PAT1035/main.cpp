#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024

using namespace std;

int n;
struct User {
	char name[64], password[64];
} arr[MAXN];

bool vis[MAXN];

int main()
{
    freopen("test", "r", stdin); 
    for( ; EOF != scanf("%d", &n); ) {
    	memset(vis, false, n+10);
    	int count = 0;
    	for(int i=0; i<n; i++) {
    		scanf("%s %s", arr[i].name, arr[i].password);
    		bool tag = false;
    		for(int k=0; arr[i].password[k]; k++) {
    			char& c = arr[i].password[k];
    			if(c == 'l') { c = 'L'; tag = true; }
    			else if(c == '0') { c = '%'; tag = true; }
    			else if(c == '1') { c = '@'; tag = true; }
    			else if(c == 'O') { c = 'o'; tag = true; }
    		}
    		if(tag) count ++, vis[i] = true;
    	}
    	if(!count)
    		if(n==1)
    			printf("There is %d account and no account is modified\n", n);
    		else
    			printf("There are %d accounts and no account is modified\n", n);
    	else {
    		printf("%d\n", count);
    		for(int i=0; i<n; i++)
    			if(vis[i]) {
    				printf("%s %s\n", arr[i].name, arr[i].password);
    			}
    	}
    }
    return 0;
}

