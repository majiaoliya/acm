#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

int val = 100;
int main(void) {
	int a = 777;
	int* p = &a;
	pid_t pid;
	//使用MAP_ANON宏代表创建匿名映射
	p = (int*) mmap(NULL, 4, PROT_READ|PROT_WRITE, 
			MAP_SHARED|MAP_ANON, -1, 0);
	pid = fork();
	if(pid == 0) {
		*p = 299;
		val = 888;
		printf("child *p=%d val=%d\n", *p, val);
	} else {
		sleep(1);
		printf("child *p=%d val=%d\n", *p, val);
	}
	munmap(p, 4);
   	return 0;
}
