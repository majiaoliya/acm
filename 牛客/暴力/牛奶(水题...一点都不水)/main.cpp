#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 50005
//链接：https://ac.nowcoder.com/acm/problem/13592
//武藏牌牛奶为了吸引顾客，推出优惠活动，可以使用x个空的瓶身，**或者**y个瓶盖，去商店换一瓶全新的武藏牌牛奶。注意，一瓶牛奶包含了瓶身和瓶盖。
//现在小萌老师有a个空的瓶身和b个瓶盖，她想喝到尽可能多的牛奶，你知道她到底能喝到多少瓶完整的牛奶吗？ 

using namespace std;
int x, y, a, b;
//抄网上的, 一点都不水好吗... 我完全想不到该怎么写....
int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d %d %d", &x, &y, &a, &b); ) {
		bool tag = false;
		int ans = 0;
		if(x == 1 || y == 1) tag = true;
		if(!tag) {
			while(a>=x || b>=y) {
				ans += a/x + b/y;
				int i = a, j = b;
				a = i%x + i/x + j/y;
				b = j%y + i/x + j/y;
				if(a>=i && b>=j) {
					tag = true;
					break;
				}
			}
		}
		if(tag) printf("INF\n");
		else printf("%d\n", ans);
	}
	
	return 0;
}

