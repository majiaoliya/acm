#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 10005

char mtx[MAXN][MAXN];
char mtx2[MAXN][MAXN];
int n;
void copy(int xx, int yy, int nn, int tag) {
	for(int i=1, ii=xx; i<=nn; i++, ii++) {
		for(int k=1, kk=yy; k<=nn; k++, kk++) {
			if(tag) mtx[ii][kk] = mtx2[i][k]=='P' ? 'C' : 'P';
			else mtx[ii][kk] = mtx2[i][k];
		}
	}
}

void dsp(int len) {
	for(int i=1; i<=len; i++) {
		for(int k=1; k<=len; k++)
			printf("%c", mtx[i][k]);
		printf("\n");
	}
}

int main() {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		mtx2[1][1] = 'C', mtx2[1][2] = 'C', mtx2[2][1] = 'P', mtx2[2][2] = 'C';
		int nn;
		scanf("%d", &nn);
		if(nn == 1) {
			for(int i=1; i<=2; i++) {
				for(int k=1; k<=2; k++) {
					printf("%c", mtx2[i][k]);
				}
				printf("\n");
			}
			continue ;
		}
		for(int i=2; i<=nn; i++) {
			int len = pow(2, i);
			copy(1, 1, len/2, false);
			copy(1, len/2+1, len/2, false);
			copy(len/2+1, 1, len/2, true);
			copy(len/2+1, len/2+1, len/2, false);
			memcpy(mtx2, mtx, sizeof(mtx));
		}
		int tn = pow(2, nn);
		for(int i=1; i<=tn; i++)  {
			for(int k=1; k<=tn; k++)
				printf("%c", mtx[i][k]);
			printf("\n");
		}
	}
	/*
	int a, b, c, k=1;
	for(int i=2; i<=10; i+=2, k++)
		printf("%d\n", (i^k) & ((i+10)^k));
	*/
	/**
	for(int i=1, k=3; i<20; i+=2, k+=2) {
		printf("%d %d = %d\n", i, k, (i^1) & (k^1));
	}
	*/
	return 0;
}




/**
#include <iostream>
#include <map>

using namespace std;
#define MAXN 300005

int n, m;

struct Node {
	int val, idx;
	bool vis;
} arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		map<int, Node> mp;
		for(int i=1; i<=n; i++) {
			scanf("%d", &arr[i].val);
			arr[i].idx = i;
			mp[arr[i].val] = arr[i];
		}
		while(m--) {
			int x;
			scanf("%d", &x);
			Node px = mp[x];
			
		}
	}
	return 0;
}
*/

/**
#include<bits/stdc++.h>
using namespace std;
int m[2000003],a[2000003];
int main(){
    int n,m1;
    while(scanf("%d%d",&n,&m1)!=EOF){
        for(int i=n;i>=1;i--){
            scanf("%d",&a[i]);
            m[a[i]]=i;
        }
        for(int i=0;i<m1;i++){
            int x;
            scanf("%d",&x);
            a[m[x]]=-1;
            a[++n]=x;
            m[a[n]]=n;
        }
        for(int i=n;i>=1;i--){
            if(a[i]!=-1)
              printf("%s%d",i==n?"":" ",a[i]);
        }
        memset(m,0,sizeof(m));
    }
}
*/
