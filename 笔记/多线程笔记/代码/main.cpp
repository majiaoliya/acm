#include<stdio.h>   
#include<omp.h>   
#include<string.h>   
#include<time.h>   
#include<stdlib.h>   
#include<iostream>   
using namespace std;   



#define NMAX 4096 * 10   
#define NUM_CORE 4   

int g_iBuff[NMAX];   


int main()   
{   
	int alignPos = 0;   
	for (int i = 0; i < 65; ++i)   
	{
		int tmp = *(&g_iBuff[i]);
		if (tmp % 64 == 0)   
		{     
			alignPos = i;   
			break;   
		}     
	}     

	for (int pos = 1; pos <= 4096; pos <<= 1)   
	{     
		memset(g_iBuff, 0 , sizeof(g_iBuff));   
		time_t beg = time(0);   
#pragma omp parallel for num_threads(NUM_CORE)   
		for (int i = 0; i < NUM_CORE; ++i)   
		{     
			int tp = i * pos + alignPos;   
			for (int j = 0; j < 999999999; ++j)   
			{     
				g_iBuff[tp]++;   
			}     
		}     
		time_t end = time(0);   

		cout << "false shareing: step = "<<pos<<" time = "<< end - beg << "s" <<endl;   
	}     

	return 0;   
} 
