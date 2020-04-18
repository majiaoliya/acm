##### opendir_readdir递归读取目录[代码](.//home/majiao/桌面/Link to 刷题/笔记/linux网络学习笔记/文件操作代码/opendir_readdir递归读取目录/main1递归统计文件夹下普通文件的个数.cpp)

* readdir函数

* * 函数原型

  * ```c++
    struct dirent *readdir(DIR *dirp);
    ```

  * 返回值

  * ```c++
    struct dirent {
      int ino_t d_ino; //此目录进入点的inode
      ff_t d_off; //目录开头至此目录的进入点的位移
      unsigned short d_reclen; //文件名d_name长度
      unsigned char d_type; //文件类型
      char d_name[256]; //文件名
    };
    //其中d_type文件类型如下
    DT_BLK 块设备
    DT_CHR 字符设备
    DT_DIR 目录
    DT_LNK 软链接
    DT_FIFO 管道
    DT_REG 普通文件
    DT_SOCK 套接字
    DT_UNKNOWN 未知
    ```

  * ​



##### 文件描述符复制

* dup函数

  * 函数原型

  * ```c++
    int dup(int oldfd); //返回一个fd
    int dup(int oldfd, int newfd);//会先关闭oldfd
    ```

    ​