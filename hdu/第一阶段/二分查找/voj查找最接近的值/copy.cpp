#include<iostream>
#include <algorithm>
#include<cstdio>
using namespace std;
int a[100001],ask,n,m;

int abs(int a)
{
    if(a<0) return -a;
    return a;
}
int main()
{
	freopen("test", "r", stdin);
    int i,mid;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    cin>>m;
    sort(a+1, a+n+1);
	for(i=1;i<=m;i++)
    {
        scanf("%d",&ask);
        if(a[1]>ask){cout<<a[1]<<endl;continue;}
        if(a[n]<ask){cout<<a[n]<<endl;continue;}
        int l=1,r=n;
        while(l<r)//不用二分查找会超时
        {
            mid=(l+r)/2;
            if(a[mid]>=ask) r=mid;
            else l=mid+1;
        }
        if(a[l]==ask||abs(a[l]-ask)<abs(a[l-1]-ask)) cout<<a[l]<<endl;
        else cout<<a[l-1]<<endl;
    }
    return 0;
}
