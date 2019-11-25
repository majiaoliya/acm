#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#define MAXN 512
using namespace std;

//set<int> s1, s2, s3;

int main()
{
	freopen("test", "r", stdin);
	int cnt = 0, x;
	
	set<int>* s1 = new set<int>(), *s2 = new set<int>(), *s3 = new set<int>();
	
	for( ; scanf("%d", &x); ) {
		if(x == -1) cnt ++;
		if(cnt == 2) break;
		if(cnt == 0) { //第一个序列
			s1->insert(x);
		} else { //第二个序列
			if(s1->find(x) != s1->end()) 
				s3->insert(x);
		}
	}
	
	if(s3->empty()) {
		printf("NULL\n");
		return 0;
	}
	
	set<int>::iterator it = s3->begin();
	int c = 0;
	while(it != s3->end()) {
		if(c++) printf(" ");
		printf("%d", *it);
		it ++;
	}
	
	return 0;
}

