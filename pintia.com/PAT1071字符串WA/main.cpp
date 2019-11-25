#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

map<string, int> mp;

void parse(string& str) {
	char buf[str.length()+4];
	memset(buf, false, sizeof(buf));
	int i, idx;
	for(i=0, idx=0; i<str.length(); i++) {
		if(str[i]>='a' && str[i]<='z') {
			buf[idx] = str[i];
		} else if(str[i]>='A' && str[i]<='Z') {
			buf[idx] = str[i] - ('A'-'a');
		} else {
			continue ;
		}
		idx ++;
	}
	str = buf;
//	cout << str << "-";
}

int main()
{
    freopen("test", "r", stdin);
    int max_count = 0;
    set<string> rs_w;
    for(string w; cin>>w; ) {
    	if(w.back() == ':') continue;
    	parse(w);
    	int& rc = mp[w];
    	rc ++;
    	if(rc > max_count) { rs_w.clear(); max_count = rc; rs_w.insert(w); }
    	else if(rc == max_count) { rs_w.insert(w); }
    }
    set<string>::iterator it = rs_w.begin();
    if(max_count == 0 || it->empty()) printf(" 0\n");
    else
    	printf("%s %d", it->data(), max_count);
    return 0;
}

