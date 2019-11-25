#include <bits/stdc++.h>
#define random(x) (rand()%x)
using namespace std;

int main(void) {
	freopen("test", "w", stdout);
	srand(time(0));
	
	int n = random(20), m = random(20);
	cout << n << " " << m << endl;
	for(int i=1; i<=n; i++) {
		int x = random(30), y = random(30);
		cout << x << " " << y << endl;
	}
	for(int i=1; i<=m; i++) {
		cout << random(100) << " ";
	}
	
	/**
	int t = 10;
	while(t--) {
		int n = random(20);
		cout << n << endl;
		int arr[n];
		for(int i=0; i<n; i++) 
			arr[i] = random(100);
		sort(arr, arr+n);
		for(int i=0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	*/
	return 0;
}
