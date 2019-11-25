
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

float n, k;

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%f %f", &n, &k); ) {
		float house = 200.0, money = n;
		int i=1;
		for(i=1; i<=20; i++) {
			if(house <= money) break;
			float thouse = house*k*.01;
			house += thouse;
			money += n;
		}
		if(i > 20) printf("Impossible\n");
		else printf("%d\n", i);
	}
	
	return 0;
}



