#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 100086

using namespace std;

string str;

void my_sub(string& line, string& rs, int lef, int rig) {
	for(int i=lef; i<=rig; i++)
		rs += line[i];
}

string parse(string& line) {
	bool is_fu = line[0] == '-' ? true : false;
	string zhengshu, xiaoshu, houzui; //正数部分,小数部分,后缀
	int ei = line.find('E'), pi = line.find('.');
	my_sub(line, zhengshu, 1, pi-1);
	my_sub(line, xiaoshu, pi+1, ei-1);
	my_sub(line, houzui, ei+1, line.length()-1);
	
	int zs = stoi(zhengshu), xs = stoi(xiaoshu), hz = stoi(houzui);
	
	int npi = pi;
	if(hz > 0) { //后缀为正, 小数点右移, 补0
		while(hz > 0) {
			npi ++, hz --;
			if(npi >= ei)
				xiaoshu += '0';
		}
	} else if(hz < 0) { //后缀为负, 小数点左移, 补0
		while(hz < 0) {
			npi --, hz ++;
			if(npi <= 0)
				zhengshu = '0' + zhengshu;
		}
		if(npi <= 0)
			zhengshu = "0." + zhengshu;
	}
	cout << (is_fu?"-" : "") << zhengshu << xiaoshu << endl;
	
	return "";
}

int main()
{
    freopen("test", "r", stdin); 
	for( ; cin>>str; ) {
		if(str=="0E0" || str=="-0E0" || str=="+0E0"
			|| str=="0.0E0" || str=="-0.0E0" || str=="+0.0E0") printf("0");
		else
			string rs = parse(str);
	}
	
    return 0;
}

