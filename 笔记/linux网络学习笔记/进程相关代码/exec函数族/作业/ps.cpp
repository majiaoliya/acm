#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

int main() {
	pid_t pid;
	pid = fork();
	if(pid == -1) {
		perror("error\n");
		return 0;
	} else if(pid > 0) { //父进程
		sleep(1);
		printf("father\n");
	} else {
		//最后一个参数必须是NULL
		execlp("ls", "ls", "-l", "-a", NULL);
	}
	return 0;
}

