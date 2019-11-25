//#include <iostream>
//#include <vector>
//#include <stack>
//#include <math.h>
//#include <map>
//#include <set>
//#include <string.h>
//#include <algorithm>
//#define MAXN 100005
//using namespace std;

//int main() { 
//	freopen("test", "r", stdin);
//	
//	int n;
//	scanf("%d", &n);
//	set<int> s1, s2, rs;
//	for(int i=0, x; i<n; i++) {
//		scanf("%d", &x);
//		s1.insert(x);
//	}
//	scanf("%d", &n);
//	for(int i=0, x; i<n; i++) {
//		scanf("%d", &x);
//		s2.insert(x);
//	}
//	set<int>::iterator it = s1.begin();
//	while(it != s1.end()) {
//		int x = *it;
//		if(s2.find(x) == s2.end())
//			rs.insert(x);
//		it ++;
//	}
//	it = s2.begin();
//	while(it != s2.end()) {
//		int x = *it;
//		if(s1.find(x) == s1.end())
//			rs.insert(x);
//		it ++;
//	}
//	it = rs.begin();
//	int c = 0;
//	while(it != rs.end()) {
//		int x = *it;
//		if(c++) printf(" ");
//		printf("%d", x);
//		it ++;
//	}
//	return 0;
//}



#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 1024
using namespace std;

int x[MAXN], y[MAXN];

int main() { 
	freopen("test", "r", stdin);
	
	int n1, n2;
	vector<int> rs;
	scanf("%d", &n1);
	for(int i=0; i<n1; i++) 
		scanf("%d", x+i);
	scanf("%d", &n2);
	for(int i=0; i<n2; i++) 
		scanf("%d", y+i);
	
	for(int i=0; i<n1; i++) {
		bool tag = true;
		for(int k=0; k<n2; k++) 
			if(x[i] == y[k]) { tag = false; break; }
		if(tag) {
			bool had = false;
			for(int k=0; k<rs.size(); k++) 
				if(rs[k] == x[i]) { had = true; break; }
			if(!had)
				rs.push_back(x[i]);
		} 
	}
	
	for(int i=0; i<n2; i++) {
		bool tag = true;
		for(int k=0; k<n1; k++) 
			if(y[i] == x[k]) { tag = false; break; }
		if(tag) {
			bool had = false;
			for(int k=0; k<rs.size(); k++) 
				if(rs[k] == y[i]) { had = true; break; }
			if(!had)
				rs.push_back(y[i]);
		} 
	}
	for(int i=0, c=0; i<rs.size(); i++) {
		if(c++) printf(" ");
		printf("%d", rs[i]);
	}
	return 0;
}



