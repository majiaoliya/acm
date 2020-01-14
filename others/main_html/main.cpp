#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  
#include <dirent.h>  
#include <sys/stat.h>  
#include <unistd.h>  
#include <sys/types.h> 
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
using namespace std;
vector<string> imgs;

string pre_path;

void listDir(char *path)  
{  
	DIR              *pDir ;  
	struct dirent    *ent  ;  
	int               i=0  ;  
	char              childpath[1024];  

	pDir=opendir(path);  
	memset(childpath,0,sizeof(childpath));  


	while((ent=readdir(pDir))!=NULL)  
	{  

		if(ent->d_type & DT_DIR)  
		{  

			if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0)  
				continue;  

	//		sprintf(childpath,"%s/%s",path,ent->d_name);  
	//		printf("path:%s/n",childpath);  

	//		listDir(childpath);  

		}  
		else
		{
//			cout<<"'./img/"<<ent->d_name << "',"<<endl;
			if(pre_path.back() != '/') pre_path.push_back('/');
			auto str = '\'' + pre_path + ent->d_name + "'";
			imgs.push_back(str);
		}
	}  

}  

int main(int argc,char *argv[])  
{ 	
	if(argc < 2) {
		printf("error ! I need a path !\n"); 
		return -1;
	}
	pre_path = argv[1];
	listDir(argv[1]);  
	string str;
	ofstream outfile;
	ifstream in_pre, in_suf;
	outfile.open("out.html", ios::out | ios::trunc);
	in_pre.open("./pre_html", ios::in);
	in_suf.open("./suf_html", ios::in);
	printf("pre_html:%s\n", "./pre_html");
	printf("suf_html:%s\n", "./suf_html");
	while(in_pre) { //前缀
		std::getline(in_pre, str);
		outfile << str << endl;
	}
	for(int i=0; i<(int)imgs.size(); i++) {
		if(i) outfile << ",";
		outfile << imgs[i] << endl;
	}
	while(in_suf) {
		std::getline(in_suf, str);
		outfile << str << endl;
	}
	printf("write to %s finish !\n", "./out.html");
	return 0;  
}
