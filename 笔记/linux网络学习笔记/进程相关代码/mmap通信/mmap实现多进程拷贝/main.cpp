#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <math.h>
#include <stdlib.h>

int min(int x, int y) { return x < y ? x : y; }

int main(int argc, char** argv) {
	char src[256] = { 0 };
	char dst[256] = { 0 };
	if(argc >=3) 
		strcpy(src, argv[1]), strcpy(dst, argv[2]);
	else {
		printf("./main src.txt dist.txt\n ./main \"/home/majiao/桌面/pixiv/not_h/61370981_p0.jpg\" \"./a.jpg\"\n");
		return 0;
	}

	int fd_src = open(src, O_RDONLY);
	if(fd_src < 0) {
		perror("open src:");
		return 0;
	}

	int fd_dst = open(dst, O_RDWR|O_CREAT|O_TRUNC, 0664);
	if(fd_dst < 0) {
		perror("open dst:");
		return 0;
	}

	struct stat sbuf;
	int ret = fstat(fd_src, &sbuf);
	if(ret < 0) {
		perror("fstat:");
		return 0;
	}

	int n = 4, i;
	int flen = sbuf.st_size;
	if(flen < n) n = flen;

	ret = ftruncate(fd_dst, flen);
	if(ret < 0) {
		perror("ftruncate:");
		return 0;
	}

	char* mp_src = (char*)mmap(NULL, flen, PROT_READ, MAP_SHARED, fd_src, 0);
	close(fd_src);
	if(mp_src == MAP_FAILED) {
		perror("mmap src:");
		return 0;
	}

	char* mp_dst = (char*)mmap(NULL, flen, PROT_READ|PROT_WRITE,
			MAP_SHARED, fd_dst, 0);
	close(fd_dst);
	if(mp_src == MAP_FAILED) {
		perror("mmap dst:");
		return 0;
	}

	int blocksize = flen / n;
	int mod = flen % blocksize;
	printf("flen/n = %d/%d = %d\n", flen, n, flen/n);
	printf("mod = %d\n", mod);
	pid_t pid[n];

	for(i=0; i<n; i++) {
		pid[i] = fork();
		if(pid[i] == 0) break;
	}
	if(i >= n) 
		for(int j=0; j<n; ++j) 
			wait(NULL);
	else if(i == (n-1)) {
		memcpy(mp_dst+i*blocksize, mp_src+i*blocksize, blocksize+mod);
	} else if(i == 0)
		memcpy(mp_dst+i*blocksize, mp_src+i*blocksize, blocksize);
	else 
		memcpy(mp_dst+i*blocksize, mp_src+i*blocksize, blocksize);

	ret = munmap(mp_src, flen);
	ret = munmap(mp_dst, flen);

   	return 0;
}
