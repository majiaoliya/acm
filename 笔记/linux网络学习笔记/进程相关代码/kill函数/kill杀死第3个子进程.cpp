#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <signal.h>
using namespace std;

int main() {
	pid_t pid, p[16];
	int i = 0, n = 5;
	for( ; i<n; i++) {
		pid = fork();
		if(!pid) break;
		p[i] = pid;
	}
	if(i == n) {
		kill(p[3], SIGKILL);
	} else {
		int t = 10;
		while(t--) {
			printf("i am child %d\n", i);
			sleep(1);
		}
	}
	return 0;
}

