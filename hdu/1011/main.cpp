#include <iostream> 
#include <vector>
using namespace std;

/**
template <typename T>
class Node {
	public:
		T data;
		Node* parent;
		vector<Node*> childs;

		Node(T _data, Node* _par) : data(_data), parent(_par) { }
		~Node() {
			for(int i=0; i<childs.size(); i++)
			  delete childs[i];
		}
		
		bool operator == (Node node) { return this->data == other.data; }
		bool operator == (T other) { return this->data == other; }

		void add(Node* child) {
			if(child != 0)
				this->childs.push_back(child);
		}
		void add(T _data) {
			Node* node = new Node(_data, this);
			this->add(node);
		}

		bool remove(T _d) {
			std::vector<Node*>::iterator iter = this->childs.begin();
			bool ret = false;
			for( ; iter != this->childs.end(); iter++) {
				Node* n = *iter;
				if(*n == _d) {
					delete n;
					this->childs.erase(iter);
					ret = true;
					break;
				}
			}
			return ret;
		}
};

class Tree {
	public :
		Node* root;
		Tree() : root(0) { }
		~Tree() { delete root; }
};
*/
/** 可以得到结果 但是不能ac
class Room {
	public:
		int bugs;
		int value;
		int pid;
		int spend; //消耗的队员数量
		vector<int> childs;
		int dp;

		Room() { }
		Room(int b, int v) : bugs(b), value(v), pid(0), dp(0) {
			if(bugs%20) this->spend = (bugs/20) + 1;
			else this->spend = (bugs/20);
		}
		inline bool canF(int sur) { return this->bugs <= sur*20; }
};

//bool canF(Room& r, int sur) { return r.bugs <= sur*20; }

int bt(vector<Room>& rooms, int i, int sur, int sum) {
	if(rooms[i].canF(sur)) {
		vector<int>& childs = rooms[i].childs;
		int max = sum;
		for(int k=0; k<childs.size(); k++) {
			int t = sum + bt(rooms, childs[i], sur-rooms[i].spend, sum);
			if(max < t) {
				max = t;
			}
		}
		return max + rooms[i].value;
	}
	return sum;
}

int main(void) {

	int n, m;
	for( ; cin>>n, cin>>m, n!=-1, m!=-1; ) { 
		vector<Room> tree;
		for(int i=0; i<n; i++) { //输入洞穴
			int tBugs, tValue;
			cin >> tBugs; cin >> tValue;
			Room room(tBugs, tValue);
			tree.push_back(room);
		}
		for(int i=0; i<n-1; i++) { //建立树型
			int par, child;
			cin >> par, cin >> child;
			par --, child --;
			tree[par].childs.push_back(child);
			tree[child].pid = par;
		}

		//状态转移方程: dp[i] = max(dp[par], dp[par]+value[i])
		int max = 0;
		int tMax = max;
		int sur = m;
		int sum = 0;
		max = bt(tree, 0, sur, sum);
		cout << max << endl;
		cout << "size: " << sizeof(tree) << endl;
	}

	return 0;
}
*/

/* 注释时间2019_6_6 13:06
#include <queue>

class Room {
	public:
		int bugs;
		int value;
		int spend;
		int parent;
		int dp;
		int maxSpend;
		vector<int> childs;

		Room() : bugs(0), value(0), spend(0), parent(-1), dp(0), maxSpend(0) { }
		Room(int b, int v) : bugs(b), value(v), parent(-1), dp(0), maxSpend(0) {
			if(b%20) this->spend = b/20+1;
			else this->spend = b/20;
		}
		Room(int b, int v, int par) : bugs(b), value(v), parent(par), dp(0), maxSpend(0) {
			if(b%20) this->spend = b/20+1;
			else this->spend = b/20;
		}
		bool canF( int sur) {
			if(this->bugs <= sur*20) return true;
			else return false;
		}
		static int max(int x, int y) { return x > y ? x : y; }
};

int main(void) {
	
	int n, m;
	for( ; cin>>n, cin>>m, n!=-1, m!=-1; ) { 
		vector<Room>* rs = new vector<Room>();
		vector<Room>& rooms = *rs;
		for(int i=0; i<n; i++) { //输入洞穴
			int tBugs, tValue;
			cin >> tBugs; cin >> tValue;
			Room room(tBugs, tValue);
			rooms.push_back(room);
		}

		for(int i=0; i<n-1; i++) {
			int par, chl;
			cin >> par, cin >> chl;
			par --, chl --;
			rooms[chl].parent = par;
			rooms[par].childs.push_back(chl);
		}

		int max = 0;
		if(rooms[0].canF(m)) {
			rooms[0].dp = rooms[0].value;
			rooms[0].maxSpend = rooms[0].spend;
			if(max < rooms[0].dp) max = rooms[0].dp;
		} else {
			cout << 0 << endl;
			continue;
		}

		std::queue<int>* pq = new std::queue<int>();
		std::queue<int>& q = *pq;

		q.push(0); //根节点入队列

		while(!q.empty()) {
			Room& cur = rooms[q.front()];
			q.pop();
			for(int i=0; i<cur.childs.size(); i++) {
				q.push(cur.childs[i]);
			}
			if(cur.parent != -1) { //有父节点
				Room& par = rooms[cur.parent];
				cur.maxSpend = par.maxSpend + cur.spend; //当前消耗
				if(cur.canF(m-par.maxSpend)) {
					//cur.dp = par.dp + cur.value;
					cur.dp = Room::max(par.dp, (par.dp+cur.value));
				} else {
					cur.dp = par.dp;
				}
				if(cur.dp > max) max = cur.dp;
			} else { //无父节点
				cur.maxSpend = cur.spend;
				if(cur.canF(m)) {
					cur.dp = cur.value;
				} else {
					cur.dp = 0;
				}
				if(cur.dp > max) max = cur.dp;
			}
		}
		
		cout << max << endl;

	}

	return 0;
}

*/

/** 错误做法dfs 反例:https://www.cnblogs.com/cglongge/p/10305771.html
    8 2
	0 0
	0 9
	0 8
	0 4
	0 7
	0 3
	0 2
	0 1
	1 2
	1 3
	2 4
	2 5
	4 6
	6 7
	7 8
*  应该使用dfs+dp
*/
/**
#include <iostream>
#include <vector>
#define MY_MAX(x, y) ((x>y ? x : y))
#define MAXN 1005
using namespace std;
int n, m, rs, vis[MAXN]; //n个room k个士兵 rs结果

struct Room {
	int bugs, value;
} arr[MAXN];

vector<int> G[MAXN];
void init() {
	rs = 0;
	for(int i=1; i<=n; i++) {
		G[i].clear();
		vis[i] = false;
	}
}

void dfs(int x, int hav, int trs) {
	vis[x] = true;
	int cost = arr[x].bugs / 20; //消耗的队员数量
	if(arr[x].bugs % 20) cost ++;
	if(hav >= cost) { //能打
		int now_hav = hav - cost, now_rs = trs + arr[x].value;
		rs = MY_MAX(rs, now_rs);
		for(int i=0; i<G[x].size(); i++) {
			int chl = G[x][i];
			if(vis[chl]) continue;
			dfs(chl, now_hav, now_rs);
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF!=scanf("%d %d", &n, &m) && n!=-1 && m!=-1; ) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d %d", &arr[i].bugs, &arr[i].value);
		}
		for(int i=1, x, y; i<n; i++) {
			scanf("%d %d", &x, &y);
			G[x].push_back(y), G[y].push_back(x);
		}
		dfs(1, m, 0);
		printf("%d\n", rs);
	}
	return 0;
}
*/


#include <iostream>
#include <vector>
#define MY_MAX(x, y) ((x>y ? x : y))
#define MAXN 105
using namespace std;
#include <string.h>
int n, m, rs, vis[MAXN]; //n个room k个士兵 rs结果
int dp[MAXN][MAXN]; //第i个点放j个人的价值

struct Room {
	int bugs, value;
} arr[MAXN];

vector<int> G[MAXN];
void init() {
	rs = 0;
	memset(dp, false, sizeof(dp));
	for(int i=1; i<=n; i++) {
		G[i].clear();
		vis[i] = false;
	}
	vector<int> v;
	
}

void dfs(int x) {
	vis[x] = true;
	int cost = arr[x].bugs / 20;
	if(arr[x].bugs % 20) cost ++;
	for(int i=cost; i<=m; i++) 
		dp[root][i] = arr[root].value; //小于cost无法获得value
	vis[x] = true;
	for(int i=0; i<G[root].size(); i++) {
		int chl = G[root][i];
		if(vis[chl]) continue;
		dfs(chl);
		
	}
}

struct temp {
	int a, b, c, d;
	void fuck() {

	}
	int shit(int a) {
		return 0;
	}
	bool operator < (string& str) {

	}
};

int main(void) {
	freopen("test", "r", stdin);
	temp te;
	
	for( ; EOF!=scanf("%d %d", &n, &m) && n!=-1 && m!=-1; ) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%d %d", &arr[i].bugs, &arr[i].value);
		}
		for(int i=1, x, y; i<n; i++) {
			scanf("%d %d", &x, &y);
			G[x].push_back(y), G[y].push_back(x);
		}
	}
	return 0;
}


