##### linux压缩命令

1. ##### tar

   > **tar zcvf fuck.tar.gz *.txt**压缩文件
   >
   > **tar -zcvf fuck.tar.gz fuck/**压缩文件夹
   >
   > 参数
   >
   >   c 创建压缩
   >
   >   x 释放,解压
   >
   >   v  显示提示
   >
   >   f  指定压缩文件名
   >
   >   z  使用gzip压缩成.gz
   >
   >   j  使用bzip2压缩成.bz2(**z和j不能同时使用**)
   >
   > **tar zxvf fuck.tar.gz -C ./xxx**解压到指定目录



##### who查看当前用户

##### ps查看进程

```
ps -a 列出用户
ps -au 
ps -aux 查看没有终端的应用程序
ps -aux | grep "root" 常用
ps -ajx 可以看到组id 常用
```



##### kill杀进程

```
kill -SIGKILL 10086 杀死pid为10086的进程
kill -9 10086 同上
kill -9 -10086 杀死组号为10086的多个进程
```





##### env命令查看环境变量

```
env | grep PATH
```

> linux环境变量格式
>
> > key=value:value:value



##### ifconfig 查看IP



##### sudo adduser + 用户名

##### file xxxx查看文件类型

