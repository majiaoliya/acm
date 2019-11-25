//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define MAXN 4096
//using namespace std;

//int n;
//struct Node {
//	string name;
//	int inhh, inmm, inss, outhh, outmm, outss;
//	Node() { }
//} arr[MAXN];

//int cmp_in(Node& x, Node& y) {
//	if(x.inhh == y.inhh) {
//		if(x.inmm == y.inmm) 
//			return x.inss < y.inss;
//		return x.inmm < y.inmm;
//	}
//	return x.inhh < y.inhh;
//}

//int cmp_out(Node& x, Node& y) {
//	if(x.inhh == y.inhh) {
//		if(x.inmm == y.inmm) 
//			return x.inss > y.inss;
//		return x.inmm > y.inmm;
//	}
//	return x.inhh > y.inhh;
//}

//int main() {
//	freopen("test", "r", stdin);
//	scanf("%d", &n);
//	for(int i=0; i<n; i++) {
//		char buf[32];
//		scanf("%s", buf);
//		arr[i].name = buf;
//		scanf("%d:%d:%d", &arr[i].inhh, &arr[i].inmm, &arr[i].inss);
//		scanf("%d:%d:%d", &arr[i].outhh, &arr[i].outmm, &arr[i].outss);
//	}
//	sort(arr, arr+n, cmp_in);
//	printf("%s ", arr[0].name.data());
//	sort(arr, arr+n, cmp_out);
//	printf("%s\n", arr[0].name.data());
////	for(int i=0; i<n; i++) {
////		printf("%s,", arr[i].name.data());
////		printf(",%d:%d:%d,", arr[i].inhh, arr[i].inmm, arr[i].inss);
////		printf("%d:%d:%d\n", arr[i].outhh, arr[i].outmm, arr[i].outss);
////	}
//	return 0;
//}
















#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 4096
using namespace std;

int parse(int hh, int mm, int ss) { return hh*3600+mm*60+ss; }
int n, inhh, outhh, inmm, outmm, inss, outss;
int intime = parse(23, 59, 59), outtime = parse(0, 0, 0);

string inname, outname;

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		char buf[32];
		scanf("%s", buf);
		scanf("%d:%d:%d", &inhh, &inmm, &inss);
		int tin = parse(inhh, inmm, inss);
		if(intime >= tin) {
			inname = buf;
			intime = tin;
		}
		scanf("%d:%d:%d", &outhh, &outmm, &outss);
		int tout = parse(outhh, outmm, outss);
		if(outtime <= tout) {
			outname = buf;
			outtime = tout;
		}
//		printf("%s:%d %d\n", buf, tin, tout);	
	}
//	printf("%d %d\n", intime, outtime);
	printf("%s %s\n", inname.data(), outname.data());
	return 0;
}
























