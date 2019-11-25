#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAXN 1086

using namespace std;

int n, rad;

string parse(int n, int rad) { //十进制n转化成rad进制
	string ret;
	int tn = n;
	while(tn) {
		ret = to_string(tn%rad) + ret;
		tn /= rad;
	}
	return ret;
}

bool check(string str) {
	int len = str.length();
	for(int i=0; i<len; i++) 
		if(str[i] != str[len-1-i]) return false;
	return true;
}

int main()
{
    freopen("test", "r", stdin);
   	
   	for( ; EOF != scanf("%d %d", &n, &rad); ) {
   		if(n==0) {
   			cout << "Yes\n0\n";
   			continue ;
   		} 
   		string rs = parse(n, rad);
   		cout << (check(rs) ? "Yes" : "No") << endl;	
   		for(int i=0, c=0; i<rs.length(); i++) {
   			if(c++) cout << " ";
   			cout << rs[i];
   		}
   		cout << "\n";
   	}
   	
    return 0;
}


