//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <stdio.h>
//#include <string.h>

//using namespace std;

//int main()
//{	
//	freopen("test", "r", stdin);
//	int a, b, c;
//	while(~scanf("%d %d %d", &a, &b, &c)) {
//		int tmax = max(a, b);
//		tmax = max(tmax, c);
//		printf("%d\n", tmax);
//	}
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int abs(int x) { return x > 0 ? x : -x; }

int t;
char c;

int main()
{	
	cin >> t;
	while(t--) {
		cin >> c;
		printf("%c\n", c-abs('a'-'A'));
	}
	return 0;
}
