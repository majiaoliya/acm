#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class Int {
	public:
		friend ostream& operator<<(ostream& out, Int i) {
			vector<int>::const_iterator b = i.inte.begin();
			if(i.isPos) out << '-';
			for( ; b!=i.inte.end(); b++) {
				out << *b;
			}
			return out;
		}

	public :
		vector<int> inte;
		bool isPos; 

		Int() {

		}

		Int(string str) : isPos(false) {
			int i = 0;
			if(str[0] == '-') {
				i = 1;
				this->isPos = true;
			}
			for( ; i<str.size(); i++) {
				inte.push_back(str[i] - '0');
			}
		}
		
		Int(bool isPos, vector<int> _inte) {
			for(int i=0; i<_inte.size(); i++) {
				if(_inte[i] >= 0 && _inte[i] <= 9) {
					this->inte.push_back(_inte[i]);
				} else {
					cout << " error about Int() i:" << i << " _inte[i]: " << _inte[i] << endl;
					int x;
					cin >> x;
				}
			}
			this->isPos = isPos;
		}

		Int abs() {
			Int ret = (*this);
			ret.isPos = false;
/**
			for(vector<int>::iterator iter=inte.begin(); iter!=inte.end(); iter++) {
				ret.inte.push_back(*iter);
			}
*/
			return ret;
		}

		Int abs(Int i) { //return the abs about i
			Int ret = i;
			ret.isPos = false;
/**
			for(vector<int>::iterator iter=inte.begin(); iter!=inte.end(); iter++) {
				ret.inte.push_back(*iter);
			}
*/
			return ret;
		}

		Int operator + (Int other) {
			Int ret;
			int n1 = inte.size();
			int n2 = other.inte.size();
			int len = n1 > n2 ? n1+2 : n2+2;
			int big[len], small[len], rs[len];
			
			for(int i=0; i<len; i++) {
				big[i] = small[i] = rs[i] = 0;
			}

			if(n1 > n2) {
				for(int i=len-1, nn1=n1-1, nn2=n2-1; i>=0; i--, nn1--, nn2--) {
					if(nn1 >= 0) big[i] = this->inte[nn1];
					if(nn2 >= 0) small[i] = other.inte[nn2];
				}
			} else if(n1 < n2) {
				for(int i=len-1, nn1=n1-1, nn2=n2-1; i>=0; i--, nn1--, nn2--) {
					if(nn1 >= 0) small[i] = this->inte[nn1];
					if(nn2 >= 0) big[i] = other.inte[nn2];
				}
			} else if(n1 == n2) {
				int tag = 0;
				for(int i=len-1, nn1=n1-1, nn2=n2-1; i>=0; i--, nn1--, nn2--) {
					if(inte[nn1] > other.inte[nn2]) { //this大
						tag = 1; break;
					} else if(inte[nn1] < other.inte[nn2]) { //this小
						tag = -1; break;
					} else if(inte[nn1] == other.inte[nn2]) { //相等
						tag = 0;
					}
				}
				switch(tag) {
					case 1 :
						for(int i=len-1, nn1=n1-1, nn2=n2-1; i>=0; i--, nn1--, nn2--) {
							if(nn1 >= 0) big[i] = this->inte[nn1];
							if(nn2 >= 0) small[i] = other.inte[nn2];
						}
						break;
					case -1 :
						for(int i=len-1, nn1=n1-1, nn2=n2-1; i>=0; i--, nn1--, nn2--) {
							if(nn1 >= 0) small[i] = this->inte[nn1];
							if(nn2 >= 0) big[i] = other.inte[nn2];
						}
						break;
					case 0 :
						for(int i=len-1, nn1=n1-1, nn2=n2-1; i>=0; i--, nn1--, nn2--) {
							if(nn1 >= 0) small[i] = this->inte[nn1];
							if(nn2 >= 0) big[i] = other.inte[nn2];
						}
						break;
				}
			}

			char bit = 0;
			if(this->isPos && other.isPos) { //负数 + 负数
				ret.isPos = true;
				for(int i=len-1; i>=0; i--) {
					big[i] += bit;
					int t_rs = big[i] + small[i];
					if(t_rs >= 10) {
						bit = 1;
						rs[i] = t_rs - 10;
					} else {
						bit = 0;
						rs[i] = t_rs;
					}
				}
			} else if(!this->isPos && !other.isPos) { //正数 + 正数
				ret.isPos = false;
				for(int i=len-1; i>=0; i--) {
					big[i] += bit;
					int t_rs = big[i] + small[i];
					if(t_rs >= 10) {
						bit = 1;
						rs[i] = t_rs - 10;
					} else {
						bit = 0;
						rs[i] = t_rs;
					}
				}
	
			} else if(!this->isPos && other.isPos) { //正数 + 负数
				if(this->abs() > other.abs()) //this的绝对值大
					ret.isPos = false;
				else if(this->abs() < other.abs()) //other的绝对值大
					ret.isPos = true;
				for(int r1=len-1; r1>=0; r1--) {
					big[r1] -= bit;
					if(big[r1] < small[r1]) {
						bit = 1;
						rs[r1] = big[r1] + 10 - small[r1];
					} else {
						bit = 0;
						rs[r1] = big[r1] - small[r1];
					}
				}

			} else if(this->isPos && !other.isPos) { //负数 + 正数
				if(this->abs() > other.abs()) //this的绝对值大
					ret.isPos = true;
				else if(this->abs() < other.abs()) //other的绝对值大
					ret.isPos = false;
				for(int r1=len-1; r1>=0; r1--) {
					big[r1] -= bit;
					if(big[r1] < small[r1]) {
						bit = 1;
						rs[r1] = big[r1] + 10 - small[r1];
					} else {
						bit = 0;
						rs[r1] = big[r1] - small[r1];
					}
				}
			}

			bool b = false;
			for(int i=0; i<len; i++) {
				if(rs[i] != 0) b = true;
				if(b) ret.inte.push_back(rs[i]);
			}

			if(ret.inte.size() <= 0) ret.inte.push_back(0);
			
			return ret;
		}

		Int operator - (Int other) {
			int n1 = this->inte.size();
			int n2 = other.inte.size();
			int len = n1 > n2 ? n1+2 : n2+2;
			int temp[len];
			int rs[len];
			int big[len];
			int small[len];
			int r = len - 1;
			int t = len - 1;
			Int ret;

			for(int i=len-1; i>=0; i--) {
				temp[i] = rs[i] = big[i] = small[i] = 0;
			}
			
			char tag = (*this) > other ? 1 : (*this) < other ? -1 : 0;
			for(int i=len-1, nn1=n1-1, nn2=n2-1; i>=0; i--, nn1--, nn2--) { //初始化big[]和small[]
				switch(tag) {
					case 1 :
						ret.isPos = false;
						if(nn1 >= 0) big[i] = this->inte[nn1];
						if(nn2 >= 0) small[i] = other.inte[nn2];
						break;
					case -1 :
						ret.isPos = true;
						if(nn1 >= 0) small[i] = this->inte[nn1];
						if(nn2 >= 0) big[i] = other.inte[nn2];
						break; 
					case 0 :
						ret.isPos = false;
						small[i] = big[i] = this->inte[nn1];
						break;
				}
			}

			if(!this->isPos && !other.isPos) { // 正数 - 正数
/**
				cout << "big[] ";
				for(int i=0; i<len; i++) cout << big[i] << ",";
				cout << endl;
				cout << "small[] ";
				for(int i=0; i<len; i++) cout << small[i] << ",";
co << endl;
*/
				char bit = 0; //标志退位
				for(int i=len-1; i>=0; i--) {
					big[i] -= bit;
					if(big[i] < small[i]) {
						bit = 1;
						rs[i] = big[i] + 10 - small[i];
					} else {
						bit = 0;
						rs[i] = big[i] - small[i];
					}
				}
			
			} else if(this->isPos && !other.isPos) { //负数 - 正数
				ret.isPos = true;
				char bit = 0;
				for(int i=len-1; i>=0; i--) {
					big[i] += bit;
					int t_rs = big[i] + small[i];
					if(t_rs >= 10) {
						bit = 1;
						rs[i] = t_rs - 10;
					} else {
						bit = 0;
						rs[i] = t_rs;
					}
				}
		
			} else if(!this->isPos && other.isPos) { //正数 - 负数
//				ret = (*this) + other.abs(); //偷懒
				ret.isPos = false;
				char bit = 0;
				for(int i=len-1; i>=0; i--) {
					big[i] += bit;
					int t_rs = big[i] + small[i];
					if(t_rs >= 10) {
						bit = 1;
						rs[i] = t_rs - 10;
					} else {
						bit = 0;
						rs[i] = t_rs;
					}
				}
			
			} else if(this->isPos && other.isPos) { //负数 - 负数
				Int a = this->abs() - other.abs();
				Int absT = this->abs(); 
				Int absO = other.abs();
//				cout << (*this) << " abs: " << absT << ", " << other << " abs:" << absO << " sub: " << a << endl;
				if(!a.isPos)
				  ret.isPos = true;
				else if(a.isPos)
				  ret.isPos = false;
				for(int i=len-1, na=a.inte.size()-1; i>=0 && na>=0; i--, na--) {
					rs[i] = a.inte[na];
				}
/**
				cout << "负数 - 负数 rs[] : ";
				for(int i=0; i<len; i++) 
					cout << rs[i] << ",";
				cout << endl;
*/
			}
/**
			cout << "big[] ";
			for(int i=0; i<len; i++) cout << big[i] << ",";
			cout << endl;
			cout << "small[] ";
			for(int i=0; i<len; i++) cout << small[i] << ",";
			cout << endl;
			cout << "rs[] ";
			for(int i=0; i<len; i++) cout << rs[i] << ",";
*/
			bool b = false;
			for(int i=0; i<len; i++) {
				if(rs[i] != 0) b = true;
				if(b) ret.inte.push_back(rs[i]);
			}
//			cout << "ret = " << ret << endl;
			if(ret.inte.size() <= 0) ret.inte.push_back(0);

			return ret;
		}

		bool operator > (Int other) {
			bool ret = false;

			do {
				int n1 = inte.size();
				int n2 = other.inte.size();

				if(this->isPos && other.isPos) {
					if(n1 > n2) {
						ret = false; break;
					} else if(n1 < n2) { 
						ret = true; break;
					} else if(n1 == n2) {
						for(int i=0; i<n1; i++) {
							if(inte[i] > other.inte[i]) 
							  break;
							else if(inte[i] < other.inte[i]) {
								ret = true;
								break;
							}
						}
					}	
				} else if(this->isPos && !other.isPos) { // - cmp +
					break;
				} else if(!this->isPos && other.isPos) { // + cmp -
					ret = true;
				} else if(!this->isPos && !other.isPos) { // + cmp +
					//cout << "not pos cmp not pos" << endl;
					if(n1 < n2) {
						ret = false; break;
					} else if(n1 > n2) { 
						ret = true; break;
					} else if(n1 == n2) {
						for(int i=0; i<n1; i++) {
							if(inte[i] < other.inte[i]) 
							  break;
							else if(inte[i] > other.inte[i]) {
								ret = true;
								break;
							}
						}
					}
				}
			} while(0);

			return ret;
		}

		bool operator < (Int other) {
			bool ret = false;
			int n1 = inte.size();
			int n2 = other.inte.size();
			do {
				if(this->isPos && other.isPos) { // - cmp -
					if(n1 > n2) {
						ret = true; break;
					} else if(n1 < n2) {
						break;
					} else if(n1 == n2) {
						for(int i=0; i<n1; i++) {
							if(inte[i] > other.inte[i]) {
								ret = true; break;
							} else if(inte[i] < other.inte[i]) {
								break;
							}
						}
					}
				} else if(this->isPos && !other.isPos) { // - cmp +
					ret = true;
				} else if(!this->isPos && other.isPos) { // + cmp -
					ret = false;
				} else if(!this->isPos && !other.isPos) {
					if(n1 < n2) {
						ret = true; break;
					} else if(n1 > n2) {
						break;
					} else if(n1 == n2) {
						for(int i=0; i<n1; i++) {
							if(inte[i] < other.inte[i]) {
								ret = true; break;
							} else if(inte[i] > other.inte[i]) {
								break;
							}
						}
					}
				}
			} while(0);

			return ret;
		}

		bool operator == (Int other) {
			bool x = (*this) > other;
			bool y = (*this) < other;
			if(!x && !y) 
			  return true;
			else 
			  return false;
		}

};

int main() {
/**
	Int x1234("1234");
	Int x_1234("-1234");
	Int x5677("5677");
	Int x_3306("-3306");
	Int x8080("8080");
	Int x_8080("-8080");

	cout << x1234 << " + " << x5677 << " = " << (x1234 + x5677) << endl;
	cout << x1234 << " - " << x5677 << " = " << (x1234 - x5677) << endl;
	cout << x1234 << " + " << x_3306 << " = " << (x1234 + x_3306) << endl;
	cout << x1234 << " - " << x_3306 << " = " << (x1234 - x_3306) << endl;
	cout << x_3306 << " + " << x_8080 << " = " << (x_3306 + x_8080) << endl;
	cout << x_3306 << " - " << x_8080 << " = " << (x_3306 - x_8080) << endl;
*/

	int count = 0;
	int i = 0;
	cin >> count;
/**
	while(i < count) {
		string num1;
		string num2;
		cin >> num1;
		cin >> num2;
		Int i1(num1);
		Int i2(num2);
		cout << "Case " << i << ":" << endl;
		cout << i1 << " + " << i2 << " = " << (i1 + i2) << endl;
		if(i < count)
			cout << endl;
		i++;
	}
*/

	for(int i=1; i<=count; i++) {
		string num1, num2;
		cin >> num1;
		cin >> num2;
		Int i1(num1);
		Int i2(num2);
		cout << "Case " << i << ":" << endl;
		cout << i1 << " + " << i2 << " = " << (i1+i2) << endl;
		if(i!=count)
		  cout << endl;
	}

	return 0;
}

