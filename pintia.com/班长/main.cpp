#include<bits/stdc++.h>
using namespace std;
vector<int>v;
//typedef struct tt{
struct tt{
    int hh,mm,ss,ti;
}bb[10005];
bool cmp(tt& x,tt& y){
    if(y.hh>x.hh)      return true;
    else if(y.hh<x.hh) return false;
    else if (y.hh==x.hh){
        if(y.mm>x.mm)      return true;
        else if(y.mm<x.mm) return false;
        else if(y.mm==x.mm) {
            if(y.ss>x.ss) return true;
            else     return false;
        }
    }
}
int main(){
    int n,w,h,m,s,t,i=0,wait;
    cin>>n>>w;
    while(n--){
        scanf("%d:%d:%d %d",&h,&m,&s,&t);
      if((h>=8&&h<17)||(h==17&&m==0&&s==0)){
       bb[i].hh=h;
       bb[i].mm=m;
       bb[i].ss=s;
       bb[i].ti=t;
       i++;
      }
    }
//    sort(bb[0],bb[i-1],cmp);
	sort(bb, bb+(i-1), cmp);
    int k=0;
     vector<int>::iterator it ;
    for(int j=0;j<=w;j++){
//         v.push_back(b[k++].ti);
		v.push_back(bb[k++].ti);
    }
   while(k<i){   
       sort(v.begin(),v.begin()+w);
       it=v.begin();
       wait=*it;
       v.erase(v.begin());  //ÉẅṁôÊḟỳäṪî¶ÌṁÄ
       int kk=1;
       while(it!=v.end()){   //ÌæṠṠṁôÆäËûṀḞṡÚṁÄṁÈṀýÊḟỳä
           it=v.begin();
           int c=*it;
           c-=wait;
          v.erase(v.begin());
          v.push_back(c);
       }
       v.push_back(bb[k++].ti);  //ÔÙĠṗÒṠẁö
   }
   scanf("%0.1f\n",(float)wait/i);
}
