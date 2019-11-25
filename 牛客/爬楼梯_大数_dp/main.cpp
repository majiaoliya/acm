#include <iostream>
#include <string.h>
#include <string>
using namespace std;
//盛世荷城1区13懂
#define ll long long int
#define max(x, y) ( x > y ? x : y )
struct Int {
	int n, arr[1024];
	Int() : n(0) { memset(arr, false, sizeof(arr)); }
	friend istream& operator >> (istream& in, Int& other) {
		string str;
		in >> str;
		memset(other.arr, false, sizeof(arr));
		int& on = other.n;
	   	on = str.length();
		for(int i=0, k=on-1; i<on; i++, k--)
			other.arr[i] = str[k]-'0';
		return in;
	}
	friend ostream& operator << (ostream& out, Int& other) {
		for(int i=other.n-1; i>=0; i--)
			out << other.arr[i];
		return out;
	}
	Int operator + (Int& other) {
		Int rs;
		int tmax = max(n, other.n);
		rs.n = tmax;
		for(int i=0; i<tmax+1; i++) {
			rs.arr[i] += arr[i] + other.arr[i];
			if(rs.arr[i] >= 10) rs.arr[i+1] = 1, rs.arr[i] -= 10;
		   	if(i == tmax && rs.arr[tmax]) rs.n++;
		}
		return rs;
	}
	Int& operator = (string str) {
		this->n = str.length();
		for(int i=this->n-1, k=0; i>=0; i--, k++)
			this->arr[k] = str[i] - '0';
		return *this;
	}
};

int main(void) {
	freopen("test", "r", stdin);
    int n, t;
	cin >> t;
	while(t-- && cin >> n) {
		Int dp[1005];
		dp[0] = "0", dp[1] = "1", dp[2] = "1";
		for(int i=2; i<=n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
	//		cout << dp[i] << " = " << dp[i-1] << " + " << dp[i-2] << endl;
		}
		cout << dp[n] << endl;
	}
	/**
	Int a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << a << " + " << b << " = " << c << endl;
	printf("\n");
	*/
	return 0;
}
