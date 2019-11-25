#include <iostream>
#include <string.h>
using namespace std;
string num;
struct XY {
	int x, y;
	XY(int r, int c) : x(r), y(c) { }
};
bool vis[3][3];
XY arr[] = {XY(0, 0), XY(0,1), XY(0,2),
			XY(1, 0), XY(1,1), XY(1,2),
			XY(2, 0), XY(2,1), XY(2,2)};

bool check(int before, int x) {
	bool ret = false;
	if(x==1 && (before==2||before==4||before==5)) ret = true;
	else if(x==2 && (before==1||before==3||before==5)) ret = true;
	else if(x==3 && (before==2||before==6||before==5)) ret = true;
	else if(x==4 && (before==1||before==5||before==7)) ret = true;
	else if(x==5 && (before==1||before==2||before==3||
			before==4||before==6||before==7||before==8||
			before==9)) ret = true;
	else if(x==6 && (before==5||before==3||before==9)) ret = true;
	else if(x==7 && (before==4||before==5||before==8)) ret = true;
	else if(x==8 && (before==7||before==5||before==9)) ret = true;
	else if(x==9 && (before==8||before==5||before==6)) ret = true;
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; getline(cin, num) && !num.empty(); ) {
		for(int i=0; i<3; i++)	
			for(int k=0; k<3; k++)
				vis[i][k] = false;
		vis[arr[num[0]].x][arr[num[0]].y] = true;
		bool tag = true;
		for(int i=1; i<num.length(); i++) {
			int x = arr[num[i]].x, y = arr[num[i]].y;
			if(vis[x][y]) {
				tag = false; 
				break;
			} else { //这个数字的前一个数字必须来自他四周
				vis[x][y] = true;
				if(!check(num[i-1], num[i])) {
					tag = false;
				}
			}
		}
		printf("%s\n", tag ? "YES":"NO");
	}
	
	return 0;
}
