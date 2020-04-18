#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
 
 
int main(void)
{
    int fd = open("file",O_RDWR|O_CREAT,0664);
    if(fd==-1)
    {
        perror("open hello");
        exit(1);
    }
	int file_len = 8;
    ftruncate(fd, file_len);
    int len = lseek(fd,0,SEEK_END);
    void* ptr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(ptr == MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    char* temp = (char*)ptr;
    while(1) {
		printf("%s\n", (const char*) ptr);
        sleep(2);
    }
    int ret = munmap(ptr,len);
    if(ret==-1)
    {
        perror("munmap");
        exit(1);
    }
    close(fd);
    return 0;
}
