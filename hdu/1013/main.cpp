#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

std::string dr(std::string x) {

	int sum = 0;
	std::string ret;
	for(int i=0; i<x.length(); i++) {
		sum += x[i] - '0';
	}
	if(sum > 9) {
		ret = dr(std::to_string(sum));
	} else {
		ret = std::to_string(sum);
	}
	return ret;
}

int main(void) {

	std::string x;
	for( ; cin>>x, x!="0"; ) {
		cout << dr(x) << endl;
	}

	return 0;
}
