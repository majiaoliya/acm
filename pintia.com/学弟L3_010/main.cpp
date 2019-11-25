#include<stdio.h>
#include <string.h>
#define max 10003
int main()
{
//	freopen("test", "r", stdin);
    int n;
    while(EOF != scanf("%d",&n)) {
    	
	    int pre[max]={0};
//	    memset(pre, false, sizeof(pre));
		int maxpoi=-1;
		for(int i=1;i<=n;i++){
		    int k, fi=1;
		    scanf("%d",&k);
		    if(i==1){
		       pre[i]=k;
//		       maxpoi = 1;
		       continue;
		    }
		    while(pre[fi]!=0){//填放二叉树
		       if(k>pre[fi]){
		          fi=2*fi;
		       }
		       else{
		          fi=2*fi+1;
		       }
		    }
		    pre[fi]=k;
		    if(fi>maxpoi){
		      maxpoi=fi;
		    }
		}
		int flag=0;   //标记完全二叉树
		for(int i=1;i<=maxpoi;i++){
		    if(i==1&&pre[i]!=0){
		       printf("%d",pre[i]);
		       continue;
		    }
		    if(pre[i]!=0){
		      printf(" %d",pre[i]);
		    }
		    else {
		      flag=1;
		    }
		}
		if(flag==1){  //是否完全二叉树
		 printf("\nNO\n");
		}
		else {
		 printf("\nYES\n");
		}
    }
    return 0;
}
