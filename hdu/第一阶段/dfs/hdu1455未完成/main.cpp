
//#include <iostream>
//#include <algorithm>
//#define MAX 100
//using namespace std;
// 
//int n, sum;
//int tag_len; //目标值[4,sum]之间
//int arr[MAX];
//int vis[MAX];
//bool is_find = false;
///**
// * 木棍arr[]={ 1, 2, 3, 4 } sum = 1+2+3+4 = 10;
// * so 每条原始木棍长度在 [4, sum]之间
// * 想办法从arr[]中凑出x1+x2+...+xn = x11+x22+...+xnn = [4, sum]
// * 凑出目标值[4,sum]
// */

//int cmp(int x, int y) { return x > y; }

//void dfs(int level, int len, int count) {
//	if(count == n) return ;
//	if(level > n) return ;
//	
//	for(int i=0; i<n; i++) {
//		if(!vis[i]) {
//			int t = len + arr[i];
//			vis[i] = true;
//			if(t == tag_len) {
//				dfs(level+1, 0, count+1);
//			} else {
//				dfs(level+1, t, count);
//			}
//			vis[i] = false;
//		}
//	}
//}

//int main()
//{
//	freopen("test", "r", stdin);
//	for( ; scanf("%d", &n), n; ) {
//		for(int i=0; i<n; i++) {
//			scanf("%d", arr+i);
//			sum += arr[i];
//		}
//		sort(arr, arr+n, cmp); //
//		tag_len = arr[0];
//		while(!is_find && tag_len<sum) {
//			printf("tag_len:%d\n", tag_len);
//			dfs(1, 0, 1);
//			tag_len ++;
//		}
//	}
//	
//	return 0;
//}


















///**
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 70;
//const int INF = 0x3f3f3f3f;
//int n, sumv, target, aim;//target表示目标的棍子个数，aim表示目标的棍子长度,sumv为所有木棍总长度 
//int stick[maxn], vis[maxn];//vis数组标记 ，stick存储输入的木棒长度 

//bool cmp(int a, int b) {
//    return a > b;
//}
//bool dfs(int cnt, int len, int pos) {
//    if(cnt == target) return true;//根数对上就返回 退出dfs
//    if(len == aim) return dfs(cnt+1, 0, 0); //当拼完一根后，继续拼下一根
//    for(int i = pos; i < n; i++) {//从大到小排序后，按顺序搜索
//        if(!vis[i] && len+stick[i] <= aim) {
//            vis[i] = 1;
//            if(dfs(cnt, len+stick[i], i+1)) return true;
//            vis[i] = 0;                         //只有失败才会运行到下面，否则是直接返回的
//            if(len == 0) return false;                     //如果第一根时失败  剪枝
//            while(i+1 < n && stick[i+1] == stick[i]) i++;  //如果下一根长度跟当前的失败的长度一样，剪枝
//        }
//    }
//    return false;
//}
//int main() {
//	freopen("test", "r", stdin);
//    while(~scanf("%d", &n), n) {
//        sumv = 0;
//        for(int i = 0; i < n; i++) {
//            scanf("%d",&stick[i]);
//            sumv += stick[i];
//        }
//        sort(stick, stick+n, cmp);
//        int ans = 0;
//        for(int i = stick[0]; i <= sumv; i++) {//拼好后的木棒长度只会在stick[0]和总长度之间 
//            if(sumv % i == 0) {
//                memset(vis, 0, sizeof(vis));
//                aim = i;
//                target = sumv / aim;
//                if(dfs(0, 0, 0)) {
//                    ans = aim;
//                    break;
//                }
//            }
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}
//*/













#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 20
using namespace std;

int n, tag_len, sum;
int arr[MAXN], rs[MAXN];
bool vis[MAXN];

int cmp(int x, int y) { return x > y; }

void dfs(int x, int cur_len) {
	if(x == n+1) {
		for(int i=1; i<x; i++)
			printf("%d,", arr[rs[i]]);
		printf("\n");
		return ;
	}
	if(cur_len > tag_len) return ;
	else if(cur_len == tag_len) {
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				rs[x] = i;
				vis[i] = true;
				dfs(x+1, 0);
				vis[i] = false;
			}
		}
	} else if(cur_len < tag_len) {
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				rs[x] = i;
				vis[i] = true;
				dfs(x+1, cur_len+arr[rs[x]]);
				vis[i] = false;
			}
		}
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
//	freopen("rs", "wr", stdout);
	for( ; EOF != scanf("%d", &n), n; ) {
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			sum += arr[i];
		}
		sort(arr+1, arr+1+n, cmp);
//		for(int i=arr[1]; i<=sum; i++) {
			tag_len = 6;
			dfs(1, 0);
//		}
	}
	
	return 0;
}































