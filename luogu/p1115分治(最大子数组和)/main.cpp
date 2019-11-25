#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN (200200)
#define inf 19260817
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, arr[MAXN];


int bt(int lef, int rig) {
	if(lef == rig) return arr[lef];
	int mid = (lef + rig) >> 1;
	int sum = 0, i, lmax = -inf, rmax = -inf;
	//左半边一定要从 mid向前求和
	for(sum=0, i=mid; i>=lef; i--) { sum += arr[i]; lmax = max(lmax, sum); }
	//右半边一定要从 mid+1向后求和
	for(sum=0, i=mid+1; i<=rig; i++) { sum += arr[i]; rmax = max(rmax, sum); }
	return max(lmax+rmax, 
			max(bt(lef, mid), bt(mid+1, rig)));
}

int main() {
#ifdef debug
	freopen("./testdata.in", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	int ans = bt(1, n);
	printf("%d\n", ans);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}









//
//
//#include<cstdio>
//int n , arr[200200]; //arr存储该序列
//const int minn = -19260817; // 定义最小值
//inline int Max( int a , int b) { return a > b ? a : b ;} //自定义 Max 函数（好像比stl的快一点）
//int rec( int l , int r ) { //分治函数
//    if ( l == r ) {    //    l=r时，直接返回该位置的值
//        return arr[l];
//    }
//    int mid = ( l + r ) >> 1;
//    int sum = 0 , ret1 = minn , ret2 = minn; //ret1为[l..mid]区间内包含mid的最大子段和，ret2为[mid+1..r]区间内包含(mid+1)的最大子段和
//    for( int i = mid ; i >= l ; i-- ) {
//        sum += arr[i];
//        ret1 = Max( ret1 , sum );
//    }  //求出[i..mid]区间最大值
//    sum = 0;
//    for( int i = mid+1 ; i <= r ; i++ ) {
//        sum += arr[i];
//        ret2 = Max( ret2 , sum );
//    }  //求出[mid+1..r]区间最大值
//    return Max( Max( rec( l , mid ) , rec( mid + 1 , r ) ) , ret1 + ret2 );   //返回可能一 可能二 可能三 中的最大值
//}
//int main() { // 以下主函数
//	freopen("./testdata.in", "r", stdin);
//    scanf("%d", &n );
//    for( int i = 1 ; i <= n ; i++ ) {
//        scanf("%d" , &arr[i] );
//    }
//    printf("%d" , rec(1 , n) );
//    return 0;
//}
