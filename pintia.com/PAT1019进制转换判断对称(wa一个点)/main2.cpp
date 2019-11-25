#include <iostream>
#include <vector> 

using namespace std;

int n, rad;

bool check(vector<int>& v) {
	for(int i=0, k=v.size()-1; i<v.size()/2; i++, k--) 
		if(v[i] != v[k]) return false;
	return true;
}

void parse(int n, int rad, vector<int>& v) {
	int tn = n;
	if(tn == 0) { v.push_back(0); return ; }
	while(tn) {
		v.push_back(tn%rad);
		tn /= rad;
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &rad); ) {
		vector<int> v;
		parse(n, rad, v);
		printf("%s\n", check(v) ? "Yes" : "No");
		for(int i=v.size()-1, c=0; i>=0; i--) {
			if(c++) printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}

	
	return 0;
}
