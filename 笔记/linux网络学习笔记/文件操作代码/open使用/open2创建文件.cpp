#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main() {
	int fd = open("new_file", O_RDWR | O_CREAT, 0777);
	if(fd == -1) { perror("can not create\n"); return 0; }
	close(fd);
	return 0;
}

