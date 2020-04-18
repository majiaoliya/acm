#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main() {
	int fd = open("out", O_RDWR);
	int ret = lseek(fd, 20000, SEEK_END);
	printf("ret: %d\n", ret);
	write(fd, "xxx", 1); //必须随便执行一次写操作
	close(fd);
	return 0;
}

