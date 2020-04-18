#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <signal.h>
using namespace std;

int main() {
	kill(getpid(), SIGKILL);
	return 0;
}

