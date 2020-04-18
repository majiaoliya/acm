#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <pwd.h>
#include <grp.h>
using namespace std;
int main(int argc, char** argv) {
	int fd = open("out", O_CREAT | O_RDWR, 0664);
	int ret = unlink("out");

	write(fd, "hello\n", sizeof("hello"));
	lseek(fd, 0, SEEK_END);
	char buf[32] = { 0 };
	int cnt = read(fd, buf, sizeof(buf));
	printf("cnt : %d\n", cnt);
	write(1, buf, sizeof(buf));
	close(fd);
	return 0;
}

