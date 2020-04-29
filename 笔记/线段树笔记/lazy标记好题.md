lazy标记

牛客\[统计颜色\][代码](/home/majiao/my_mount/Xubuntu_Work_Space/From_Xubuntu/codeTest_2019_2_21/刷题/笔记/线段树笔记/代码/牛客统计颜色)

> 链接：<https://ac.nowcoder.com/acm/problem/15667>
> n个桶按顺序排列，我们用1~n给桶标号。有两种操作：
>
>  1 l r c 区间[l,r]中的每个桶中都放入一个颜色为c的球 (1≤l,r ≤n,l≤r,0≤c≤60)
>
>  2 l r   查询区间[l,r]的桶中有多少种不同颜色的球     (1≤l,r ≤n,l≤r)

* 因为颜色种类小于60,所以可以用long long的每一个二进制位来存放是否有颜色,
* lazy标记下放的时候进行位运算即可

