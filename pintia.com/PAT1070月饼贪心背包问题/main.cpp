#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define MAXN 1024

using namespace std;

struct Node {
	double w, v, unit;
} arr[MAXN];

int n;
double m;

bool cmp(Node& x, Node& y) {
	return x.unit < y.unit;
}

int main()
{
    freopen("test", "r", stdin); 
    scanf("%d %lf", &n, &m);
    for(int i=0; i<n; i++)
    	scanf("%lf", &arr[i].w);
    for(int i=0; i<n; i++) {
    	scanf("%lf", &arr[i].v);
    	arr[i].unit = arr[i].v / arr[i].w;
    }
    
    sort(arr, arr+n, cmp);
    double sum = 0;
    for(int i=n-1; m>=0.000 && i>=0; i--) {
    	if(m <= arr[i].w) {
    		sum += arr[i].unit * m;
    		break;
    	} else {
    		sum += arr[i].v;
    		m -= arr[i].w;
    	}
    }
    printf("%.2lf\n", sum);
//    for(int i=0; i<n; i++)
//    	printf("%.2lf,", arr[i].unit);
    return 0;
}

