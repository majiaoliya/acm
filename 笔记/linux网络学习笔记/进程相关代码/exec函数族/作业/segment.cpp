#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

int main() {
	int a = 0;
	printf("./segment try div 0 error\n");
	a /= 0;

	return 0;
}

