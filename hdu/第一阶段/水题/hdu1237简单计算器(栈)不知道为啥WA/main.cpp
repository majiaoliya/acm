#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string.h>
#define MAXN 5005
using namespace std;

string my_sub(string& line, int lef, int rig) {
	char buf[204]; memset(buf, false, sizeof(buf));
	for(int i=0; lef<=rig; lef++, i++)
		buf[i] = line[lef];
	return buf;
}

int main(void) {
	freopen("test", "r", stdin);
	string line;
	
	for( ; getline(cin, line), line != "0"; ) {
		vector<string> stk;
		for(int i=0, lef=0; i<line.length(); i++) {
			string num;
			if(line[i] == ' ') {
				num = my_sub(line, lef, i-1);
				lef = i+1;
			} else if(i == line.length()-1) {
				num = my_sub(line, lef, i);
				lef = i+1;
			} else {
				continue;
			}
			
			string fuhao;
			if(!stk.empty()) 
				fuhao = stk.back();
			if(fuhao == "*" || fuhao == "/") {
				double n2 = stod(num);
				stk.pop_back();
				double n1 = stod(stk.back());
				stk.pop_back();
				if(fuhao == "/")
					stk.push_back(to_string(n1/n2));
				else
					stk.push_back(to_string(n1*n2));
			} else {
				stk.push_back(num);
			}
		}
		double rs = 0;
		char tag = '+';
		for(int i=0; i<stk.size(); i++) {
			if(stk[i] == "+") { tag = '+'; continue; }
			if(stk[i] == "-") { tag = '-'; continue; }
			if(tag == '+')
				rs += stod(stk[i]);
			else
				rs -= stod(stk[i]);
		}
		printf("%.2lf\n", rs);
	}
	
	return 0;
}
