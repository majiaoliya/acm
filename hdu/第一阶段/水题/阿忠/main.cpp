#include <iostream>
#include <iomanip>
using namespace std;

//全局变量
float minsize=5;
int count1=0;
int count2=0;
#define  m  10    //假定系统允许的空闲区表最大为m
#define  n  10     //假定系统允许的最大作业数量为n
//已分配表的定义
struct {
	float address;  //已分分区起始地址
	float length;     //已分分区长度，单位为字节
	int flag;         //已分配区表登记栏标志，"0"表示空栏目
}used_table[n];     //已分配区表对象名
//空闲区表的定义：
struct {
	float address;        //空闲区起始地址
	float length;        //空闲区长度，单位为字节
	int flag;          //空闲区表登记栏标志，用"0"表示空栏目，用"1"表示未分配
}free_table[m]; //空闲区表对象名

//函数声明
void initialize(void);
int distribute(int, float);
int recycle(int);
void show();
//初始化两个表
void initialize(void)
{
	int a;
	for(a=0; a<=n-1; a++)
		used_table[a].flag=0;    //已分配表的表项全部置为空表项
	free_table[0].address=1000;
	free_table[0].length=1024;
	free_table[0].flag=1;    //空闲区表的表项全全部为未分配
}

////最优分配算法实现的动态分区
//return process_name;
//}

int distribute(int process_name, float need_length)
{
	int i, k=-1;    //k用于定位在空闲表中选择的未分配栏
	float  ads, len;
	int count=0;    
	i=0;    
	while(i<=m-1)       //循环找到最佳的空闲分区
	{
		if(free_table[i].flag==1 && need_length <=free_table[i].length)
		{
			count++;
			if(count==1||free_table[i].length < free_table[k].length)
			{
				count++;
				if(count==1||free_table[i].length < free_table[k].length)
					k=i;
			}
			i=i+1;    
		}
		if(k!=-1)
		{    
			if((free_table[k].length-need_length)<=minsize) //整个分配
			{    
				free_table[k].flag=0;
				ads=free_table[k].address;
				len=free_table[k].length;
			}
			else
			{    //切割空闲区
				ads=free_table[k].address;
				len=need_length;
				free_table[k].address+=need_length;
				free_table[k].length-=need_length;
			}
			i=0;    
			//循环寻找内存分配表中标志为空栏目的项
			while(used_table[i].flag!=0) 
			{i=i+1;}    
			if(i<=n-1)     //找到，在已分配区表中登记一个表项
			{    
				used_table[i].address=ads;
				used_table[i].length=len;
				used_table[i].flag=process_name;
				count1++;
			}
			else      //已分配区表长度不足
			{
				if(free_table[k].flag == 0)  //将已做的整个分配撤销
				{    
					free_table[k].flag=1;
					free_table[k].address=ads;
					free_table[k].length=len;
				}
				else                            //将已做的切割分配撤销
				{    
					free_table[k].address=ads;   
					free_table[k].length+=len;
				}
				cout<<"内存分配区已满，分配失败！\n";          
				return 0;
			}
		}
		else
		{
			cout <<"无法为该作业找到合适分区！\n";
			return 0;
		}
	}
	return true;
}
int recycle(int process_name)   
{
	int y=0;
	float recycle_address, recycle_length;
	int i, j, k;         //j栏是下邻空闲区，k栏是上栏空闲区
	int x;
	//在内存分配表中找到要回收的作业
	while(y<=n-1&&used_table[y].flag!=process_name)
	{    y=y+1;}
	if(y<=n-1)    //找到作业后，将该栏的标志置为‘0’
	{          
		recycle_address=used_table[y].address;
		recycle_length=used_table[y].length;
		used_table[y].flag=0;
		count2++;
	}
	else             //未能找到作业，回收失败
	{
		cout<<"该作业不存在！\n";
		return 0;
	}
	j=k=-1;
	i=0;
	while(!(i>=m||(k!=-1&&j!=-1)))       //修改空闲分区表
	{
		if(free_table[i].flag==1)
		{            if((free_table[i].address+free_table[i].length)==recycle_address)
			k=i;    //判断是否有上邻接
			if((recycle_address+recycle_length)==free_table[i].address)
				j=i;    //判断是否有下邻接
		}
		i=i+1;        
	}
	//合并空闲区
	if(k!=-1)         //回收区有上邻接
	{    
		if(j!=-1){    //回收区也有下邻接，和上下领接合并
			free_table[k].length+=free_table[j].length+recycle_length;
			free_table[j].flag=0;    //将第j栏的标记置为‘0’
		}
		else                        //不存在下邻接，和上邻接合并
			free_table[k].length+=recycle_length;
	}
	else if(j!=-1)
	{                               //只有下邻接，和下邻接合并
		free_table[j].length+=recycle_length;
		free_table[j].address=recycle_address;
	}
	else 
	{                              //上下邻接都没有
		x=0;
		while(free_table[x].flag!=0)
			x=x+1;    //在空闲区表中查找一个状态为‘0’的栏目
		if(x<=m-1)
		{              //找到后，在空闲分区中登记回收的内存
			free_table[x].address=recycle_address;
			free_table[x].length=recycle_length;
			free_table[x].flag=1;
		}
		else
		{                                 //空闲表已满，执行回收失败
			used_table[y].flag=process_name;
			cout<<"空闲区已满，回收失败！\n";
			return 0;
		}
	}
	return process_name;
}
void show()      //程序执行时输出模拟的内存分配回收表
{
	cout<<"+++++++++++++++++++++++++++++++++++++++\n";
	cout<<"+++++++       空  闲  区        +++++++\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++\n";
	for(int i=0;i<=count2;i++)
		cout<<"地址："<<free_table[i].address<<"   "<<"作业长度："<<free_table[i].length<<"   "<<"状  态："<<free_table[i].flag<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++\n";
	cout<<"+++++++       已 分 配 区        ++++++\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++\n";
	for(int j=0;j<count1;j++)
		cout<<"地址："<<used_table[j].address<<"   "<<"作业长度："<<used_table[j].length<<"   "<<"作业名："<<used_table[j].flag<<endl;
}

int main()         //主函数调用各功能函数对所有工作进行测试
{ 
	int choice;       //用来选择将要进行的操作
	int job_name;
	float need_memory;
	bool exitFlag=false;
	cout<<"       动态分区分配方式的模拟       \n";
	cout<<"************************************\n";
	cout<<"请选择操作类型：\n";
	initialize(); //开创空闲区和已分配区两个表
	while(!exitFlag)
	{
		cout<<"********************************************\n";
		cout<<"**    1: 分配内存        2: 回收内存      **\n";
		cout<<"**    3: 查看分配        0: 退    出      **\n";
		cout<<"********************************************\n";
		cout<<"请输入您的操作 ：";
		cin>>choice;
		cout << choice << endl;
		switch(choice)
		{
			case 0:
				exitFlag=true;                      //退出操作
				break;
			case 1:
				cout<<"请输入作业名和所需内存：";
				cin>>job_name>>need_memory;
				distribute(job_name, need_memory); // 分配内存 
				break;
			case 2:
				int ID;
				cout<<"请输入您要释放的分区号：";
				cin>>ID;
				recycle(ID);             //回收内存
				break;
			case 3:
				show();
				break;
		}
	}
	return 0;
}
