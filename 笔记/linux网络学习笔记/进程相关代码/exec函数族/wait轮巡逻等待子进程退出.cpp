#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

extern char** environ;

int main() {
	int i, n = 5;
	pid_t p, chl3, wpid;
	for(i=0; i<n; i++) {
		p = fork(); //创建5个子进程
		if(p == 0) break;
		chl3 = i==1 ? p : chl3;
	}
	printf("i=%d\n", i);
	if(n == i) {
		sleep(n);
		printf("i am parent, pid:%d", getpid());
		//waitpid(chl3, NULL, 0); //0代表阻塞 等待chl3子进程
		//waitpid(-1, NULL, 0); //-1代表 等待所有子进程
		do { 
			//WNOHANG子进程还在运行就返回0
			wpid = waitpid(-1, NULL, WNOHANG);
			if(wpid > 0) n --;
			sleep(1);
		} while(n > 0);
	} else {
		sleep(i);
		printf("i am %dth chl pid:%d, gpid:%d\n",
				i, getpid(), getgid());
	}

	return 0;
}

