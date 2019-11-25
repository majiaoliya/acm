
#include "stdio.h"
#include "math.h"
#define MAXN 10005

int prime(int x);
int pingfanghe(int x);

int yilai[MAXN]; //记录这个幸福数的依赖

int main()
{
	//freopen("test", "r", stdin);
	int A, B, count, i, j, k, p, xingfushugeshu;
	int flag[MAXN] = { -1 }, dealed[MAXN] = { 0 } , temp[MAXN] = { 0 }, dulixing[MAXN] = { -1 };
	for(int i=0; i<MAXN; i++) dulixing[i] = -1;
    // flag存放类型，-1初始化，1表示幸福数，2表示不幸福
	// dealed数组存放是否处理过，0表示未处理，1表示已处理
	// temp用来临时存放每次的处理序列
	// dulixing用来存放独立性, 如果是不独立的，置0
    scanf("%d %d", &A, &B);
	dealed[1] = 1; //vis[]
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
			int pre = i; 
		    for(k = 1; k < count; k++)
			{
				yilai[temp[k]] = pre; //记录依赖
				pre = temp[k];
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
		if(dulixing[i] > 0 && yilai[i] == 0) //是幸福数 且 不依赖于其他数
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
