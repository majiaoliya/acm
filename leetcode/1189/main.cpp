#define ll long long int
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int hash[257];
		memset(hash, false, sizeof(hash));
		for(int i=0; i<text.size(); i++)
			hash[text[i]] ++;
		//for(int i='a'; i<='z'; i++)
		//	printf("%c=%d, ", i, hash[i]);
		//printf("\n");
		int b = hash['b'], a = hash['a'], l = hash['l']>>1, o = hash['o']>>1, n = hash['n'];
		return min(a, (min(b, min(l, min(o, n)))));
	}
};
#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	string str;
	cin >> str;
	Solution s;
	printf("%d\n", s.maxNumberOfBalloons(str));
	return 0;
}
#endif
