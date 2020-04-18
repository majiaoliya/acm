#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

extern char** environ;

int main() {
	int fd = open("out", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd < 0) {
		perror("open error:");
		return 0;
	}
	dup2(fd, STDOUT_FILENO);
	execlp("ps", "ps", "ax", NULL); //execlp没有成功返回值
	printf("hello\n"); //execlp成功后hello不会被执行打印
	//close(fd); //同上,所以close(fd)没意义
	return 0;
}

