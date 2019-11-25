//#include <iostream>
//#include <vector>
//#include <map>
//#include <string.h>
//#include <algorithm>
//#define MAXN 1024

//using namespace std;

//int pre[MAXN], rs[MAXN], nodes[MAXN], is_gang[MAXN];
//int n;
//void init() {
//	for(int i=1; i<MAXN; i++)
//		pre[i] = -1, nodes[i] = 1;
//}

//string arr[MAXN];
//int sum[MAXN], time_sum[MAXN];

//int find_root(int x) {
//	int ret = x;
//	while(pre[ret] != -1) 
//		ret = pre[ret];
//	if(ret != x) pre[x] = ret;
//	return ret;
//}

//void union_xy(int x, int y) {
//	int rx = find_root(x), ry = find_root(y);
//	rs[x] = rs[y] = sum[x] >= sum[y] ? x : y;
//	if(rx != ry) {
//		nodes[rx] += nodes[ry];
//		pre[ry] = rx;
//	}
//}

//int main()
//{
//    freopen("test", "r", stdin); 
//   	int m, time, count = 0;
//   	cin >> m >> time;
//   	init();
//   	map<string, int> mp;
//   	for(int i=1; i<=m; i++) {
//   		string x, y;
//   		int t;
//   		cin >> x >> y >> t;
////   		cout << x << y << t << endl;
//   		if(mp[x] == 0) { mp[x] = ++count; arr[mp.size()] = x; }
//   		if(mp[y] == 0) { mp[y] = ++count, arr[mp.size()] = y; }
//   		int xid = mp[x], yid = mp[y];
//   		sum[xid] += t, sum[yid] += t;
//   		union_xy(xid, yid);
//   		time_sum[find_root(xid)] += t;
//   	}
//   	
//	int cnt = 0;
//   	for(int i=1; i<=mp.size(); i++) {
//   		if(pre[i]==-1 && time_sum[i]>time) {
//   			int max_id = i;
//   			for(int k=1; k<=mp.size(); k++) {
//   				if(pre[k]==i && sum[i] < sum[k]) {
//   					sum[i] = sum[k];
//   					max_id = k;
//   				}
//   			}
//   			rs[i] = max_id;
//   			if(nodes[i] > 2) 
//	   			cnt ++, is_gang[i] = true;
//   		}
//   	}
//   	printf("%d\n", cnt);
//   	for(int i=1; i<=mp.size(); i++) {
//   		if(pre[i] == -1 && is_gang[i]) {
//   			printf("%s %d\n", arr[rs[i]].data(), nodes[i]);
//   		}
//   	}
//    return 0;
//}








//#include <iostream>
//#include <vector>
//#include <map>
//#include <string.h>
//#include <algorithm>
//#define MAXN 1024<<2

//using namespace std;

//int n, cnt;
//int pre[MAXN], sum[MAXN], nodes[MAXN], all_time[MAXN];
//int max_sum_id[MAXN];

//void init() {
//	for(int i=1; i<MAXN; i++) 
//		pre[i] = -1, nodes[i] = 1;
//}

//int find_root(int x) {
//	int ret = x;
//	while(pre[ret] != -1) 
//		ret = pre[ret];
//	if(ret != x) pre[x] = ret;
//	return ret;
//}

//void union_xy(int x, int y) {
//	int rx = find_root(x), ry = find_root(y);
//	if(rx != ry) {
//		pre[ry] = rx;
//		nodes[rx] += nodes[ry];
//	}
//}
//string arr[MAXN];
//map<string, int> mp;

//int main()
//{
//    freopen("test", "r", stdin); 
//    int m, time;
//    init();
//    cin >> m >> time;
//    for(int i=1; i<=m; i++) {
//    	string x, y;
//    	int t;
//    	cin >> x >> y >> t;
//    	if(mp[x]==0) { mp[x]=(++cnt); arr[cnt]=x; }
//    	if(mp[y]==0) { mp[y]=(++cnt); arr[cnt]=y; };
//    	int xid = mp[x], yid = mp[y];
//    	sum[xid] += t, sum[yid] += t;
//    	union_xy(xid, yid);
//    	int r = find_root(xid);
//    	all_time[r] += t;
//    	int tmax = max(sum[xid], sum[yid]);
//    	int tmaxid = sum[xid] > sum[yid] ? xid : yid;
//    	if(max_sum_id[r] == 0) max_sum_id[r] = tmaxid;
//    	else {
//    		max_sum_id[r] = tmax > sum[max_sum_id[r]] ? tmaxid : max_sum_id[r];
//    	}
//    }
//    
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", pre[i]);
////    printf("\n");
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", sum[i]);
////    printf("\n");
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", nodes[i]);
////    printf("\n");
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", max_sum_id[i]);
////    printf("\n");
//	vector<int> rs1, rs2;
//	for(int i=1; i<=cnt; i++) {
//		if(pre[i]==-1 && all_time[i]>time && nodes[i]>2) 
//			rs1.push_back(max_sum_id[i]), rs2.push_back(i);
//	}
//	printf("%d\n", rs1.size());
//	for(int i=0; i<rs1.size(); i++) {
//		printf("%s %d\n", arr[rs1[i]].data(), nodes[rs2[i]]);
//	}
//    return 0;
//}




//#include <iostream>
//#include <vector>
//#include <map>
//#include <string.h>
//#include <algorithm>
//#define MAXN 1024<<2

//using namespace std;

//int n, cnt;
//int pre[MAXN], sum[MAXN], nodes[MAXN], all_time[MAXN];
////int max_sum_id[MAXN];
//vector<int> max_sum_id[MAXN];

//void init() {
//	for(int i=1; i<MAXN; i++) 
//		pre[i] = -1, nodes[i] = 1;
//}

//int find_root(int x) {
//	int ret = x;
//	while(pre[ret] != -1) 
//		ret = pre[ret];
//	if(ret != x) pre[x] = ret;
//	return ret;
//}

//void union_xy(int x, int y) {
//	int rx = find_root(x), ry = find_root(y);
//	if(rx != ry) {
//		pre[ry] = rx;
//		nodes[rx] += nodes[ry];
//	}
//}
//string arr[MAXN];
//map<string, int> mp;

//struct Node {
//	string name;
//	int people_count;
//};

//int cmp(Node& x, Node& y) { return x.name < y.name; }

//int main()
//{
//    freopen("test", "r", stdin); 
//    int m, time;
//    init();
//    cin >> m >> time;
//    for(int i=1; i<=m; i++) {
//    	string x, y;
//    	int t;
//    	cin >> x >> y >> t;
//    	if(mp[x]==0) { mp[x]=(++cnt); arr[cnt]=x; }
//    	if(mp[y]==0) { mp[y]=(++cnt); arr[cnt]=y; };
//    	int xid = mp[x], yid = mp[y];
//    	sum[xid] += t, sum[yid] += t;
//    	union_xy(xid, yid);
//    	int r = find_root(xid);
//    	all_time[r] += t;
//    	int tmax, tmaxid;
//    	if(sum[xid] > sum[yid]) {
//    		tmax = sum[xid];
//    		tmaxid = xid;
//    	} else {
//    		tmax = sum[yid];
//    		tmaxid = yid;
//    	}
//    	if(max_sum_id[r].empty()) {
//    		max_sum_id[r].push_back(tmaxid);
//    	} else if(max_sum_id[r][0] < tmax) {
//    		max_sum_id[r].clear();
//    		max_sum_id[r].push_back(tmaxid);
//    	} else if(max_sum_id[r][0] == tmax) {
//    		max_sum_id[r].push_back(tmaxid);
//    	}
//    }
//    
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", pre[i]);
////    printf("\n");
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", sum[i]);
////    printf("\n");
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", nodes[i]);
////    printf("\n");
////    for(int i=1; i<=cnt; i++)
////    	printf("%d,", max_sum_id[i]);
////    printf("\n");
//    for(int i=1; i<=cnt; i++)
//    	printf("%d,", max_sum_id[i].size());
//    printf("\n");
//    return 0;
//}











/**
 * 已经尽力了 考虑了一个团队有多个首领的情况 但是第三个点还是不过......
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 10086

using namespace std;

int n, m, cnt;
map<string, int> mp;

struct Node { 
	int id;
	string name;
	int time, nodes, all_time, max_time;
	set<int> max_ids; //存放time最大的下标们
	Node() : time(0), all_time(0), nodes(1), max_time(0) { }
	bool operator < (const Node& other) const {
		return this->name < other.name;
	}
} arr[MAXN];

int pre[MAXN];
void init() {
	for(int i=0; i<MAXN; i++)
		pre[i] = -1;
}

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = find_root(x), ry = find_root(y);
	if(rx != ry) {
		arr[rx].nodes += arr[ry].nodes;
		pre[ry] = rx;
	}
}

struct Rs { //要打印的结果
	string name;
	int team_count; //团队总人数
	bool operator < (const Rs& other) const {
		return this->name < other.name;
	}
}; 

int main()
{
    freopen("test", "r", stdin);
    init();
    cin >> n >> m; 
    for(int i=1; i<=n; i++) {
    	string x, y;
    	int t;
    	cin >> x >> y >> t;
    	if(mp[x]==0) { mp[x]=(++cnt); arr[cnt].name=x; arr[cnt].id=cnt; }
    	if(mp[y]==0) { mp[y]=(++cnt); arr[cnt].name=y; arr[cnt].id=cnt; }
    	int xid = mp[x], yid = mp[y];
    	arr[xid].time += t, arr[yid].time += t; //x和y的时间增加t
    	union_xy(xid, yid);
    	
    	// 以下代码union_xy后 更新time最大的节点的值
    	// 首领们的id, 最大time 都保存在根节点(pre[i]==-1)
    	int rid = find_root(xid);
    	arr[rid].all_time += t; //这个团体的总时长
    	int tmax, tmaxid, tag = false;
//    	printf("arr[%d]=%d   arr[%d]=%d\n", xid, arr[xid].time, yid, arr[yid].time);
    	if(arr[xid].time > arr[yid].time) {
    		tmax = arr[xid].time;
    		tmaxid = xid;
    	} else if(arr[xid].time < arr[yid].time) {
    		tmax = arr[yid].time;
    		tmaxid = yid;
    	} else {
    		tmax = arr[xid].time;
    		tmaxid = xid;
    		tag = true;
    	}
    	Node& nr = arr[find_root(xid)]; //根节点
    	set<int>& ids = nr.max_ids; //存放所有time最大de首领的id
    	if(ids.empty()) { //没有首领时 tmaxid为首领
    		ids.insert(tmaxid);
    		if(tag) ids.insert(yid);
    	} else {
    		int idx = *(ids.begin());
    		int& old_max = nr.max_time;
    		if(old_max > tmax) continue ;
    		else if(old_max < tmax) { //新的time更大 清空原来的首领id
    			old_max = tmax;
    			ids.clear();
    		}
    		ids.insert(tmaxid);
    		if(tag) ids.insert(yid);
    	}
    }
    
    set<Rs> rs;
    for(int i=1; i<=cnt; i++) { //求结果
    	if(-1==pre[i] && arr[i].all_time>m && arr[i].nodes>2) {
    		set<int>::iterator it = arr[i].max_ids.begin();
    		while(it != arr[i].max_ids.end()) {
//    			printf("%s, ", arr[*it].name.data());
				struct Rs temp;
				temp.name = arr[*it].name;
				temp.team_count = arr[i].nodes;
				rs.insert(temp);
    			it ++;
    		}
    	}
    }
    printf("%d\n", rs.size());
    set<Rs>::iterator it = rs.begin();
    while(it != rs.end()) {
    	cout << it->name << " " << it->team_count << endl;
    	it ++;
    }
    return 0;
}


