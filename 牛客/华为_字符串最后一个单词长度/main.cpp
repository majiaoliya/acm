#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <unordered_set>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define min(x, y) ( x < y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

string str;

int main() {
	freopen("test", "r", stdin);
	std::getline(cin, str);
	int cnt = 0;
	for(int i=str.length()-1; i>=0; i--) {
		if(str[i] == ' ') break;
		cnt ++;
	}
	printf("%d\n", cnt);
	return 0;
}



