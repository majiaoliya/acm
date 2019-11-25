#include <iostream>
#include <stack>
#include <limits>
#include <string>
using namespace std;

class Coor { //坐标类
	public :
		friend ostream& operator << (ostream& out, Coor& coor) {
			out << "(" << coor.x << "," << coor.y << ")";
			return out;
		}
	public :
		int x, y;
		Coor() { }
		Coor(int _x, int _y) : x(_x), y(_y) { }
		bool operator == (Coor other) {
			return (this->x == other.x) && (this->y == other.y); 
		}
		void operator = (Coor other) {
			this->x = other.x;
			this->y = other.y;
		}
};

int abs(int x) { return x < 0 ? -x : x; }

bool cut(int x, int y, int level, Coor& door, int row, int col, int& time) {
	bool ret = true;
	do {
		int sur = time - level; //剩余步数
		int minDist = abs(door.x-x) + abs(door.y-y);
		
		if(row*col < time) break;
		if(sur < minDist) break;
		if(sur%2 != minDist%2) break;

		ret = false;
	} while(0);
	
	return ret;
}

void bt(int level, bool& find, int& time, Coor dogCoor, Coor& door, char** matix, int row, int col) {
	if(dogCoor == door) {
		if(level == time) {
			find = true;
		}
/**
		for(int i=0; i<row; i++) {
			for(int k=0; k<col; k++)
			  printf("%c\t", *((char*)matix+ col*i + k));
			printf("\n");
		}
		printf("\n");
*/
		return;
	}

	int dx = dogCoor.x;
	int dy = dogCoor.y;

	if( cut(dx, dy, level, door, row, col, time) ) return; //剪枝

	char* m = (char*) matix;
	if(*(m+col*dx+dy) == 'X') {
		cout << "error" << endl;
		return;
	}
	*(m+col*dx+dy) = '*'; //标记当前狗的位置为已访问

	if(!find && dx-1 >= 0 && *(m+col*(dx-1)+dy) != 'X' && *(m+col*(dx-1)+dy) != '*') { //左
		Coor next(dx-1, dy);
		bt(level+1, find, time, next, door, matix, row, col); //回溯
	}
	if(!find && dy-1 >= 0 && *(m+col*(dx)+dy-1) != 'X' && *(m+col*dx+dy-1) != '*') { //上
		Coor next(dx, dy-1);
		bt(level+1, find, time, next, door, matix, row, col);
	}
	if(!find && dx+1 < row && *(m+col*(dx+1)+dy) != 'X' && *(m+col*(dx+1)+dy) != '*') { //右
		Coor next(dx+1, dy);
		bt(level+1, find, time, next, door, matix, row, col);
	}
	if(!find && dy+1 < col && *(m+col*dx+dy+1) != 'X' && *(m+col*dx+dy+1) != '*') { //下
		Coor next(dx, dy+1);
		bt(level+1, find, time, next, door, matix, row, col);
	} 
	*(m+col*dx+dy) = '.'; //复原

}

int main(void) {

	int row, col, time;
	for( ; cin>>row, cin>>col, cin>>time, row!=0 && col!=0 && time!=0; ) {
		char buf[row][col];
		Coor dogCoor, door;
		for(int i=0; i<row; i++) {
			cin >> buf[i];
			for(int k=0; k<col; k++) {
				if(buf[i][k] == 'S') dogCoor = Coor(i, k);
				else if(buf[i][k] == 'D') door = Coor(i, k);
			}
		}
		

		bool find = false;
		std::string result = "NO";
		bt(0, find, time, dogCoor, door, (char**)buf, row, col);
		//cout << "find: " << find << endl;
		if(find) result = "YES";
		else result = "NO";
		cout << result << endl;
	}

	return 0;
}







/**
#include <iostream>
#include <stack>
#include <limits>
#include <string>
using namespace std;

class Coor { //坐标类
	public :
		friend ostream& operator << (ostream& out, Coor& coor) {
			out << "(" << coor.x << "," << coor.y << ")";
			return out;
		}
	public :
		int x, y;
		Coor() { }
		Coor(int _x, int _y) : x(_x), y(_y) { }
		bool operator == (Coor other) {
			return (this->x == other.x) && (this->y == other.y); 
		}
		void operator = (Coor other) {
			this->x = other.x;
			this->y = other.y;
		}
};

int main(void) {

	int n, m, time; // n * m的迷宫
	for( ; cin>>n, cin>>m, cin>>time, n && m && time; ) {
		char matix[n][m];
		Coor dogCoor; //狗的位置
		Coor door; //门的位置 
		for(int i=0; i<n; i++) { //初始化迷宫
			for(int k=0; k<m; k++) {
				cin >> matix[i][k];
				if(matix[i][k] == 'S') dogCoor = Coor(i, k);
				else if(matix[i][k] == 'D') door = Coor(i, k);
			}
		}

		std::stack<Coor> cs; //存放坐标的栈
		int timeCount = INT8_MAX; //记录时间
		int minTime = INT8_MAX; //走出迷宫需要的最小时间
		
		std::string result = "NO";

		cs.push(dogCoor); //狗的起点入栈
		for( ; !cs.empty(); ) { //遍历栈顶的三条路是否可走 (用 '*' 标记为已访问)
			
			if(dogCoor == door) { //狗已经到门的位置 记录这条路径并返回上一层状态
				cout << "find an dist" << endl;
				for(int i=0; i<n; i++) {
					for(int k=0; k<m; k++) {
					  	printf("%c\t", matix[i][k]);
					}
					cout << endl;
				}

				if(timeCount <= time) { //这条路径时间充足
					result = "YES";
					break;
				} else if(minTime > timeCount) { //记录最短时间(好像没什么意义...)
					minTime = timeCount;
				}
				continue;
			}

			matix[dogCoor.x][dogCoor.y] = '*'; //标记为已经走过

			

			for(int i=0; i<n; i++) {
				for(int k=0; k<m; k++) {
					printf("%c\t", matix[i][k]);
				}
				cout << endl;
			}

			cout << dogCoor << endl;
		}

	}

	return 0;
}
*/
