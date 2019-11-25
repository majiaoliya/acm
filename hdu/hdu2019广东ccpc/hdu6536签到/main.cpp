//超时O(n*m)
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;

//int main(void) {
//	freopen("test", "r", stdin);
//	ios::sync_with_stdio(false);
//	
//	int len;
//	string str, p = "xtCpc";
//	for( ; cin>>len>>str; ) {
//		int rs = 0;
//		for(int i=0; i<len; i++) {
//			if(!str[i] || str[i]!='x') continue; 
//			int idx = 1;
//			for(int k=i+1; k<len; k++) {
//				if(str[k]==p[idx]) 
//					idx ++, str[k] = 0;
//			}
//			if(idx == 5)
//				rs ++;
//		}
//		printf("%d\n", rs);
//	}
//	
//	return 0;
//}

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	ios::sync_with_stdio(false);
	
	int len;
	string str, p = "xtCpc";
	for( ; cin>>len>>str; ) {
		if(len == 0) {
			printf("0\n");
			continue;
		}
		int a=false, b=false, c=false, d=false, e=false, rs = false;
		for(int i=0; i<len; i++) {
			if(str[i]=='x') a++;
			else if(str[i]=='t' && b<a) b++;
			else if(str[i]=='C' && c<b) c++;
			else if(str[i]=='p' && d<c) d++;
			else if(str[i]=='c' && e<d) e++;
			if(a && b && c && d && e) {
				rs ++;
				a--, b--, c--, d--, e--;
			}
		}
		printf("%d\n", rs);
	}
	
	return 0;
}
