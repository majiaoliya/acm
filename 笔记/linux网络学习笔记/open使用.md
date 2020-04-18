##### C库函数

> fopen, fclose, fread, fwrite, fgets, fputs, fscanf,
>
> fprintf, fseek, fgetc, fgetc, fputc, ftell, feof, flush
>
> * FILE* fp
> * 刷新缓冲区: fflush,强制把缓冲区写入硬盘
> * 正常关闭文件
> * * fclose, main函数return, exit都会刷新缓存

* 缓冲区默认8K,满8K后自动写入硬盘
* **C库函数的read,write有缓冲区,但是linux内核read,write没有**
* 一个进程最多能打开1024减3个文件

> man 2 open # 用man查看系统调用的open

```c++
//所需头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
```

* open读取不存在文件

* ```c++
  int fd;
  fd = open("./not_exit_file", O_RDWR);
  if(fd == -1) { //发生错误
    perror("open file"); return 0;
  }
  int ret = close(fd);
  printf("ret = %d\n", ret);
  if(ret == -1) perror("close error\n");
  return 0;

  ```

* open创建新文件

* 文件权限: 

* * 实际权限=本地掩码取反再按位与(umask命令查看掩码)

* ```c++
  int fd;
  fd = open("new_file", O_RDWR | O_CREAT, 0777);
  if(fd == -1) {
    perror("can not create\n");
    return 0;
  }
  close(fd);
  ```



* 判断文件是否存在O_EXCL

* ```c++
  int fd;
  fd = open("new_file", O_RDWR |
            O_CREAT | OEXCL, 0777);
  if(fd == -1) {
    perror("can not create\n");
    return 0;
  }
  close(fd);
  ```

  ​

* 文件截断为0可以使用O_TRUNC







##### read

1. 返回值:
   * -1 读文件失败
   * 0 文件读完了
   * 大于0,读了n个字节
