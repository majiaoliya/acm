//#include <iostream> 
//#include <string.h>
//#include <vector>
//#include <time.h>
//using namespace std;
//#include <iostream>
//#include <math.h>
//#include <vector>
//#define MAXN 1000005
//#define ll long long int
//using namespace std;

//ll prime[MAXN], pn, lef, rig, max_prime; 
//bool vis[MAXN], sec[MAXN]; //题目要求的那个区间

//void get_prime(int rig) { //线性筛 准备好sqrt(rig)以内的素数
//	memset(vis, false, sizeof(vis));
//	pn = 0, max_prime = sqrt(rig);
//	vis[0] = vis[1] = true;
//	for(int i=2; i<=max_prime; i++) {
//		if(!vis[i])
//			prime[pn++] = i;
//		for(int k=0; k<pn && prime[k]*i<=max_prime; k++) {
//			vis[i*prime[k]] = true;
//			if(i%prime[k] == 0) break; 
//		}
//	}
//}

//int main(void) {
//	freopen("test", "r", stdin);
////	get_prime(1000000);
////	for(int i=0; i<pn; i++)
////		printf("%lld ", prime[i]);
//	for( ; EOF != scanf("%lld %lld", &lef, &rig); ) {
//		get_prime(rig);
//		ll sub = rig-lef;
//		vector<ll> v; //区间[lef,rig]的所有质数
//		memset(sec, false, sub+2);
///** 太慢 应该用素数筛的思想 (把质数(2,3,5...)在[lef,rig]的倍数划掉)
//		for(int i=0; i<=sub; i++) { //筛区间[lef,rig]里的合数
//			int num = lef + i;
//			for(int k=0; k<pn; k++) 
//				if(num!=prime[k] && num%prime[k] == 0) { //能被一个质数整除 就是合数
//					sec[i] = true;
//					break;
//				}
//			if(sec[i] == false)
//				v.push_back(num);
//		}
//*/
//		for(int i=0; i<pn; i++) {
//			ll p = prime[i], temp = ceil(lef/p)*p;
//			for(ll k=temp; k<=rig; k+=p) {
//				sec[k-lef] = true;
//			}
//		}
//		for(int i=0; i<sub; i++) {
//			if(!sec[i])
//				v.push_back(i+lef);
//		}
//		if(!v.empty() && v.size()==1) 
//			printf("There are no adjacent primes.\n");
//		else {
//			ll minl=v[0], minr=v[1], maxl=v[0], maxr=v[1];
//			ll mind = minr-minl, maxd = maxr-maxl;
//			for(int i=2, lst; lst=i-1,i<v.size(); i++) {
//				ll tsub = v[i] - v[lst];
//				if(tsub < mind) {
//					mind = tsub;
//					minl = v[lst], minr = v[i];
//				}
//				if(tsub > maxd) {
//					maxd = tsub;
//					maxl = v[lst], maxr = v[i];
//				}
//			}
//			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", minl, minr, maxl, maxr);
//		}
//	}
//	return 0;
//}



#include <iostream> 
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;
#include <iostream>
#include <math.h>
#include <vector>
#define MAXN 1000005
#define ll long long int
using namespace std;

ll prime[MAXN], pn, lef, rig, max_prime; 
bool vis[MAXN], sec[MAXN]; //题目要求的那个区间

void get_prime(int rig) { //线性筛 准备好sqrt(rig)以内的素数
	memset(vis, false, sizeof(vis));
	memset(sec, false, sizeof(sec));
	pn = 0, max_prime = rig;
	vis[0] = vis[1] = true;
	for(int i=2; i<=max_prime; i++) {
		if(!vis[i])
			prime[pn++] = i;
		for(int k=0; k<pn && prime[k]*i<=max_prime; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break; 
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);

	for( ; EOF != scanf("%lld %lld", &lef, &rig); ) {
		get_prime(50000); //筛出int范围内的素数[1,sqrt(20亿)]
#ifdef DEBUG
		for(ll i=0; i<pn; i++) {
			printf("%lld ", prime[i]);
		}
		printf("\n");
#endif
		ll sub = rig-lef;
		for(int i=0; i<pn; i++) { //筛掉区间[lef,rig]的合数
			ll p = prime[i];
#ifdef DEBUG
			printf("%lld 起点:%lld\n", p, max((lef+p-1)/p*p,2ll*p));
#endif
			for(ll k=max((lef+p-1)/p*p,2ll*p); k<=rig; k+=p) {
				sec[k-lef] = true;
			}
		}
		ll minl, minr, maxl, maxr, mind=9999999
			, maxd=0, cnt=0, lst;
		for(ll i=0; i<=rig-lef; i++) {
			if(!sec[i] && i+lef>1) {
				cnt ++;
				ll cur = i + lef;
				if(cnt >= 2) {
					ll dist = cur - lst;
					if(dist > maxd)
						maxl = lst, maxr = cur, maxd=dist;
					if(dist < mind)
						minl = lst, minr = cur, mind=dist;
				}
				lst = cur;
			}
		}
		if(cnt >= 2) {
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", minl, minr, maxl, maxr);
		} else {
			printf("There are no adjacent primes.\n");
		}
	}
	return 0;
}


