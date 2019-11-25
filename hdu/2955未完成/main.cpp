#include <iostream>
using namespace std;

#define N 105

class Bank {
	public:
		int value;
		double cost;

		Bank() : value(0), cost(0.0) { }
		Bank(int _v, double _c) : value(_v), cost(_c) { }
		
		void operator = (Bank& other) {
			this->value = other.value, this->cost = other.cost;
		}
};

Bank arr[N];
int curMax = 0;

int bt(Bank* bs, int n, int& curM, double& curP, int curB, double& maxP) {

	if(curB > n) {
		if(curM > curMax) curMax = curM;
		return curM;
	}

	if(arr[curB].cost + curP <= maxP) { //向左
		curM += arr[curB].value, curP += arr[curB].cost;
		bt(bs, n, curM, curP, curB+1, maxP); 
		curM -= arr[curB].value, curP -= arr[curB].cost;
	}
	
	bt(bs, n, curM, curP, curB+1, maxP);

	return curM;
}

int main(void) {

	int n;
	for( cin>>n; n--; ) {
		double maxP; //不被抓的最大概率
		int count; //抢n家银行
		cin >> maxP, cin >> count;
		
		for(int i=1; i<=count; i++) {
			cin >> arr[i].value;
			cin >> arr[i].cost;
		}
		int curM = 0;

		bt((Bank*)arr, count, curM, 0.000000, 1, maxP);
		cout << curMax << endl;
	}

	return 0;
}
