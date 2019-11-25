#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long int 
#define ull unsigned long long int 
#pragma warning(disable:4996)
#define pf printf
#define sf scanf
#define min(a,b) (a)>(b)?(a):(b);
double PI = acos(-1.0);
double eps=1e-5;


char b[101];
ull nb, ns, nc;
int pb, ps, pc;
ll r;//卢布数

int lb = 0, ls = 0, lc = 0;
bool check(ull mid) {
    ll rr = r;
    ull b = lb * mid;
    ull s = ls * mid;
    ull c = lc * mid;
    if (nb < b) {//不足
        rr -= (b - nb)*pb;
     }

    if (ns < s) {//不足
        rr -= (s - ns)*ps;

    }

    if (nc < c) {//不足
        rr -= (c - nc)*pc;
    }


    if (rr >= 0) 
        return true;


    if(rr<0)   return false;

}
int main(void) {
	freopen("test", "r", stdin);
    int len;
    sf("%s", b);
    len = strlen(b);
    for (int i = 0; i < len; i++) {
        if (b[i] == 'B')  lb++;
        else if (b[i] == 'S')  ls++;
        else if (b[i] == 'C')  lc++;
    }

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    ull right = r + nb + ns + nc;
    ull left = 0;
    ull mid=0;

    while (right >left) {
        mid = (left + right+1) / 2;//（3+3+1）/2=3；（3+4+1）/2=4；使相差为1的两个数凑高，相同的两个数结果不变
        int mark = check(mid);
        if (mark==true) //mid偏小
        left = mid ;
        if(mark==false)//mid偏大
        right = mid-1 ;
    }
    mid = (left + right + 1) / 2;//再更新一次，不然不是最新值
    cout << mid << endl;

    return 0;
}
