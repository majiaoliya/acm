#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

extern char** environ;

int main() {
	int i;
	pid_t pid;
	for(i=0; i<5; i++) { //循环创建5个子进程
		pid = fork();
		if(pid == 0) break; 
	}
	if(i < 5) {
		sleep(i);
		printf("I'am %d child , pid : %d\n", i+1, getpid());
	} else {
		sleep(i);
		printf("I'am father\n");
	}
	return 0;
}

