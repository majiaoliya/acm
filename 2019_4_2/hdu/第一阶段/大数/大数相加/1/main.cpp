#include <iostream>
#define N 1024
#define M 1024

#include <vector>
#include <string.h>

using namespace std;

class BigInt {

	public:
		friend ostream& operator << (ostream& out, BigInt& bi) {
			if(!bi.vect.size()) {
				out << "0";
			} else {
				if(bi.neg) out << "-";
				for(int i=0; i<bi.vect.size(); i++) {
					out << bi.vect[i];
				}
			}
			return out;
		}

	public:
		bool neg;
		std::vector<char> vect;

		BigInt(std::string& str) : neg(false) {
			if(str.length() > 0) {
				int i = 0;
				if(str[i] == '-') {
					neg = true;
					i = 1;
				}
				for(bool b=false; i<str.length(); i++) {
					if(str[i] != '0') b = true;
					if(b) this->vect.push_back(str[i]);
				}
			}
		}

		bool operator > (BigInt& other) {
			bool ret = false;

			do {
				if(!this->neg && !other.neg) { // + +
					if(this->vect.size() > other.vect.size()) { return true; }
					else if(this->vect.size() < other.vect.size()) { return false; }
					else {
						for(int i=0; i<vect.size(); i++) {
							if(vect[i] > other.vect[i]) return true;
						}
						return false;
					}
				} else if(!this->neg && other.neg) { // + -
					return true;
				} else if(this->neg && !other.neg) { // - +
					return false;
				} else if(this->neg && other.neg) { // - -
					if(this->vect.size() < other.vect.size()) { return true; }
					else if(this->vect.size() > other.vect.size()) { return false; }
					else {
						for(int i=0; i<vect.size(); i++) {
							if(vect[i] < other.vect[i]) return true;
						}
						return false;
					}
				}

			} while(false);
			return ret;
		}

		bool operator < (BigInt& other) {
			bool ret = false;

			do {
				if(!this->neg && !other.neg) { // + +
					if(this->vect.size() < other.vect.size()) { return true; }
					else if(this->vect.size() > other.vect.size()) { return false; }
					else {
						for(int i=0; i<vect.size(); i++) {
							if(vect[i] < other.vect[i]) return true;
						}
						return false;
					}
				} else if(!this->neg && other.neg) { // + -
					return false;
				} else if(this->neg && !other.neg) { // - +
					return true;
				} else if(this->neg && other.neg) { // - -
					if(this->vect.size() > other.vect.size()) { return true; }
					else if(this->vect.size() < other.vect.size()) { return false; }
					else {
						for(int i=0; i<vect.size(); i++) {
							if(vect[i] > other.vect[i]) return true;
						}
						return false;
					}
				}

			} while(false);
			return ret;
		}

		bool operator == (BigInt& other) { return !((*this) > other) && !((*this) < other); }

		BigInt operator + (BigInt& other) {
			if(!this->neg && !other.neg) { // + +
				bool isBigger = *this > other;
				if(isBigger) { //this > other
					char rs[this->vect.size() + 3];
					memset(rs, false, this->vect.size()+3);
					int trear = this->vect.size()-1, orear = other.vect.size()-1;
					char tag = 0; //进位标志
					
					int i;
					for(i=sizeof(rs)-1; i>=0 && trear>=0 && orear>=0; i--) {
						rs[i] += tag;
						int trs = vect[trear] + other.vect[orear];
						if(trs >= 10) {
							tag = 1;
							trs -= 10;
						} else {
							tag = 0;
						}
						rs[i] = trs;
						trear --, orear --;
					}

					for( ; trear>=0; trear--) {
						int trs = vect[trear] + rs[i];
						if(trs >= 10) {
							tag = 1;
							trs -= 10;
						} else {
							tag = 0;
						}
						
					}

				}
			} 
		}
};

int main(void) {

//#define DEBUG
#ifdef DEBUG
	string s1, s2;
	for(int i=0; i<10; i++) {
		cin >> s1 >> s2;
		BigInt n1(s1), n2(s2);
		cout << n1 << " > " << n2 << " " << (bool)(n1 > n2) << endl;
		cout << n1 << " < " << n2 << " " << (bool)(n1 < n2) << endl;
		cout << n1 << " == " << n2 << " " << (bool)(n1 == n2) << endl;
	}
#endif

	return 0;
}
