#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#define MAXN 105
using namespace std;

int n;

struct Row {
	char buf[39];
	Row() {
		for(int i=0; i<39; i++)
			buf[i] = ' ';
		buf[3] = buf[20] = buf[25] = '|';
		buf[26] = '[', buf[37] = ']';
		buf[38] = 0;
	}
	Row& set1(string& s) {
		for(int i=2, k=s.length()-1; i>=0 && k>=0; i--, k--)
			buf[i] = s[k];
		return *this;
	}
	Row& set2(string& s) {
		for(int i=4, k=0; k<s.length(); i++, k++)
			buf[i] = s[k];
		return *this;
	}
	Row& set3(string& s) {
		for(int i=21, k=0; k<s.length(); i++, k++)
			buf[i] = s[k];
		return *this;
	}
	Row& set4(string& s, int p=-1) {
		if(s == "Running") {
			for(int i=27, k=0; k<p; k++, i++)
				buf[i] = 'X';
		} else if(s == "WA") {
			buf[31] = 'W', buf[32] = 'A';
		} else if(s == "TLE") {
			buf[31] = 'T', buf[32] = 'L', buf[33] = 'E';
		} else if(s == "FB") {
			buf[31] = 'A', buf[32] = 'C', buf[33] = '*';
		} else {
			for(int i=31, k=0; k<s.length(); i++, k++)
				buf[i] = s[k];
		}
		return *this;
	}
	friend ostream& operator << (ostream& out, Row& row) {
		out << row.buf;
		return out;
	}
};

int main(void) {
	freopen("test", "r", stdin);
//	string str = " 19|qqqqq_University|1001|[XXX       ]";
//	for(int i=0; i<str.length(); i++) {
//		if(str[i] == '|' || str[i] == '[' || str[i] == ']')
//			printf("%d ", i);
//	}
	int t;
	cin >> t;
	for( ; t--; ) {
		int p = -1;
		string str[4];
		Row row;
		for(int i=0; i<4; i++) 
			cin >> str[i];
		if(str[3] == "Running")
			cin >> p;
		row.set1(str[0]).set2(str[1]).set3(str[2]).set4(str[3], p);
		cout << row << endl;
	}
	return 0;
}
