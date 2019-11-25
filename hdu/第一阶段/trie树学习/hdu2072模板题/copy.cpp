#include<iostream>
#include<sstream>
using namespace std;
 
struct node{
    int flag;
    struct node *next[26];
    node()
    {
        for(int i=0;i<26;i++)
        {
            this->next[i]=NULL;
        }
        this->flag=0;
    }
};
 
node *root;
int ans;
void Insert(string str)
{
    node *p=root;
    for(int i=0;i<str.size();i++)
    {
        if(p->next[str[i]-'a']==NULL)
            p->next[str[i]-'a']=new node();
        p=p->next[str[i]-'a'];
    }
    p->flag++;
    if(p->flag==1)
        ans++;
}
 
int main()
{
	freopen("test", "r", stdin);
    string str,str1;
    while(getline(cin,str))
    {
        root=new node();
        ans=0;
        if(str=="#")
            break;
        istringstream ss(str);
        while(ss>>str1)
        {
            Insert(str1);
        }
       cout<<ans<<endl;
    }
    return 0;
}
