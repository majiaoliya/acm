#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#define MAXN 16
using namespace std;

string table[11] = {
	"0 ",
	"1,.?!", "2ABC", "3DEF",
	"4GHI", "5JKL", "6MNO",
	"7PQRS", "8TUV", "9WXYZ"
};

char get_char(int num, int chishu) {
	if(chishu >= table[num].length());
		chishu %= table[num].length();
	return table[num][chishu];
}

int main()
{
	freopen("test", "r", stdin);
	
	string str;
	for( ; cin>>str; ) {
		if(str.empty()) break;
		int num = str[0] - '0';
		int chishu = str.length()-1;
		char c = get_char(num, chishu);
//		printf("%d %d\n", num, chishu);
		printf("%c", c);
	}
	
	return 0;
}

