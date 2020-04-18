#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

extern char** environ;

int main() {
	pid_t pid, wpid;
	pid = fork();
	if(pid == 0) {
		printf("---child, my father id:%d, going to sleep 10s\n", getppid());
		sleep(3);
		printf("--------child die-------\n");
		return 99;
	} else if(pid > 0) {
		int status; 
		wpid = wait(&status); //用wait阻塞子进程 并收尸 
		if(WIFEXITED(status)) { //取得子进程结束的返回值
			printf("child exit status:%d\n", WEXITSTATUS(status));
		}
		if(wpid == -1) {
			perror("wait error:");
			return 0;
		}
		while(1) {
			printf("I am father, pid:%d, sonid:%d\n", getpid(), pid);
			sleep(1);
		}
	}

	return 0;
}

