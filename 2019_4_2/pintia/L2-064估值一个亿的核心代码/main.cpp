#include <iostream>
#include <vector>
#include <string>
using namespace std;

void trim(string& line) {
	int left = 0, right = line.length()-1, t=0;
	char buf[line.length()+1];
	for( ; line[left]==' ' && left<line.length(); left++) ;
	for( ; line[right]==' ' && right>=0; right--) ;
	//cout << "left:" << left << " right:" << right << " ";
	for(int i=left; i<=right; i++)
		buf[t++] = line[i];
	buf[t] = '\0';
	line = buf;
}

void mid_trim(string& line) { //一个以上的空格替换为一个空格
	char buf[line.length()+1];
	int t = 0;
	for(int i=0, tag=0; i<line.length(); i++) {
		if(line[i] == ' ') {
			tag = true; continue;
		} else {
			if(tag) {
				buf[t++] = ' ';
				tag = false;
			}
			buf[t++] = line[i];
		}
	}
	buf[t] = '\0';
	line = buf;
}

void change(string& line) { //转小写
	for(int i=0; i<line.length(); i++) {
		if(line[i]>='A' && line[i]<='Z' && line[i]!='I') 
			line[i] -= 'A'-'a';
		if(line[i] == '?') line[i] = '!';		
	}
	
}

int main(void) {
	
	freopen("test", "r", stdin);
	
	string line, rs;
	int n;
	cin >> n;
	cin.ignore();
	for( ; n--; ) {
		getline(cin, line);
		cout << "src:" << line << endl;
		trim(line); //去除前后空格
		mid_trim(line); //去除中间一个以上空格
		change(line);
		cout << line << endl;
	}
	
	
	return 0;
}
