#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)
#define ISCHAR(x) ((x>='a' && x<='z') || (x>='A' && x<='Z'))

using namespace std;

string read_name() {
	string ret;
	while(true) {
		char ch = getchar();
		if(ISCHAR(ch)) {
			ret += ch;
		} else {
			ungetc(ch, stdin);
			break ;
		}
	}
	return ret;
}

double read_double() {
	double lef = 0.0, rig = 0.0, tmp = 0.1;
	bool read_little = false;
	char ch;
	while((ch=getchar()) != EOF) {
		if(ch == 10) break;
		if(ISCHAR(ch)) {
			ungetc(ch, stdin);
			break;
		} else {
			if(ch == '.') {
				read_little = true;
				continue ;
			}
			if(read_little) {
				rig = rig + (tmp * (ch-'0'));
				tmp *= 0.1;
			} else lef = lef*10 + (ch-'0');
		}
	}
	return lef + rig;
}

typedef pair<double, string> pds;
vector<pds> vec;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	char ch;
	double sum = 0.0, tmin = 999999, tmax = 0.0;
	string maxstr, minstr;
	while((ch=getchar()) != EOF) {
		if(ch == 10) break;
		ungetc(ch, stdin);
		auto str = read_name();
		auto val = read_double();
		vec.push_back({val, str});
		sum += val;
		if(tmax < val) maxstr = str, tmax = val;
		if(tmin > val) minstr = str, tmin = val;
//		cout << str << " " << val << endl;
	}
	printf("%.1lf\n", sum/(double)vec.size());
	printf("%s %.1lf\n%s %.1lf\n", maxstr.data(), tmax,
			minstr.data(), tmin);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


