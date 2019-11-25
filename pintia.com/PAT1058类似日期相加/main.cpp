#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 512

using namespace std;

int main()
{
    freopen("test", "r", stdin); 
   	
   	int x1, y1, z1, x2, y2, z2;
   	scanf("%d.%d.%d", &x1, &y1, &z1);
   	scanf("%d.%d.%d", &x2, &y2, &z2);
   	
   	int ty = 0, tz = 0;
   	int sumz = z1 + z2;
   	if(sumz >= 29) //z满29进一
   		sumz -= 29, tz = 1;
   	int sumy = y1 + y2 + tz;
   	if(sumy >= 17) //y满17进一
   		sumy -= 17, ty = 1;
   	int sumx = x1 + x2 + ty;
   	printf("%d.%d.%d\n", sumx, sumy, sumz);
   	
    return 0;
}

