#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <algorithm>
#include <stack>
#define MAXN 512
#define ll long long int
using namespace std;

string num, num_lef, num_rig;

void my_sub(string& num, string& rs, int lef, int rig) {
	for(int i=lef; i<=rig; i++)
		rs += num[i];
}

int main()
{
	freopen("test", "r", stdin);
	int t;
	cin >> t;
	for( ; num="", num_lef="", num_rig="", t--; ) {
		cin >> num;
		int len = num.length();
		my_sub(num, num_lef, 0, (len-1)/2);
		my_sub(num, num_rig, (len-1)/2+1, num.length()-1);
		ll lef = stoll(num_lef), rig = stoll(num_rig);
		ll n = stoll(num);
		if(lef==0 || rig==0) printf("No\n");
		else
			printf("%s\n", (n%(lef*rig) == 0) ? "Yes" : "No");
	}
	return 0;
}

