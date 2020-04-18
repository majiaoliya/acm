##### read

1. 返回值:
   * -1 读文件失败
   * 0 文件读完了
   * 大于0,读了n个字节

##### 读取一个文件写入另一个文件

```c++
int fd = open("./main.cpp", O_RDONLY);
if(fd == -1) {
  perror("open\n");
  return 0;
}
int fdwrite = open("out", O_CREAT | O_WRONLY, 0664);
char buf[8096] = { 0 };
int status = 0;
while((status = read(fd, buf, sizeof(buf))) && ~status) {
  int cnt = write(fdwrite, buf, status);
  printf("status %d , wirte %d byte\n", status, cnt);
}
close(fd);
close(fdwrite);
```







##### lseek文件指针

```c++
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
//offset为正则向文件末尾移动（向前移），为负数则向文件头部（向后移）。
```





##### stat函数 文件详细信息(必须会用)

```c++
int stat(const char *pathname, struct stat *statbuf); //读软连接,会直接读实际文件(穿透函数)
int lstat(const char *pathname, struct stat *statbuf); //读软连接,访问的就是软连接文件(不穿透函数)
```

##### 用stat实现ls-l命令[我的代码](/home/majiao/桌面/Link to 刷题/笔记/linux网络学习笔记/文件操作代码/stat实现ls命令/)

