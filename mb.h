#define debug
#ifdef debug
#include <time.h>
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <unordered_set>

using namespace std;

template <typename T>
void read(T& x) {
    int f = 1; x = 0;
    char ch = getchar();

    while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

template <typename T>
inline void forarr(T* arr, int lef, int rig, string str="") {
	cout << str << " : ";
	for(int i=lef; i<=rig; i++)
		cout << "[" << arr[i] << "] ";
	cout << endl;
}

inline void forvec(vector<int>& v, int lef=-1, int rig=-1, string str="") {
	lef = max(lef, 0), rig = max(rig, (int)v.size()-1);
	printf("%s: ", str.data());
	for(int i=lef; i<=rig; i++)
		printf("[%d], ", v[i]);
	printf("\n");
}

//打印集合
template <typename T>
void forit(T& list, int lef=-1, int rig=-1, string str="") {
	cout << str << " : ";
	typename T::iterator it = list.begin();
	typename T::iterator itend = list.end();
	if(lef != -1) it += lef;
	while(it != itend) {
		cout << "[" << *it << "], ";
		it ++;
	}
	cout << endl;
}

//打印图
void forvvi(vector<vector<int> >& G, string str="") {
	cout << str << " : \n";
	int i = 1;
	for(auto x : G) {
		cout << i++ << ": ";
		for(auto y : G[i]) {
			cout << "->" << y << " ";
		}
		cout << endl;
	}
}


