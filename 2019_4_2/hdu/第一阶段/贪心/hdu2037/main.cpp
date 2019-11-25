#include <iostream>
#include <algorithm>
#include <string.h>
#define M 9999999
using namespace std;

/**
  * 按结束end时间升序排序
  */
class Tv {
	public :
		int start, end;
		
		Tv() : start(0), end(0) { }
		Tv(int s, int e) : start(s), end(e) { }
		bool operator < (Tv& other) { return this->end < other.end; }
		bool operator > (Tv& other) { return this->end > other.end; }
		bool operator == (Tv& other) { return this->end == other.end; }

};

Tv tv[105];

int main(void) {

	for(int n; scanf("%d", &n), n; ) {
		for(int i=0; i<n; i++) scanf("%d %d", &(tv[i].start), &(tv[i].end));
		std::sort(tv, tv+n);
		int count = 1;
		int lastEnd = tv[0].end;
		for(int i=1; i<n; i++) {
			if(tv[i].start >= lastEnd) { //排好序的下一个节目的start大于等于上一个的end就可以看
				count ++;
				lastEnd = tv[i].end;
			}
		}
		printf("%d\n", count);
	}
	
	return 0;
}
