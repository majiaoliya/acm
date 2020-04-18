#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

int main() {
	
	pid_t p[128] = { 0 };
	int i, n = 3;
	for(i=1; i<=n; i++) {
		p[i] = fork();
		if(p[i] == 0) {
			sleep(2);
			printf("pid:%d gid:%d\n", getpid(), getgid());
			execlp("ls", "ls", "-l", "-a", NULL);
			break;
		}
	}
	do {
		pid_t wpid;
		wpid = waitpid(-1, NULL, WNOHANG);
		if(wpid > 0) n --;
		sleep(1);
	} while(n);
	return 0;
}

