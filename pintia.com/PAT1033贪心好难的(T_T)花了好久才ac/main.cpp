//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <stack>
//#include <set>
//#define MAXN 10005
//using namespace std;

////double cap, dist, avg;
////int n;

//string to_bin(unsigned char c) {
//	stack<int> rs;
//	while(c) {
//		rs.push(c%2);
//		c /= 2;
//	}
//	string rs_str = "";
//	while(!rs.empty()) {
//		rs_str += rs.top()+'0';
//		rs.pop();
//	}
//	for(int i=rs_str.length(); i<8; i++) {
//		rs_str = '0' + rs_str;
//	}
//	return rs_str == "" ? "00000000" : rs_str;
//}

//int main()
//{
//	freopen("test", "r", stdin);
//	
//	string str;
//	cin >> str;
//	for(int i=0; i<str.length(); i++) {
//		cout << to_bin((unsigned char)str[i]);
//	}
//	cout << endl;
//	
//	return 0;
//}






//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <stack>
//#include <algorithm>
//#include <set>
//#define MAXN 10005
//using namespace std;

//double cap, dist, avg;
//int n;

//struct Node {
//	double unit, dist;
//} arr[MAXN];

//int cmp(Node& x, Node& y) { return x.dist < y.dist; }

//int main()
//{
//	freopen("test", "r", stdin);
//	scanf("%lf %lf %lf %d", &cap, &dist, &avg, &n);
//	
//	for(int i=1; i<=n; i++) 
//		scanf("%lf %lf", &arr[i].unit, &arr[i].dist);
//	sort(arr+1, arr+1+n, cmp);
//	
//	if(n == 0 || arr[1].dist != 0) { 
//		printf( "The maximum travel distance = 0.00\n");
//		return ;
//	}
//	double sum_dist = 0; //已经走的路的总和
//	double can_go = cap * avg; //满油最多可跑
//	int cur_id = 1; //当前在那个加油站
//	while(sum_dist < dist) {
//	
//		//先找范围内第一个更小unit的加油站
//		bool hav = false;
//		int cnt = 0; //记录距离内的加油站有几个
//		for(int i=cur_id+1; i<=n; i++) {
//			double sub = arr[i].dist - arr[cur_id].dist;
//			if(sub > can_go) break;
//			cnt ++;
//			if(arr[i].unit <= arr[cur_id].unit) {
//				hav = true;
//				sum_dist += sub;
//				sum_cost += sub * arr[cur_id].unit;
//				break;
//			}
//		}
//		if(hav) continue ;
//		if(cnt == 0) { //到不了其他加油站了 判断是否能到终点
//			if(arr[cur_id].dist + can_go >= dist) { //能到终点
//				ok = true;
//				sum_cost += (dist-arr[cur_id].dist)*arr[cur_id].unit;
//				printf("%.2lf\n", sum_cost);
//				return 0;
//			} else {
//				sum_cost += (arr[i].unit * cap);
//				printf("The maximum travel distance = %.2lf\n", sum_cost);
//				return 0;
//			}
//		} else { //还能到达其他加油站 加满油 就去最便宜的那个
//			int min_id = cur_id + 1;
//			double min_unit = arr[cur_id].unit;
//			for(int i=min_id; i<=n; i++) {
//				double sub = arr[i].dist - arr[cur_id].dist;
//				if(sub > can_go) break;
//				if(arr[i].unit <= min_unit) {
//					min_id = i;
//					min_unit = arr[i].unit;
//				}
//			}
//			
//		}
//	}
//	return 0;
//}







//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <stack>
//#include <algorithm>
//#include <set>
//#define MAXN 10005
//using namespace std;

//double cap/*油箱容量*/, max_dist/*终点距离*/, avg/*每公里耗油*/;
//int n/*加油站个数*/;

//struct Node {
//	double unit/*单价*/, dist/*距离*/;
//} arr[MAXN];

//int cmp(Node& x, Node& y) { return x.dist < y.dist; }

//int main()
//{
//	freopen("test", "r", stdin);
//	scanf("%lf %lf %lf %d", &cap, &max_dist, &avg, &n);
//	for(int i=1; i<=n; i++) 
//		scanf("%lf %lf", &arr[i].unit, &arr[i].dist);
//	sort(arr+1, arr+1+n, cmp);
//	if(arr[1].dist != 0.000) { //起点没有加油站 跑不动
//		printf("The maximum travel distance = 0.00");
//		return 0;
//	}
//	
//	double can_go = avg * cap; //加满油能跑xxx公里
//	double now = 0.00; //当前剩余油量
//	double cost = 0.00; //当前花费
//	int now_idx = 1; //当前在那个加油站
//	while(true) {
//		//1.先判断在加满油 可走的范围内有没有更便宜的加油站 挑最接近now的去
//		bool hav_cheaper = false, hav_other = false;
//		for(int i=now_idx+1; i<=n; i++) {
//			double sub_dist = arr[i].dist - arr[now_idx].dist;
//			if(can_go < sub_dist) break; //到不了的加油站不用看了
//			hav_other = true; 
//			if(arr[i].unit <= arr[now_idx].unit) { //有更便宜的最近加油站
//				hav_cheaper = true;
//				now_idx = i;
//				cost += arr[now_idx].unit * sub_dist; //花钱去
//				break;
//			}
//		}
//		printf("hav_cheaper:%d hav_other:%d\n", hav_cheaper, hav_other);
//		if(hav_cheaper) continue ;
//		if(!hav_other) { //无法到达其他加油站 能到终点到终点,不能到就加满油跑最远
//			int sub_dist = max_dist - arr[now_idx].dist;
//			if(sub_dist <= can_go) { //能到终点
//				double need = sub_dist/avg; //到终点需要的油量
//				if(now < need) //如果剩余的油不够到终点 就加一点点
//					cost += (need-now)*arr[now_idx].unit;
//				printf("%.2lf\n", cost);
//			} else {
//				double max_go = arr[now_idx].dist + can_go;
//				printf("The maximum travel distance = %.2lf\n", max_go);
//			}
//			break;
//		} else { //可以到达其他加油站 且其他加油站都比now_idx贵, 加满油去最便宜的那个
//			cost += arr[now_idx].unit * (cap-now);
////			now = cap; //加满油
//			int min_id = now_idx + 1;
//			double min_unit = arr[now_idx].unit;
//			for(int i=min_id; i<=n; i++) {
//				double sub_dist = arr[i].dist - arr[now_idx].dist;
//				if(can_go < sub_dist) break;
//				if(arr[i].unit < min_unit) {
//					min_id = i;
//					min_unit = arr[i].unit;
//				}
//			}
//			double sub_dist = arr[min_id].dist - arr[now_idx].dist;
//			double need = sub_dist / avg; //到这个相对便宜的加油站耗掉的油
//			now = cap - need;
//			now_idx = min_id;
//		}
//		
//	}
//	
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <set>
#define MAXN 10005
using namespace std;

double cap/*油箱容量*/, max_dist/*终点距离*/, avg/*每公里耗油*/;
int n/*加油站个数*/;

struct Node {
	double unit/*单价*/, dist/*距离*/;
} arr[MAXN];

int cmp(Node& x, Node& y) { return x.dist < y.dist; }

int main()
{
	freopen("test", "r", stdin);
	scanf("%lf %lf %lf %d", &cap, &max_dist, &avg, &n);
	for(int i=1; i<=n; i++) 
		scanf("%lf %lf", &arr[i].unit, &arr[i].dist);
	sort(arr+1, arr+1+n, cmp);
	if(arr[1].dist != 0.000) { //起点没有加油站 跑不动
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	
	double can_go = avg * cap; //加满油能跑xxx公里
	double now = 0.00; //当前剩余油量
	double cost = 0.00; //当前花费
	int now_idx = 1; //当前在那个加油站
	
	while(true) {
		bool hav_cheaper = false, hav_other = false;
		for(int i=now_idx+1; i<=n; i++) {
			double sub_dist = arr[i].dist - arr[now_idx].dist;
			if(sub_dist > can_go) break;
			hav_other = true;
			if(arr[i].unit < arr[now_idx].unit) { //找到第一个更便宜的 go
				hav_cheaper = true;
//				printf("[%.2lf,%.2lf]go to cheaper%.2lf,%.2lf] cost:%.2lf\n", arr[now_idx].unit, arr[now_idx].dist, arr[i].unit, arr[i].dist, arr[now_idx].unit * (sub_dist/avg));
//				cost += arr[now_idx].unit * (sub_dist/avg);
				double need = sub_dist / avg;
				if(now < need) {
					cost += arr[now_idx].unit * (need-now);
					now = need;
				}
				now -= need;
				now_idx = i;
				break;
			}
		}
		if(hav_cheaper) continue;
		if(!hav_other) { //范围内没有加油站
			double sub_dist = max_dist - arr[now_idx].dist;
			if(can_go >= sub_dist) { //能到终点
				double need = sub_dist / avg; //到终点需要的油量
				if(need > now) { //如果剩余的油不够到终点 就加一点点 
//					printf("差%.2lf油到终点 cost:%.2lf\n", need-now, arr[now_idx].unit * (need - now));
					cost += arr[now_idx].unit * (need - now);
				}
				printf("%.2lf\n", cost);
			} else { //不能到就加满油跑最远
//				printf("now_idx:%d\n", now_idx);
				double max_go = arr[now_idx].dist + can_go;
				printf("The maximum travel distance = %.2lf\n", max_go);
			}
			break;
		} else { //范围内有加油站 但是都比当前贵
			double sub_dist = max_dist - arr[now_idx].dist;
			if(sub_dist <= can_go) { //直接到终点
				double need = sub_dist / avg;
				if(now < need) {
//					printf("有加油站 差%.2lf油到终点 cost:%.2lf\n", need-now, arr[now_idx].unit * (need - now));
					cost += arr[now_idx].unit * (need-now);
				}
				printf("%.2lf\n", cost);
				break;
			} else { //不能到终点 加满油 挑一个相对便宜且更远的加油站x去
				int min_id = -1;
				double min_unit = 999999999;
				for(int i=now_idx+1; i<=n; i++) {
					sub_dist = arr[i].dist - arr[now_idx].dist;
					if(sub_dist > can_go) break;
					if(arr[i].unit <= min_unit) {
						min_id = i;
						min_unit = arr[i].unit;
					}
				}
				sub_dist = arr[min_id].dist - arr[now_idx].dist;
				double need = sub_dist / avg; //到x花费的油
//				printf("[%.2lf,%.2lf]到相对便宜[%.2lf,%.2lf] now:%.2lf need:%.2lf 加满cost:%.2lf\n", 
//					arr[now_idx].unit, arr[now_idx].dist, 
//					arr[min_id].unit, arr[min_id].dist,
//					now,
//					need,
//					(cap-now) * arr[now_idx].unit
//					);
				cost += (cap-now) * arr[now_idx].unit;
				now = cap - need;
				now_idx = min_id;
			}
		}
	}
	
	return 0;
}






