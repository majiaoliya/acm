### 2019-3-14 luogu1433 好题$\color{\red}著名的NP问题$

>  给定二维平面上的N个点 (N<15) 从(0,0)开始出发 找到一条最短的路径 保留两位小数

- ~~枚举所有情况~~
- ~~当前路径比答案大   剪枝~~  $O(n^2)$预处理出两点之间距离会变快
- 正解是DP$\color{\green}(不会~~用dfs骗到了90分)$
- 还有大神用爬山算法的.....



