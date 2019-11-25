#include <iostream>
#include <string.h>
using namespace std;

int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	freopen("test", "r", stdin);
	
	int year, mon, num;
	for( ; EOF != scanf("%d %d %d", &year, &mon, &num); ) {
		string y = to_string(year);
		string m = mon < 10 ? ("0"+to_string(mon)) : to_string(mon);
		if(year%4||year%400) arr[2] = 29;
		else arr[2] = 28;
		int tnum = 1, count = 0;
		while(tnum <= arr[mon]) {
			string tnum_str = tnum<10 ? ("0"+to_string(tnum)) : to_string(tnum);
			printf("%s-%s-%s\n", y.data(), m.data(), tnum_str.data());
			for(int i=0; i<y.length(); i++) 
				if(y[i]==(num+'0')) count ++;
			for(int i=0; i<m.length(); i++) 
				if(m[i]==(num+'0')) count ++;
			for(int i=0; i<tnum_str.length(); i++) 
				if(tnum_str[i]==(num+'0')) count ++;
			tnum += 1;
		}
		printf("%d\n", count);
	}
	
	return 0;
}
