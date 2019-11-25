#include <iostream>
#include <vector>
#include <map>
#include <string>
#define MAX 100005

using namespace std;
int n;
float m, k, sum=0;

struct Person {
	float gong_li; //功力值
	bool is_get; //是否是得道者
	int bei_shu; //得道者放大的倍数
	vector<int> chl; 
	Person() : is_get(false) { }
};

Person vs[MAX];

void dfs(int root) {
	Person& r = vs[root];
	printf("gl%d:%f\t%s\n", root, r.gong_li, r.is_get ? "yes":"no");
	for(int i=0; i<r.chl.size(); i++) {
		if(vs[r.chl[i]].is_get) { //这个root的弟子是得道者
			vs[r.chl[i]].gong_li = r.gong_li*vs[r.chl[i]].bei_shu; //放大功力
			sum += vs[r.chl[i]].gong_li;
		} else {
			vs[r.chl[i]].gong_li = r.gong_li - r.gong_li*k*.01; //功力down
		}
		dfs(r.chl[i]); //继续向下
	}
}

int main(void) {
	freopen("test", "r", stdin);
	
	scanf("%d %f %f", &n, &m, &k);
	vs[0].gong_li = m; //祖师爷功力
	
	for(int i=0; i<n; i++) {
		int t;
		scanf("%d", &t);
		if(t == 0) { //得道者
			scanf("%d", &vs[i].bei_shu);
			vs[i].is_get = true;
		} else {
			for( ; t--; ) {
				int x;
				scanf("%d", &x);
				vs[i].chl.push_back(x);
			}
		}
	}
	for(int i=0; i<n; i++) {
		printf("%d : ", i);
		for(int k=0; k<vs[i].chl.size(); k++) {
			printf("->%d ", vs[i].chl[k]);
		}
		printf("\t%s\n", vs[i].is_get ? "Yes" : "No");
	}
	dfs(0);
	printf("sum:%f\n", sum);
	
	return 0;
}
