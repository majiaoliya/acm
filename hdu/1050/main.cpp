#include <iostream>
#include <list>
#include <vector>
#include <string.h>
using namespace std;

/**
  * 找公共区间 没有公共区间的桌子可以同时搬 有公共区间不可同时搬
  */
class Entry {
	public :
		int sid, eid; //起点和终点
		int dist; 
		bool moved; 
		Entry(int s, int e) : sid(s), eid(e), moved(false) {
			s = (s+1)/2, e = (e+1)/2;
			sid = s < e ? s : e;
			eid = s > e ? s : e;
			this->dist = abs(sid-eid);
		}
		
		int abs(int x) { return x > 0 ? x : -x; }

		bool overLap(Entry& other) { //判断是否有区间重叠
			int left = this->sid < other.sid ? this->sid : other.sid;
			int right = this->eid > other.eid ? this->eid : other.eid;
			int sub = abs(left-right);
			return sub <= (this->dist+other.dist);
		}
};

int main(void) {

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int tn;
		cin >> tn;
		/**
		int time = tn ? 10 : 0;
		
		list<Entry>* pl = new list<Entry>();
		list<Entry>& l = *pl;
		*/
		/**
		vector<Entry>* pl = new vector<Entry>();
		vector<Entry>& l = *pl;
		for(int k=0; k<tn; k++) {
			int s, e;
			cin >> s, cin >> e;
			Entry ety(s, e);
			l.push_back(ety);
			bool b = false;
			for(int j=0; j<l.size()-1; j++) {
				if(!ety.overLap(l[i])) {
					break;
				} else {
					b = true;
				}
			}
			if(b) time += 10;
		}
		*/
		/**
		for(list<Entry>::iterator iter=l.begin(); iter!=l.end(); iter++) {
			Entry& ety = *iter;
			if(!ety.moved) time += 10;
			ety.moved = true;
			for(list<Entry>::iterator next=iter; ++next != l.end(); ) {
				Entry& nety = *next;
				if(!ety.overLap(nety)) {
					nety.moved = true;
				}
			}
		}
		*/
		int road[202];
		int time = 0;
		memset(road, 0, sizeof(road));
		for(int k=0; k<tn; k++) {
			int s, e;
			cin >> s, cin >> e;
			int ss = (s+1)/2, ee = (e+1)/2;
			s = ss < ee ? ss : ee;
			e = ss > ee ? ss : ee;
			for(int j=s; j<=e; j++) {
				road[j]++;
			}
		}
		for(int k=0; k<202; k++) {
			if(time < road[k]) time = road[k];
		}
		cout << time*10 << endl;
	}

	return 0;
}







