#include <iostream>
#include <queue>
using namespace std;

int inf = 2147483647;
queue<int> q1, q2;

int main() {
	freopen("test", "r", stdin);
	
	int n1, n2;
	scanf("%d", &n1);
	for(int i=0; i<n1; i++) {
		int x;
		scanf("%d", &x);
		q1.push(x);
	}
	scanf("%d", &n2);
	if((n1+n2) == 0) return 0; //两个序列都空 
	// n1={ 2, 3 }   n2={ 1 }
	// rs = 2
//	if(n2==0) q2.push(inf); //n1序列比n2长的时候报错
//	else {					//删掉后就第6个点过了 
//		int x;
//		scanf("%d", &x);
//		q2.push(x);
//	}
	
	int cnt = 0, mid = (n1+n2+1) >> 1, rs = min(q1.front(), q2.front());
	while(true) {
		if(mid == cnt) {
			printf("%d\n", rs);
			break;
		}
		if(q1.empty()) q1.push(inf);
		if(q2.empty()) {
			if(n2) {
				int x;
				scanf("%d", &x);
				q2.push(x);
				n2 --;
			} else {
				q2.push(inf);
			}
		}
		if(q1.front() < q2.front()) {
			rs = q1.front();
			q1.pop();
		} else {
			rs = q2.front();
			q2.pop();
		}
		cnt ++;
	}
	
	return 0;
}
