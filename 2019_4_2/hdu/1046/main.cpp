#include <iostream>
using namespace std;

int main(void) {

	int l, u, d;
	for(int i=0; cin>>l, cin>>u, cin>>d, l||u||d; i++) {
		int rs = -1; 
		int now = d;
		while(now < l) {
			now -= d; //下滑
			rs += 1; //休息一分钟
			rs += 1; //向上爬一分钟
			now += u; //u英寸
		}
		cout << rs << endl;
	}

	return 0;
}
