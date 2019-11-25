#include <iostream>
#include <algorithm>
#define M 105
using namespace std;

class Entry { //药水
	public: 
		double pi; //浓度
		Entry() : pi(0.00) { }
		Entry(double _pi) : pi(_pi) { }
		bool operator < (Entry& other) { return this->pi < other.pi; }
};

Entry arr[M];

int main(void) {

	int n;
	cin >> n;
	for( ; n--; ) {
		int count, v, w;
		scanf("%d %d %d", &count, &v, &w);
		for(int i=0; i<count; i++) scanf("%lf", &(arr[i].pi));
		std::sort(arr, arr+count);

		double rsPi = 0.0;
		int rsV = 0;
		for(int i=0; i<count; i++) {
			if(rsPi+arr[i].pi <= w*(i+1))
			  rsPi += arr[i].pi, rsV=i+1;
			else 
			  break;
		}
		if(rsV)
			printf("%d %.2lf\n", rsV*v, rsPi/(rsV*v));
		else 
			printf("%d %.2lf\n", 0, 0.00);

/**
		 for(sum=0,i=0; i<n; i++) {
            if(sum+iarr[i] <= w*(i+1))
                sum+=iarr[i];
            else break;
		}
        if(!sum)
            printf("0 0.00\n");
        else
            printf("%d %.2lf\n",v*i,(double)sum/(i*100));
*/

	}
	
	return 0;
}
