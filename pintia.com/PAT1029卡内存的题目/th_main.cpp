#include <bits/stdc++.h>
using namespace std;
#define inf 0xffffffff
#define maxN 200005
int main()
{
	//1、如果第二个序列的数直接就是排在中位数，输出
	//2、如果第二个序列的数排在中位数之后，那么说明序列2后面的数都大，没必要读了，直接输出序列1的那个数
	//3、第二个序列中的数比序列1都大，那就在序列2里找
	//4、普通情况，不用管，直接让中位数序-1

	freopen("test", "r", stdin);
    int dataA[maxN], num;
    int N1, N2, i, loc, count, mid;

	scanf("%d", &N1);
    for(i = 0; i < N1; i++)
	{
		scanf("%d", &num);
		if(num < 0)
			num = inf;
		dataA[i] = num;
	}

	count = 0;
	scanf("%d", &N2);
	mid = (N1 + N2 - 1) / 2;
    while(N2 >= 0)
	{
		scanf("%d", &num);
		count ++;
		loc = lower_bound(dataA, dataA + N1, num) - dataA;
		if(loc == mid)
		{
			printf("%d\n", num);
			return 0;
		}
		else if(loc > mid)
		{
			printf("%d\n", dataA[mid]);
			return 0;
		}
		else if(loc == N1)
		{
			while(count + N1 - 1 < mid)
			{
				scanf("%d", &num);
				count ++;
			}
			printf("%d\n", num);
			return 0;
		}
		else
		{
			mid --;
		}
		N2 --;
	}
}
