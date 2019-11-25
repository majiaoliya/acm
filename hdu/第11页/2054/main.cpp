#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
#define ll long long
using namespace std;

string n1, n2;

int main(void) {
	freopen("test", "r", stdin);
	for( ; cin>>n1>>n2; ) {
		int pat1 = n1.length(), pat2 = n2.length();
		int zero1 = 0, zero2 = 0;
		for(int i=pat1-1, k=pat2-1; i>=0||k>=0; i--, k--) {
			if(i>=0 && n1[i]=='.') pat1 = i;
			if(k>=0 && n2[k]=='.') pat2 = k;
		} 
		for(int i=n1.length()-1; i>=0 && i>pat1 && n1.back()=='0'; i--) {
			n1.pop_back();
		}
		for(int k=n2.length()-1; k>=0 && k>pat2 && n2.back()=='0'; k--) {
			n2.pop_back();
		}
		if(n1.back() == '.') n1.pop_back();
		if(n2.back() == '.') n2.pop_back();
		cout << (n1 == n2 ? "YES" : "NO") << endl;
	}
	return 0;
}
