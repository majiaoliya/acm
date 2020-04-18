#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <pwd.h>
#include <grp.h>
using namespace std;
int main(int argc, char** argv) {
	if(argc < 2) {
		printf("argc < 2\n");
		return 0;
	}
	struct stat st; //文件属性结构体
	int ret = stat(argv[1], &st);
	if(-1 == ret) {
		perror("can not : ");
		return 0;
	}
#if 0
	//通过宏判断文件类型
	if(S_ISREG(st.st_mode)) //文件
		printf("is file ");
	else if(S_ISDIR(st.st_mode)) //文件夹
		printf("is dir ");
#endif

	//通过与操作判断文件类型
	int type = st.st_mode & S_IFMT;
	printf(" %s is %s\n", argv[1], type==S_IFREG ? "FILE" : 
			(type==S_IFDIR ? "DIR" : "un_know"));

	//文件权限
	for(int i=8; i>=0; i--) {
		if(st.st_mode & (1<<i)) {
			switch(i%3) {
				case 2 : 
					printf("r");
					break;
				case 1 :
					printf("w");
					break;
				case 0 :
					printf("x");
					break;
			}
		} else
			printf("-");
	}

	struct passwd *pw = getpwuid(st.st_uid);
	printf("\n%s\n", pw->pw_name);
	struct group *gp = getgrgid(st.st_gid);
	printf("%s\n", gp->gr_name);
	printf("文件大小 : %ld\n", st.st_size);
	printf("%s\n", ctime(&(st.st_mtime)));
	return 0;
}

