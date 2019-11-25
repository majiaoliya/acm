
#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>

#define MAX 10005
using namespace std;
int n, m;
vector<int> rs;
int yilai[MAX]; //记录依赖, 如果x没有依赖的数(yilai[x]==0) 则x特立独行
bool is_xingfu[MAX]; //记录x是否是幸福数
int count_xf[MAX]; //记录x的独立值

int ping_fang_he(int x) { //计算x的平方和
	int sum = 0;
	while(x) {
		int t = x%10;
		sum += t*t;
		x /= 10;
	}
	return sum;
}
/**
bool is_shusu(int x) { //判断是否是素数
	if(x == 1 || x == 0) return false;
	int t = sqrt(x);
	bool ret = true;
	for(int i=2; i<=t; i++) 
		if(i%x == 0) {
			ret = false;
			break;
		}
	return ret;
}
*/

int is_shusu(int x)   //判素数
{
	int i;
	//if(x == 1 || x == 0) return 0;
	i = 2;
	while(i <= sqrt(x))
	{
		if(x % i == 0)
			return 0;
		i ++;
	}
    return 1;
}

int xfshu(int x) { //记录x的幸福数
	int count = 0, pre = x;
	if(pre == 1) count = 1;
	bool vis[MAX]; //标记是否访问
	memset(vis, false, sizeof(vis));
	vector<int> pfhs;	
	while(pre != 1) {
		if(vis[pre]) { //出现死循环 标记不幸福
			count = 0; 
			pfhs.clear();
			break;
		}
		count ++; //幸福计数 
		vis[pre] = true;
		pre = ping_fang_he(pre); //下一个平方和
		pfhs.push_back(pre); //把这次迭代的数保存
	}
	//printf("count:%d---", count);
	if(count) { //如果x是幸福数 那他每次迭代的数都是幸福数
		if(is_shusu(x)) //素数的幸福翻倍 
			count <<= 1; //count *= 2
		count_xf[x] = count;
		is_xingfu[x] = true; 
		int tpre = x;
		for(int i=0; i<pfhs.size(); i++) {
			is_xingfu[pfhs[i]] = true;
			yilai[pfhs[i]] = tpre; //设置依赖
			tpre = pfhs[i];
		}
		return x;
	}
	return 0;
}

int main(void) {

//	freopen("test", "r", stdin);
//	printf("19 is ss ? %d\n", is_shusu(19));
	scanf("%d %d", &n, &m);
//	cout << ping_fang_he(20) << endl;	
	for(int i=n; i<=m; i++) { //[n,m]里每个数都过一遍xfshu(int)
		xfshu(i);
	}
	bool tag = false;
	for(int i=n; i<=m; i++) { //从(n,m]里找被标记为幸福数 并且 没有依赖于其他数 的数
		if(is_xingfu[i] && !yilai[i]) {
			printf("%d %d\n", i, count_xf[i]);
			tag = true;
		}
	}
	if(!tag) printf("SAD\n");
	//printf("97依赖%d \n", yilai[97]); //97依赖于94
	return 0;
}











/**
#include "stdio.h"
#include "math.h"
#define MAXN 10005

int prime(int x);
int pingfanghe(int x);

int main()
{
	freopen("test", "r", stdin);
	int A, B, count, i, j, k, p, xingfushugeshu;
	int flag[MAXN] = { -1 }, dealed[MAXN] = { 0 } , temp[MAXN] = { 0 }, dulixing[MAXN] = { -1 };
	for(int i=0; i<MAXN; i++) dulixing[i] = -1;
    // flag存放类型，-1初始化，1表示幸福数，2表示不幸福
	// dealed数组存放是否处理过，0表示未处理，1表示已处理
	// temp用来临时存放每次的处理序列
	// dulixing用来存放独立性, 如果是不独立的，置0
    scanf("%d %d", &A, &B);
	dealed[1] = 1;
	flag[1] = 1;

    for(i = A; i <= B; i++)
	{
		count = 0;
		j = i;
		while(dealed[j] == 0)  // 如果未遇到已处理的数据
		{
			temp[count] = j;    // 保存到临时数组
			count ++;
			dealed[j] = 1;     // 更新已处理的数组
			j = pingfanghe(j);  // 找下一个平方和
		}
		if(flag[j] == 1)     // 如果遇到的已处理数据是幸福数， 有两种情况，遇到1，或者是遇到其他幸福数
		{
			if(j != 1)    // 遇到其他幸福数的情况 把序列全部进入临时数组
			{
                count = 0;
			    k = i;
			    while(k != 1)
				{	
					temp[count] = k;
			        count ++;
			        k = pingfanghe(k);
				}
			}              // 不管遇到1还是其他幸福数，计算独立性， 同时把序列里的其他幸福数的独立性清零  
			dulixing[i] = count;
			flag[i] = 1;
		    for(k = 1; k < count; k++)
			{
				flag[temp[k]] = 1;
				dulixing[temp[k]] = 0;
			}
		}
		else if(flag[j] == 0)   // 如果是死循环 置flag为2
            for(k = 0; k < count; k++)
				flag[temp[k]] = 2;
		else if(flag[j] == 2)   // 如果遇到了已确定的死循环， 置flag为2
			for(k = 0; k < count; k++)
				flag[temp[k]] = 2;
	}

	xingfushugeshu = 0;     
	for(i = A; i <= B; i++)   // 输出
		if(dulixing[i] > 0)
		{
			xingfushugeshu ++;
			p = prime(i);
		    if(p == 1)
				printf("%d %d\n", i, dulixing[i] * 2);
			else
				printf("%d %d\n", i, dulixing[i]);
		}
	if(xingfushugeshu == 0)
		printf("SAD\n");
    return 0;
} 

int prime(int x)   //判素数
{
	int i;
//	if(x == 1 || x == 0) return 0;
	i = 2;
	while(i <= sqrt(x))
	{
		if(x % i == 0)
			return 0;
		i ++;
	}
    return 1;
}

int pingfanghe(int x)   // 计算平方和
{
	int i, xfshu;

	xfshu = 0;
	while(x != 0)
	{
		i = x % 10;
		xfshu = xfshu + i * i;
		x = x / 10;
	}
	return xfshu;
}
*/
