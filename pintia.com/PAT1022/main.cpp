//#include <iostream>
//#include <vector>
//#include <map>
//#include <string.h>
//#include <algorithm>
//#define MAXN 100000

//using namespace std;

//int n;

//string my_sub(string& line, int lef, int rig) {
//	int len = rig-lef+1;
//	char buf[len+5];
//	memset(buf, false, sizeof(buf));
//	for(int i=0; lef<=rig; lef++) {
//		if(line[lef] != ' ')
//			buf[i++] = line[lef];
//	}
//	return buf;
//}

//string my_sub2(string& line, int lef, int rig) {
//	int len = rig-lef+1;
//	char buf[len+5];
//	memset(buf, false, sizeof(buf));
//	for(int i=0; lef<=rig; lef++) {
//		buf[i++] = line[lef];
//	}
//	return buf;
//}

//map<string, vector<string>> mp[7];

//int main()
//{
//    freopen("test", "r", stdin); 
////    ios::sync_with_stdio(false);
//    
//    cin >> n;
//    cin.ignore();
//    cin.ignore();
//    for( ; n--; ) {
//    	string line, id;
//    	for(int i=1; i<=6; i++) {
//			getline(cin, line);
//			if(i==1) {
//				id = line;
//			} else if(i==4) {
//    			int lef = 0;
//    			for(int k=0; k<line.length(); k++) { //一行分割成多个单词
//    				if(line[k]==' ' || k==line.length()-1) {
//    					string w = my_sub(line, lef, k-1);
////    					cout << w << ",";
//    					lef = k;
//    					if(w[w.length()-1] != 'r') w += '\r';
//    					mp[i][w].push_back(id);
//    				}
//    			}
//    		} else {
//    			mp[i][line].push_back(id);
////    			cout << line << endl;
//    		}
//    	}
//    }

//    int m;
//    cin >> m;
//	getchar();
//	getchar();
//    for(int i=1; i<=m; i++) {
//    	string line;
//    	getline(cin, line);
//    	cout << line << '\n';
//    	int tag = line[0]-'0';
//    	string key = my_sub2(line, 3, line.length()-1);
//    	map<string, vector<string>>& tm = mp[tag+1];
//    	vector<string>& tv = tm[key];

//    	if(tv.size()==0) { cout << "Not Found" << endl; }
//    	else {
//    		for(int j=0; j<tm[key].size(); j++) {
//    			string rs = tm[key][j];
//    			rs[rs.length()-1] = 0;
//    			cout << rs << '\n';
//    		}
//    	}
//    }
//    
//    return 0;
//}













#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <sstream>
#include <algorithm>

using namespace std;

int n;

map<string, vector<string>> mp[6]; 

int main()
{
//    freopen("test", "r", stdin); 
   	cin >> n;
   	getchar();
   	for(int t=n; t--; ) {
   		string id, line;
   		getline(cin, id);
   		for(int i=1; i<=5; i++) {
   			getline(cin, line);
   			if(i == 3) { //第三行特殊 需要分割
   				stringstream ss(line);
   				string w;
   				while(ss >> w) {
   					mp[i][w].push_back(id);
   				}
   			} else {
   				mp[i][line].push_back(id);
   			}
   		}
   	}
   	cin >> n;
   	getchar();
   	for(int i=1; i<=n; i++) {
   		string line;
   		getline(cin, line);
   		int tag = line[0]-'0';
   		int pos = 3;
   		string cmd = line.substr(pos);
   		map<string, vector<string>>& tm = mp[tag];
   		vector<string>& tv = tm[cmd];
   		cout << line << endl;
   		if(!tv.size()) {
   			printf("Not Found\n");
   		} else {
   			sort(tv.begin(), tv.end());
   			for(int k=0; k<tv.size(); k++) {
   				printf("%s\n", tv[k].data());
   			}
   		}
   	}
    return 0;
}


