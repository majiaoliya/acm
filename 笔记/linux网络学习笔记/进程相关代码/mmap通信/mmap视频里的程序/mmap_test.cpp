#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void) {
	int fd = open("file", O_RDWR|O_CREAT, 0664);
	if(-1 == fd) {
		perror("write.cpp open error");
		return 0;
	}
	int len = 128;
	ftruncate(fd, len);
	if(-1 == len) {
		perror("write.cpp ftruncate error");
		return 0;
	}
	void* ptr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED) {
		perror("mmap error:");
		return 0;
	}
	strcpy((char*)ptr, "fuck you !");
	close(fd);
	int ret = munmap(ptr, len);
	if(ret == -1) {
		perror("write.cpp munmap:");
		return 0;
	}
	return 0;
}
