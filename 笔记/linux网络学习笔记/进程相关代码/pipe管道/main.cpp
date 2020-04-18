#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	
	printf("STDOUT:%d\n", STDOUT_FILENO);
	
	int i = 0, n = 4;
	for( ; i<n; i++) {
		pid_t pid = fork();
		if(!pid) break;
	}

	if(i == n) {
		for(int j=0; j<n; ++j) {
			wait(NULL);
			printf("father finish\n");
		}
	} else {
		char buf[4096] = { 0 };
		
	}


	return 0;
}


