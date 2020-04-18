#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main() {
	int fd = open("./main.cpp", O_RDONLY);
	if(fd == -1) {
		perror("open\n");
		return 0;
	}
	int fdwrite = open("out", O_CREAT | O_WRONLY, 0664);
	char buf[8096] = { 0 };
	int status = 0;
	while((status = read(fd, buf, sizeof(buf))) && ~status) {
		int cnt = write(fdwrite, buf, status);
		printf("status %d , wirte %d byte\n", status, cnt);
	}
	close(fd);
	close(fdwrite);
	return 0;
}

