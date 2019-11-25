#include <iostream>
#include <vector>
#include <map>
#include <string>
#define MAX 100005

using namespace std;

int n;

map<string, int> map1;
string fst_name[MAX];
string lst_name[MAX];
bool is_man[MAX]; //判断性别
int pre[MAX];
int bcj_pre[MAX]; //并查集pre[] 

string sub(string& str, int id) { //截子串 billsson->返回bill(即父节点name)
	int tag = 0; // -1男   1女   0额....
	int len = str.length();
	if(str[len-1]=='n' && str[len-2]=='o' && str[len-3]=='s') tag = -1; //判男
	else if(str[len-1]=='r' && str[len-2]=='i' && str[len-3]=='t') tag = 1; //判女
	else if(str[len-1]=='m') tag = -1;
	else if(str[len-1]=='f') tag = 1;
	
//	return tag==-1 ? "男" : 1==tag ? "女" : "额....";
	int left = 0, right = 0;
	if(-1==tag) right = len-4, is_man[id] = true;
	else if(1==tag) right = len-7;
	char buf[len];
	for( ; left<right; )
		buf[left] = str[left], left ++;
	buf[left] = '\0';
	return buf;
}

int find_root(int x) { //并查集找根
	int ret = x;
	while(bcj_pre[ret] != -1)
		ret = bcj_pre[ret];
	if(ret != x) 
		bcj_pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) { //并查集的并
	int root_x = find_root(x);
	int root_y = find_root(y);
	if(root_x != root_y)
		bcj_pre[root_y] = root_x;
}

bool check(int x_id, int y_id) { //检查x与y
	if(is_man[x_id] == is_man[y_id]) { //同性 不可通婚
		cout << "Whatever" << endl;
		return false;
	}
	
	bool in_same_set = (find_root(x_id) == find_root(y_id)); //并查集判断是否在同一集合
	if(!in_same_set) { //异性 不同祖先 直接yes
		cout << "Yes" << endl;
		return true;
	}
	
	{ //判断是否嫡系
		bool is_dixi = false; //判断x和y是否是嫡系 找x的祖先是y 或 y的祖先是x
		int pre_x = x_id, pre_y = y_id;
		while(pre_x != -1) { // 找x的祖先是y
			if(pre[pre_x] == y_id) {
				is_dixi = true;
				break;
			}
			pre_x = pre[pre_x];
		}
		while(pre_y != -1) { // y的祖先是x
			if(pre[pre_y] == x_id) {
				is_dixi = true;
				break;
			}
			pre_y = pre[pre_y];
		}
		if(is_dixi) { //找到就KO
			cout << "No" << endl;
			return false;
		}
	}
	
	{ //不是嫡系
		int count_x=0, count_y=0, pre_x=x_id, pre_y=y_id;
		while(true) {
			if(pre_x==pre_y) break; //发现5代以内同根 break
			if(count_x>=4 && count_y>=4) break; //两个都超过4代没发现同根 break
			if(pre_x != -1)
				pre_x = pre[pre_x], count_x++;
			if(pre_y != -1)
				pre_y = pre[pre_y], count_y++;
		}
		
		if(pre_x==pre_y && (count_x<4||count_y<4)) { //5代以内有同根
			cout << "No" << endl;
			return false;
		}
		if(count_x>=4 && count_y>=4) {
			cout << "Yes" << endl;
			return true;
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	cin >> n;
	for(int i=1; i<=n; i++) pre[i] = -1, bcj_pre[i] = -1; //初始化pre[]
	
	for(int i=1; i<=n; i++) { //输入每个人的数据
		cin >> lst_name[i] >> fst_name[i];
		map1[lst_name[i]] = i; //map映射名字和下标 通过名字查找到下标
	}
	
	for(int i=1; i<=n; i++) { //通过每个人的下标和父节点下标建立树型
		int pre_id = map1[sub(fst_name[i], i)]; //
		if(pre_id) {
			pre[i] = pre_id;
			union_xy(pre_id, i); //并查集的join操作
		}
	}
	
	int t;
	cin >> t;
	for( ; t--; ) { //t次询问
		string x_fst_name, x_lst_name, y_fst_name, y_lst_name;
		cin >> x_lst_name >> x_fst_name >> y_lst_name >> y_fst_name; //输入姓名
		int x_id = map1[x_lst_name], y_id = map1[y_lst_name];
		if(x_id==0 || y_id==0) //有一个不在列表里
			cout << "NA" << endl;
		else
			check(x_id, y_id); //对每次询问调check()
	}
	return 0;
}
