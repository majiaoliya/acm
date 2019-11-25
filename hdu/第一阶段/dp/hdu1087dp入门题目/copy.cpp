#include<iostream>
using namespace std;
int a[1005];
int dp[1005];
int DP(int);

int main()
{
	freopen("test", "r", stdin);
	int group;
	while (cin>>group)
	{
		if (group == 0)
			break;
		for (int i = 0; i < group; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < group; i++)   //dp数组代表在这个位置时，加上之前的所有权值能得到的最大权值,在不加其他位置的时候，默认为自身的权值；
		{
			dp[i] = a[i];
		}
		cout << DP(group) << endl;
	}
    return 0;
}

int DP(int x)   //动态规划;
{
	int maxn = -1;
	for (int i = 0; i < x ; i++)  //从第一个点开始遍历，直到遍历到最后一个点;
	{
		for (int j = 0; j < i; j++)   //在这个位置时，加上之前的所有权值能得到的最大权值;
		{
			if (a[i] > a[j] && dp[i] < dp[j] + a[i])  //记住dp[j]每次循环都会发生变化，因为dp这个数组的含义;
			{
				dp[i] = dp[j] + a[i]; 
			}
			printf("%d  ", dp[i]);
		}
		printf("\n");
		if (maxn < dp[i])
		{
			maxn = dp[i];
		}
	}
	printf("\n");
	return maxn;
}

