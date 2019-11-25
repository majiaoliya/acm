#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#define MAXN 512
using namespace std;

int arr[MAXN];
bool vis[MAXN];
int n;

int main()
{
	freopen("test", "r", stdin);
	
	vector<int> num;
	for(int i=0; i<10; i++) {
		int x;
		scanf("%d", &x);
		for(int k=0; k<x; k++)  
			num.push_back(i);
	}
	
	sort(num.begin(), num.end());
	for(int i=0; i<num.size(); i++)
		if(num[i] != 0) {
			printf("%d", num[i]);
			num.erase(num.begin()+i);
			break;
		}
	for(int i=0; i<num.size(); i++)
		printf("%d", num[i]);
//	int t, min;
//	for( ; cin>>t; ) {
//		arr[n] = t;
//		printf("[%d]", arr[n]);
//		n ++;
//	}
//	sort(arr, arr+n);
//	for(int i=0; i<n; i++) 
//		if(arr[i] != 0) {
//			printf("%d", arr[i]);
//			vis[i] = true;
//			break;
//		}
//	for(int i=0; i<n; i++) {
//		if(vis[i]) continue ;
//		printf("%d", arr[i]);
//	}
	
	return 0;
}

