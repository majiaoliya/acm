#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main() {
	int fd;
	fd = open("./not_exit_file", O_RDWR);
	if(fd == -1) { //发生错误
		perror("open file"); return 0;
	}
	int ret = close(fd);
	printf("ret = %d\n", ret);
	if(ret == -1) perror("close error\n");
	return 0;
}

