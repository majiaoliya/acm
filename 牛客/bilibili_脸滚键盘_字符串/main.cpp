#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int n;
string str;

struct Node {
	int cnt, lst;
} nodes[256];

int cnt[257];

int main(void) {
	freopen("test", "r", stdin);
	while(cin >> n) {
		cin.ignore();
		memset(cnt, false, sizeof(cnt));
		getline(cin, str);
//		printf("try[%d] [%s]\n", n, str.data());
//		cout << n << " " << str << endl;
		for(int i=0; i<str.length(); i++)
			cnt[str[i]] ++;
		int k = 0;
		for(int i=0; i<str.length(); i++) {
			if(cnt[str[i]] == 1) {
//				printf("%c=1\n", str[i]);
				k ++;
				if(k == n) {
					cout << "[" << str[i] << "]" << endl;
					break;
				}
			}
		}
		if(k==0 || k<n) cout << "Myon~" << endl; 
	}
	return 0;
}
