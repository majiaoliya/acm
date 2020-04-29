### luogu1160用数组模拟双向链表[我的代码](/home/majiao/桌面/Link to 刷题/luogu/luogu1160双向链表/)

> 一个学校里老师要将班上$N$个同学排成一列，同学被编号为1到$N$，他采取如下的方法：
>
> 1. 先将1号同学安排进队列，这时队列中只有他一个人；
> 2. 2到$N$号同学依次入列，编号为i的同学入列方式为：老师指定编号为i的同学站在编号为1到$i-1$中某位同学（即之前已经入列的同学）的左边或右边；
> 3. 从队列中去掉M(M<N)个同学，其他同学位置顺序不变。
>
> 在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。

* 插入双向链表

```c++
void insert(int x, int y) {
	++ tot;
	a[tot].val = tot;
	if(y) { //在x的右边插入
		a[tot].nxt = a[x].nxt;
		a[x].nxt = tot;
		a[tot].pre = x;
		if(a[tot].nxt) a[a[tot].nxt].pre = tot;
	} else { //在x的左边插入
		a[tot].pre = a[x].pre;
		a[x].pre = tot;
		a[tot].nxt = x;
		if(a[tot].pre) a[a[tot].pre].nxt = tot;
		else head = tot;
	}
}
```

* 删除已有的$x$节点

  ```c++
  void del(int x) { //删除链表已有的x
  	if(!vis[x]) return ;
  	vis[x] = false;
  	if(!a[x].pre) head = a[x].nxt; //删除链表头时要把头往下指
  	if(!a[x].nxt) { //链表尾
  		if(a[x].pre) 
  			a[a[x].pre].nxt = 0;
  		return ;
  	}
  	a[a[x].pre].nxt = a[x].nxt;
  	a[a[x].nxt].pre = a[x].pre;
  }
  ```

  ​