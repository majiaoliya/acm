#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define MAX 100005

using namespace std;

int n;

struct Person {
	string fst_name, lst_name, pre_name; //姓名
	int pre_id; //父节点下标
	bool is_man; //是不是男
	Person() : is_man(false), pre_id(-1) { }
};

int bcj_pre[MAX]; //并查集pre[] 
Person ps[MAX]; //人数组 等下按名字排序

int cmp(Person& x, Person& y) { return x.lst_name < y.lst_name; } //按名排序

void do_str(Person& p) { //处理这个人的名字, 设置性别, 设置父名
	string& str = p.fst_name;
	int tag = 0; // -1男   1女   0额....
	int left=0, right=0;
	int len = str.length();
	if(str[len-1]=='n' && str[len-2]=='o' && str[len-3]=='s') 
		tag = -1, right=len-4; //判男
	else if(str[len-1]=='r' && str[len-2]=='i' && str[len-3]=='t')
		tag = 1, right=len-7; //判女
	else if(str[len-1]=='m') tag = -1;
	else if(str[len-1]=='f') tag = 1	;
	if(-1 == tag) p.is_man = true;
	char buf[len];
	for( ; left<right; )
		buf[left] = str[left], left ++;
	buf[left] = '\0';
	p.pre_name = buf;
}

/*
	我的思路是这样的 
	处理名字
	按名字排序
	然后建一个parent数组 用二分查找找每个人对应的父亲
	判断时 用二分查找找到人 然后找包含他在内的4个祖先，
	这样检查最多两个人的4个祖先有没有相同就能判定了
*/

int bin_search(Person& be_search) { //二分 
	string& t = be_search.lst_name;
	int left = 0, right = n-1, mid = (left+right)/2;
	while(left < right) {
		mid = (left+right)/2;
		if(t==ps[mid].lst_name) return mid;
		else if(t>ps[mid].lst_name) left = mid+1;
		else if(t<ps[mid].lst_name) right = mid-1;
	}
	return -1;
}

int bin_search(string be_search) { //二分重载
	string& t = be_search;
	int left = 0, right = n-1, mid = (left+right)/2;
	while(left < right) {
		mid = (left+right)/2;
		if(t==ps[mid].lst_name) return mid;
		else if(t>ps[mid].lst_name) left = mid+1;
		else if(t<ps[mid].lst_name) right = mid-1;
	}
	return -1;
}

int main(void) {
	freopen("test", "r", stdin);
	cin >> n;
	
	for(int i=0; i<n; i++) { //输入姓名
		cin >> ps[i].lst_name >> ps[i].fst_name;
	}
	sort(ps, ps+n, cmp); //按名排序
	
	for(int i=0; i<n; i++) {
		do_str(ps[i]); //处理名字 设置性别
	//	cout << i << " : " << ps[i].lst_name << "-" << ps[i].fst_name << " pid:" << bin_search(ps[i].pre_name) << endl;
	}
	
	int t;
	cin >> t;
	for( ; t--; ) {
		Person x, y;
		cin >> x.lst_name >> x.pre_name >> y.lst_name >> y.pre_name;
	}
	
	return 0;
}
