#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <set>
#include <algorithm>
#define MAXN 10005
using namespace std;

int n;

string my_sub(string& line, int lef, int rig) {
	string rs = "";
	for(int i=lef; i<=rig; i++)
		rs += line[i];
	return rs;
}

int parse(string& str) {
	int rs = 0;
	for(int i=str.length()-1, cnt=0; i>=0; i--) {
		int c = str[i] - '0';
		rs += (c*pow(2, cnt));
		cnt ++;
	}
	return rs;
}

int main()
{
	freopen("test", "r", stdin);
	string line;
	cin >> line;
	int lef = 0, c = 0;
	for(int i=0; i<line.length(); i++) {
		if((i+1)%8 == 0) {
			string str = my_sub(line, lef, i);
			lef = i+1;
			if(c++) printf(".");
			printf("%d", parse(str));
		}
	}
	return 0;
}

