#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 10005
#define ll long long int

int main() {
    freopen("test", "r", stdin);
    ll t, a, b;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &a, &b);
		ll ans = a&b;
		if(!ans) printf("1\n");
		else printf("%lld\n", ans);
	}
    return 0;
}


/**
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 10005

int main() {
    freopen("test", "r", stdin);
//	freopen("out", "w", stdout);
	int t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
		printf("%d\n", a^b);
     //   int c = 0;
     //   if(a == b) {
     //       printf("%d\n", a);
     //       continue ;
     //   }
     //   while((a^c)&(b^c)) {
     //       c++;
     //   }
     //   printf("%d\n", c);
    }
    return 0;
}
*/

/**
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("a.txt","r",stdin);
    int num;
    cin>>num;
    while(num--){
    memset(ans,-1,sizeof(ans));
    	int a,b,c,min=1000;
    	cin>>a>>b;
    for(int i=0;i<4294967296;i++){
    	c=(a^i)&(b^i);
    	cout<<"(a^c)&(b^c)="<<c<<" C="<<i<<endl;
    	if(i==0&&c==0){
    	cout<<1<<endl;
    	flag=0;
    	break;
		}
		if(c==0){
			cout<<i<<endl;

			break;
		}
	}


		}

	}

*/
