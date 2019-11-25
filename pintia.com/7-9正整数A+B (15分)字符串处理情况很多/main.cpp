#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

string a, b, rs;

void split_ab(string& line, int idx, string& a, string& b) { //截成a,b两份
	for(int i=0; i<idx; i++)
		a += line[i];
	for(int i=idx+1; i<line.length(); i++)
		b += line[i];
}

bool check(string& x) { //检测x是否为[1,1000]的纯数字字符串
	if(x.length() > 4 || x.empty()) return false;
	for(int i=0; i<x.length(); i++)
		if(x[i]<'0' || x[i]>'9') return false;
	int xi = atoi(x.data());
	if(xi<1 || xi>1000) return false; 
	return true;
}

int main() {
	freopen("test", "r", stdin);
	
	string line;
	getline(cin, line); 
	{
		a = "", b = "";
		for(int i=0; i<line.length(); i++) {
			if(line[i] == ' ') {
				split_ab(line, i, a, b);
				break;
			}
		}
		if(check(a) && check(b)) {
			cout << a << " + " << b << " = " << (atoi(a.data())+atoi(b.data())) << endl;
		} else if(check(a) && !check(b)) {
			if(atoi(a.data()) > 1000 || atoi(a.data()) < 1) a = "?"; 
			cout << a << " + " << "?" << " = " << "?" << endl;
		} else if(!check(a) && check(b)) {
			if(atoi(b.data()) > 1000 || atoi(b.data()) < 1) b = "?"; 
			cout << "?" << " + " << b << " = " << "?" << endl;
		} else if(!check(a) && !check(b)) {
			cout << "? + ? = ?" << endl;
		}
	}
	
	return 0;
}


