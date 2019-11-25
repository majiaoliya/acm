//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	freopen("test","r",stdin);
//	map<int,float>m;
//	map<int, float>::reverse_iterator it;

//	int n;
//	cin>>n;
//	while(n--) {
//		int a; float b;
//		cin>>a>>b;
//		m[a]+=b;
//	}
//	cin>>n;
//	while(n--) {
//		int a; float b;
//		cin>>a>>b;
//		m[a]+=b;
//	}
//	int f=0;
//	map<int, float>::iterator tit = m.begin();
//	vector<map<int, float>::iterator> rmv;
//	while(tit != m.end()) {
//		if(tit->second == 0.0000)
//			rmv.push_back(tit);
//		tit ++;
//	}
//	for(int i=0; i<rmv.size(); i++)
//		m.erase(rmv[i]);
//	cout<<m.size();
//	for(it=m.rbegin();it!=m.rend();it++){
//		cout<< " " << it->first<<" "<<it->second;
//	}
//} 







#include<bits/stdc++.h>
using namespace std;
map<int, double> m;

int main(){
	freopen("test","r",stdin);
	int n;
	cin >> n;
	for( ; n--; ) {
		int mi; double xishu;
		cin >> mi >> xishu;
		m[mi] += xishu;
	}
	cin >> n;
	for( ; n--; ) {
		int mi; double xishu;
		cin >> mi >> xishu;
		m[mi] += xishu;
		if(m[mi] == 0.000)
			m.erase(mi);
	}
	
	cout << m.size();
	map<int, double>::reverse_iterator it = m.rbegin();
	while(it != m.rend()) {
//		cout << " " << it->first << " " << it->second;
//		printf(" %d %.1lf", it->first, it->second);
		if(it->second != 0.000)
		cout<< " " << it->first<<setiosflags(ios::fixed)<<setprecision(1) << " "<<it->second;
		it ++;
	}
	
} 
