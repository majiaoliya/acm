#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

//  >  输出重定向
//  <  输入重定向
//  |  管道

int status, tot;

void init() {
	status = 0;
}

struct Node {
	int argc, fd[2], write_to_id, read_from_id;
	FILE* in_file, *out_file;
	char argv[16][16];
	Node() : argc(0){ 
		in_file = stdin; out_file = stdout;
		write_to_id = read_from_id = fd[0] = fd[1] = 0;
	}
	void add(char* s) {
		memcpy(argv[argc], s, 16);
		argc ++;
	}
	void print() {
		printf("[%s]\n", argv[0]);
		for(int i=1; i<argc; i++)
			printf("    %s\n", argv[i]);
	}
} a[4096];

void redue2(char ch, Node* ptr) {
	Node* lst = ptr - 1;
	if(ch == '|') {

	}
}

int main(int argc, char** argv) {
	freopen("test", "r", stdin);
	bool not_exit = true;
	while(not_exit) {
		char str[128], buf[4096] = { 0 };
		//ps aux | grep pid
		fgets(buf, sizeof(buf), stdin);
		if(!buf[0]) break;
		int status = 0, status2 = 0;
		tot = 0;
		Node* ptr = a;
		for(int i=0, k=0; buf[i]; i++) {
			if(status == 0) 
				if(buf[i]!=' ') status = 1;
			if(status == 1) {
				if(buf[i] == ' ' || buf[i]=='\n') {
					status = 0;
					str[k++] = 0;
//					printf("[%s]\n", str);
					k = 0;
					if(status2 == 0) { //一个进程
						status2 = 1;
						ptr ++;
						tot ++;
						ptr->argc = 0;
						ptr->fd[0] = ptr->fd[1] = 0;
						ptr->add(str);
					} else if(status2 == 1) {
						if(str[0]=='|' || str[0]=='>' || str[0]=='<') {
							// 读完了一个进程的所有参数
							redue2(str[0], ptr);
							status2 = 0;
						} else { //读一个参数
							ptr->add(str);
						}
					}

				} else {
					str[k++] = buf[i];
				}
			}
		}
		for(int i=1; i<=tot; i++) {
			a[i].print();
		}
flag1:;
	}

	return 0;
}

