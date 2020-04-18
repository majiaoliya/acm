#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <signal.h>
using namespace std;

int main() {

	alarm(1);
	for(int i=0; ; i++) 
		printf("%d\n", i);

	return 0;
}

