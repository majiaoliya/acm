#include<stdio.h>
#define max 100001
struct stu{
	double id;
	double beis;
}sub[max];
int pre[max];
double xue;  //削弱

double fu(int x,double sum,int i,double gong){   //构造祖先树 
	if(pre[x]==x) {
		return gong*sum*sub[i].beis;
	}
	else {
		sum*=xue;
		return fu(pre[x],sum,i,gong);
	}
}
int main() {
	freopen("test", "r", stdin);
	int n;   //人数
	double gong;  //功力
	double sum=0;  //得道者的总功力 
	int count=0;  //得道者的总人数 
	scanf("%d%lf%lf",&n,&gong,&xue);
	xue=1-xue/100;     //将倍数其变为小数 
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);   //徒弟总人数输入 
		if(k==0){           //得道
			int x;
			scanf("%d",&x);
			sub[count].id=i;
			sub[count++].beis=x;
			continue;
		}
		for(int j=0;j<k;j++){  //非得道
			int tudi;
			scanf("%d",&tudi);   //各徒弟编号
			pre[tudi]=i;
		}
	}
	for(int i=0;i<count;i++){
		sum+=fu(sub[i].id,1.0,i,gong);
	}
	printf("%lld\n", (long long int)sum);
	return 0;
}
