#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 这里用的是贪心法
 * Entry封装兑换javaBean所需的catFood,
 */

class Entry {
	public :
		friend ostream& operator <<(ostream& out, Entry& e) {
			out << "[cf:" << e.catFood << " jb:" << e.javaBean << " u:" << e.unit;
			return out;
		}
	public :
		double unit; //该房间的性价比 unit = catFood / javaBean
		double catFood;
		double javaBean;
		int index; //房间下标 暂时未使用
		
		Entry(int i, double jb, double cf) : unit(jb/cf), index(i) {
			this->catFood = cf;
			this->javaBean = jb;
		}
	
		
		~Entry() { }

		bool operator > (Entry other) {	return this->unit > other.unit; }
		bool operator < (Entry other) {	return this->unit < other.unit; }
		bool operator == (Entry other) { return this->unit == other.unit; }
};

int main(void) {

	int m, n;
	for( ; cin>>m, cin>>n, m!=-1 && n!=-1; ) {
		vector<Entry> es;
		int catFood[n+1];
		int javaBean[n+1];
		for(int i=1; i<=n; i++) {
			cin >> javaBean[i];
			cin >> catFood[i];
			Entry e(i, javaBean[i], catFood[i]);
			es.push_back(e);
		}
		
		sort(es.begin(), es.end()); //把房间按性价比排序

/**
		for(int i=0; i<es.size(); i++) {
			cout << es[i] << ",";
		}

		cout << endl;
*/
		double max = 0;
		for(int i=es.size()-1; i>=0 && m>0; i--) {
			if(m>=es[i].catFood) {
				max += es[i].javaBean;
				m -= es[i].catFood;
			} else {
				max += es[i].unit * m;
				m = 0;
			}
		}
		printf("%.3f\n", max);
	}

	return 0;
}
