#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAXN 10005
int arr[MAXN];

int main() {
	freopen("test", "r", stdin);
	int n, a1=-1, a2=0, a3=-1;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	for(int i=0; i<n; i++) {
		if(arr[i]%3 == 0) {
			if(a1==-1) a1 = arr[i];
			else a1 = max(a1, arr[i]);
		}
	}
	double sum = 0;
	for(int i=0; i<n; i++) {
		if((arr[i]-1)%3==0) a2 ++;
	}
	int count = 0;
	for(int i=0; i<n; i++) {
		if((arr[i]-2)%3==0) sum += arr[i], count++;
	}
	if(a1==-1) printf("NONE ");
	else printf("%d ", a1);
	if(a2==0) printf("NONE ");
	else printf("%d ", a2);
	if(count!=0) printf("%.2lf", sum/(count*1.));
	else printf("NONE");
	return 0;
}

