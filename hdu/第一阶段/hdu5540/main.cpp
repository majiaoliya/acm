
#include <iostream>
#include <algorithm>
#define MAX 5005
using namespace std;

int mx[2][2];
int my[2][2];

bool equals() {
	if(mx[0][0]==my[0][0] && 
		mx[0][1]==my[0][1] && 
		mx[1][0]==my[1][0] && 
		mx[1][1]==my[1][1]
	) {
		return true;
	}
	return false;
}

void zhuan() {
	int t = my[0][0];
	my[0][0] = my[0][1];
	my[0][1] = my[1][1];
	my[1][1] = my[1][0];
	my[1][0] = t;
}

int main()
{
	freopen("test", "r", stdin);
	
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		cin >> mx[0][0] >> mx[0][1] >> mx[1][0] >> mx[1][1];
		cin >> my[0][0] >> my[0][1] >> my[1][0] >> my[1][1];
		bool ok = false;
		for(int i=0; i<4; i++) {
			ok = equals();
			if(ok) break;
			else zhuan();
		}
		printf("%s\n", ok ? "Yes" : "No");
	}
	
	return 0;
}



