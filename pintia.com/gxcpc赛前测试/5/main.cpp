#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	string num;
	cin>>num;
	int sum = 0;
	string rs;
	for(int i=0; i<num.length(); i++) {
		if(num[i]>='0' && num[i]<='9')
			rs += num[i];
	}
	if(!rs.empty())
		printf("%d\n", atoi(rs.data()));
//	bool tag = false;
//	for(int i=0; i<rs.length(); i++) {
//		if(rs[i]!='0') tag = true;
//		if(tag)
//			printf("%c", rs[i]);
//	}
	return 0;
}

