#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

extern char** environ;

int main() {
	int i;
	pid_t pid;
	pid = fork();
	if(pid == -1) {
		perror("error\n");
		return 0;
	} else if(pid > 0) { //父进程
		sleep(1);
		printf("father\n");
	} else {
		const char* img = "https://i0.hdslb.com/bfs/archive/184b5771e5b7b595f32409515e21c73523473a6e.jpg@1885w_830h_1c_100q.webp";
		execlp("wget", "wget", img, "-O", "b.webp", NULL);
	}
	return 0;
}

