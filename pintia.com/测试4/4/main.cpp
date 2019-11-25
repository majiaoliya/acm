#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#define MAXN 10005
using namespace std;

int n;

struct Node {
	string name, birth, phone;
} arr[MAXN];

int cmp(Node& x, Node& y) {
	return x.birth < y.birth;
}

int main()
{
	freopen("test", "r", stdin);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i].name >> arr[i].birth >> arr[i].phone;
	}
	sort(arr+1, arr+n+1, cmp);
	for(int i=1; i<=n; i++) 
		cout << arr[i].name << " " << arr[i].birth << " " << arr[i].phone << endl;
	return 0;
}

