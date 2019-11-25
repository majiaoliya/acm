#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

//char* table[] = {"zero", "one", "tow", "three", "four", "five", "six", "seven", "eight", "nine"};
char * table[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
	freopen("test", "r", stdin);
	string str;
	cin >> str;
	ll rs = 0;
	for(int i=0; i<str.length(); i++) 
		rs += str[i]-'0';
	string rs_str = to_string(rs);
	
	for(int i=0, c=0; i<rs_str.length(); i++) {
		if(c++) printf(" ");
		printf("%s", table[rs_str[i]-'0']);
	}
	printf("\n");
	return 0;
}
