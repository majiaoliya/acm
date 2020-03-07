#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif

#include "mycurl.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

//https://i.nyahentai.net/galleries/1368241/6.jpg
string str = "https://i.nyahentai.net/galleries/1368241/";
string suf = ".jpg";
string name;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	myinit();
	for(int i=1; i<=10; i++) {
		string url_str = str + std::to_string(i) + suf;
		printf("[%s]\n", url_str.data());
		name = std::to_string(i) + suf;
		int write_len = read_img(url_str.data(), name.data());
		if(!write_len) { 
//			printf("第%d张size为0.", i);
			printf("\033[40;31m第%d张size为%d.\033[0m", i, write_len);
	   	} else {
//			printf("第%d张完成 大小:%d\n", i, write_len);
			printf("\033[40;32m第%d张完成 大小:%d\n\033[0m", i, write_len);
		}
	}


	myclean();


//printf("\033[字背景颜色;字体颜色m字符串\033[0m" );
//printf("\033[47;31mThis is a color test.\033[0m");



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

