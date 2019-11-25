#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#define debug
using namespace std;

int abs(int x) { return x > 0 ? x : -x; }
//#define max(x,y) (x > y ? x : y)
class Solution {
public:
    int equalSubstring(string s, string t, int m) {
        int ret = 0;
		if(s.empty() || t.empty()) return ret;
		
		vector<int> arr(s.length(), 0);
		for(int i=0; i<s.length(); i++)
			arr[i] = abs(s[i] - t[i]);
		int i = 0, j = 0, sum = 0;
		while(i < (int)s.length()) {
			while(j<(int)s.length() && sum+arr[j]<=m) {
				sum += arr[j];
				j++;
			}
			ret = max(ret, j-i);
			sum -= arr[i];
			i++;
		}
		/**
		for(int i=0; i<(int)s.length(); i++) {
			int mm = m, len = 0;
			for(int k=0; k<i; k++) {
				if(s[k] == t[k]) len ++;
				else {
					int val = abs(s[k]-t[k]);
					if(mm >= val) {
						mm -= val;
						len ++;
					}
				}
			}
			ret = max(len, ret);
		}
		*/
		return ret;
    }
};

#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	string s = "abcd", t = "bcdf";
	int cost = 3;
	Solution sl;
	cout << sl.equalSubstring(s, t, cost) << endl;
	s = "abcd", t = "cdef", cost = 3;
	for(int i=0; i<s.length(); i++) printf("[%d]", s[i]);
	printf("\n");
	for(int i=0; i<t.length(); i++) printf("[%d]", t[i]);
	printf("\n");

	cout << sl.equalSubstring(s, t, cost) << endl;
	s = "abcd", t = "acde", cost = 0;
	for(int i=0; i<s.length(); i++) printf("[%d]", s[i]);
	printf("\n");
	for(int i=0; i<t.length(); i++) printf("[%d]", t[i]);
	printf("\n");

	cout << sl.equalSubstring(s, t, cost) << endl;
	s = "krrgw", t = "zjxss", cost = 19;
	for(int i=0; i<s.length(); i++) printf("[%d]", s[i]);
	printf("\n");
	for(int i=0; i<t.length(); i++) printf("[%d]", t[i]);
	printf("\n");
	cout << sl.equalSubstring(s, t, cost) << endl;
	return 0;
}
#endif
