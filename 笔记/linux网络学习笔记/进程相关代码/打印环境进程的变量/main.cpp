#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

extern char** environ;

int main() {
	for(int i=0; environ[i]; i++)
		printf("%s\n", environ[i]);
	return 0;
}

