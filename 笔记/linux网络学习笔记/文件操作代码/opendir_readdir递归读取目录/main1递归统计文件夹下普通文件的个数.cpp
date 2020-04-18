#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int getFileNum(char* root) { //递归判断文件夹里普通文件的个数
	DIR* dir = opendir(root); //打开文件夹
	if(!dir) {
		perror("open error : ");
		return -1;
	}
	int tot = 0;
	struct dirent* ptr = nullptr;
	char path[1024] = { 0 };
	while((ptr=readdir(dir))) {
		//过滤./和../
		if(strcmp(ptr->d_name, ".")==0 || strcmp(ptr->d_name,"..")==0) 
			continue ;
		if(ptr->d_type == DT_DIR) { //递归子目录 
			sprintf(path, "%s/%s", root, ptr->d_name);
			tot += getFileNum(path);
		}
		if(ptr->d_type == DT_REG) tot ++;
	}

	closedir(dir); //关闭文件夹
	return tot;
}

int main(int argc, char** argv) {
	if(argc < 2) {
		printf("./main dir\n");
		return 0;
	}
	printf("%d\n", getFileNum(argv[1]));
	return 0;
}

