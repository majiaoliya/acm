#include <iostream>
using namespace std;

#define n 64      //页表的最大长度
#define length 4  //系统为每个作业分配的主存块数
struct{
	int lnumber;  //页号
	int flag;      //表示页是否在主存中，“1”表示在，“0”表示不在
	int pnumber;  //该页所在主存块的块号
	int write;    //该页是否被修改过，“1”表示修改过，“0“表示没有修改过
	int dnumber;  //该页存放在磁盘上的位置，即磁盘块号
}page[n];      //页表定义
int m;
int page_length;  //页表的实际长度
int p[length];    //用向量模拟主存
int head;
void page_interrupt(int);  //缺页中断处理函数
void command(unsigned, int); //命令处理函数
int main(){
	int lnumber,pnumber,write,dnumber;
	unsigned laddress;
	int i;
	cout<<"输入页表的信息，创建页表（页号从0开始，若页号为－1，则结束输入） ";
	cout<<"请输入页号和辅存地址：";
	cin>>lnumber>>dnumber;
	cin.ignore ();
	i=0;
	while(lnumber!=-1){
		page[i].lnumber=lnumber;
		page[i].flag=0;
		page[i].write=0;
		page[i].dnumber=dnumber;
		i++;
		cout<<"请输入页号和辅存地址:\n";
		cin>>lnumber>>dnumber;
	}
	//预先将输入的页调入主存块中
	page_length=i;
	cout<<"输入主存块号(输入少于或者等于"<<i<<"个数据，若块号数为－1，则结束输入):";
	cin>>pnumber; 
	cin.ignore ();
	m=0;
	head=0;
	while(m<length&&pnumber!=-1){
		if(m<i){
			page[m].pnumber=pnumber;
			page[m].flag=1;//调入主存后，标志为置1
			p[m]=m;        //记录主存中的页号
			m++;
		}
		cout<<"输入主存块号（输入少于或者等于"<<i<<"个数据，若块号数为－1，则结束输入）:";
		cin>>pnumber; 
		cin.ignore ();
	}//while
	cout<<"输入指令性质（1－修改，0－不需要，其他－结束程序运行）和逻辑地址 "
		<<"逻辑地址最大能支持2的16次方－1＝65535。";
	cout<<"输入指令性质：";
	cin>>write;
	cin.ignore ();
	cout<<"输入逻辑地址：";
	cin>>laddress;
	cin.ignore ();
	while((write=0) || (write=1)){
		command(laddress,write); //将输入的逻辑地址转换成物理地址
		cout<<"输入指令性质：";
		cin.ignore ();
		if(write!=0&&write!=1) break;
		cout<<"输入逻辑地址：";
		cin>>laddress;
		cin.ignore ();
	}//while
}//main
//中断处理函数，采用先进现出的页面调度算法//
void page_interrupt(int lnumber){
	int j;
	cout<<"发生缺页中断"<<lnumber<<endl;
	j=p[head];
	p[head]=lnumber;
	head=(head+1)%m;
	if(page[j].write==1)
		cout<<"将页 "<<j<<"写回磁盘?"<<page[j].dnumber << (page[j].flag=0);
	page[lnumber].pnumber=page[j].pnumber;
	page[lnumber].flag=1;
	page[lnumber].write=0;
	cout<<"淘汰主存块 "<<page[j].pnumber<<" 中的页 ?" << j <<" 块中调入页 ?" <<lnumber<<endl;
}
//地址转换函数，将逻辑地址转换成物理地址，如果要查找的页不在主存当中则产生缺页中断//
void command(unsigned laddress,int write){
	unsigned paddress,ad,pnumber;
	int lnumber;
kk:
	lnumber=laddress>>10; //取逻辑地址高6位，页号
	ad=laddress&0x3ff;    //页内地址
	cout<<"该逻辑地址的页号为："<<lnumber<<"  页内地址为：?" <<ad<<endl;
	if(lnumber>=page_length){  //页号大于页表的长度，则无效页号
		cout<<"该页不存在！";
		return;
	}
	if(page[lnumber].flag==1){  //页号为lnumber 在内存当中 
		pnumber=page[lnumber].pnumber;
		paddress=pnumber<<10|ad;
		cout<<"逻辑地址是："<<laddress<<"  对应物理地址是：? "<<paddress<<endl;
		if(write==1)      //该页被修改过
			page[lnumber].write=1;
	}
	else{  //页号为lnumber不在内存当中，则产生缺页中断
		page_interrupt(lnumber);
		goto kk;
	}
}//command
//</i<<"个数据，若块号数为－1，则结束输入）:";
//</i<<"个数据，若块号数为－1，则结束输入):";

