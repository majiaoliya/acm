#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

int main() {
	
	int fd[2];
	pid_t pid;
	//使用pipe(int* fd)创建管道
	// fd[0]是读端R,  fd[1]是写端W
	int ret = pipe(fd);
	//要使得数据单向流动 即从父进程写入子进程
	//就要关闭父进程的读, 关闭子进程的写
	pid = fork();
	if(pid == 0) { //子进程关闭写
		close(fd[1]);
		char buf[1024] = { 0 };
		printf("child try read\n");
		int len = read(fd[0], buf, sizeof(buf));
		printf("child buf[] = %s\n", buf);
	} else { //父进程关闭读
		close(fd[0]);
		const char* str = "hello pipe\n";
		printf("father try write: %s\n", str);
		write(fd[1], str, strlen(str));
	}

	return 0;
}

