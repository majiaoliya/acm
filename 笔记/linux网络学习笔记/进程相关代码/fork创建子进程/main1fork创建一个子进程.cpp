#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

extern char** environ;

int main() {
	pid_t pid = 0;
	printf("father print\n");
	pid = fork();
	if(pid == 0) { //返回0 代表当前进程是子进程
		printf("chl go on. pid:%d\n", getpid());
	} else {
		printf("father go on. pid:%d\n", getpid());
	}
	return 0;
}

