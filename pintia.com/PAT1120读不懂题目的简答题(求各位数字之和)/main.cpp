#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#include <stack>
#define MAXN 512

using namespace std;

int main()
{
    freopen("test", "r", stdin); 
    int n;
    cin >> n;
    set<int> st;
    for(int i=0; i<n; i++) {
    	string x;
    	cin >> x;
    	int sum = 0;
    	for(int k=0; k<x.length(); k++)
    		sum += x[k] - '0';
    	st.insert(sum);
    }
    printf("%d\n", st.size());
    set<int>::iterator it = st.begin();
    int c = 0;
    while(it != st.end()) {
    	if(c++) printf(" ");
    	printf("%d", *it);
    	it ++;
    }
    return 0;
}

