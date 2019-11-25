#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n;
vector<int> zheng1, fu1, zheng2, fu2;

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		if(x>=0) zheng1.push_back(x);
		else fu1.push_back(x);
	}
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		if(x>=0) zheng2.push_back(x);
		else fu2.push_back(x);
	}
	sort(zheng1.begin(), zheng1.end());
	sort(zheng2.begin(), zheng2.end());
	sort(fu1.begin(), fu1.end());
	sort(fu2.begin(), fu2.end());
	int sum = 0;
	
	for(int i=zheng1.size()-1, k=zheng2.size()-1; i>=0 && k>=0; i--, k--) {
		int t = zheng1[i] * zheng2[k];
		if(sum + t >= sum)
			sum += t;
	}
	
	for(int i=0, k=0; i<fu1.size() && k<fu2.size(); i++, k++) {
		int t = fu1[i] * fu2[k];
		if(sum + t >= sum)
			sum += t;
	}
	printf("%d\n", sum);
	
	return 0;
}

