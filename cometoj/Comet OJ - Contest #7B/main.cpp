#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define ll long long int
using namespace std;

int arr[5], idx1;

bool check(int i) {
	if(arr[(i+1)%4]==2 && arr[(i+2)%4]==3 && arr[(i+3)%4]==4) return true;
	return false;
}

bool check2(int i) {
//	if(arr[0]==3 && arr[1]==2 && arr[2]==1 && arr[3]==4) return true;
//	if(arr[0]==4 && arr[1]==3 && arr[2]==2 && arr[3]==1) return true;
//	if(arr[0]==3 && arr[1]==2 && arr[2]==1 && arr[3]==4) return true;
	if(arr[(i+1)%4]==4 && arr[(i+2)%4]==3 && arr[(i+3)%4]==2)
		return true;
	return false;
}

int main(void) {
	freopen("test", "r", stdin);
	for(int i=0; i<4; i++) {
		scanf("%d", arr+i);
		if(arr[i] == 1)
			idx1 = i;
	}
	if(check(idx1)) printf("0\n");
	else if(check2(idx1)) printf("2\n");
	else printf("1\n");
//	printf("%d\n", check(idx1));
	
	return 0;
}


