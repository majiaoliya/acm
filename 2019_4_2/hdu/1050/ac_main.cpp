#include <iostream>
#include <string.h>
using namespace std;
/**
  * 解法简单粗暴
  */
int main(void) {

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int tn;
		cin >> tn;
		int road[202]; //一个数组模拟走廊 如果是(30->40)就把road[30/2]->road[40/2]的值加一 最后遍历找最大的X10打印
		int time = 0;
		memset(road, 0, sizeof(road));
		
		for(int k=0; k<tn; k++) {
			int s, e;
			cin >> s, cin >> e;
			int ss = (s+1)/2, ee = (e+1)/2;
			s = ss < ee ? ss : ee;
			e = ss > ee ? ss : ee;
			for(int j=s; j<=e; j++) { //把road[]区间 e->s 加一
				road[j]++;
			}
		}
		
		for(int k=0; k<202; k++) {
			if(time < road[k]) time = road[k];
		}
		cout << time*10 << endl;
	}

	return 0;
}







