#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

struct Node {
	int id;
	char name[128];
} ;

void print_node(Node* no) {
	if(!no) {
		printf("{ empty }\n");
		return ;
	}
	printf("{ id:%d, name:\"%s\"}\n", no->id, no->name);
}

int main(void) {
	int fd = open("file", O_RDWR|O_CREAT, 0664);
	if(-1 == fd) {
		perror("write.cpp open error");
		return 0;
	}
	int file_len = sizeof(Node);
	ftruncate(fd, file_len); //改变文件大小
	int len = lseek(fd, 0, SEEK_END);
	void* ptr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED) {
		perror("write.cpp can not mmap");
		return 0;
	}
	Node* pnode = (Node*) ptr;
	int i = 0;
	while(i <= 100) {
		pnode->id ++;
		printf("write.cpp : ");
		print_node(pnode);
		sleep(1);
	}
	int ret = munmap(ptr, len);
	if(ret == -1) {
		perror("write.cpp can not mummap()");
		return 0;
	}
	close(fd);
	return 0;
}
