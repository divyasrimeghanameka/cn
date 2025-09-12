#include<stdio.h>
#include<string.h>
int main()
{
	char input[30],stuffed[80]="";
	char start_delim, end_delim;
	char temp[3], double_start[3],double_end[3];
	int i;
	printf("enter the data to be stuffed:\n");
	scanf("%s", input);
	printf("enter the starting delimiter character:\n");
	scanf(" %c",&start_delim);
	printf("enter the ending delimiter character:\n");
	scanf(" %c",&end_delim);
	double_start[0]=double_start[1]=start_delim;
	double_start[2]='\0';
	double_end[0]=double_end[1]=end_delim;
	double_end[2]='\0';
	strcat(stuffed, double_start);
	for(i=0 ; i<strlen(input) ; i++)
	{
		temp[0]=input[i];
		temp[1]='\0';
		if(input[i]==start_delim)
			strcat(stuffed, double_start);
		else if(input[i]==end_delim)
			strcat(stuffed, double_end);
		else
			strcat(stuffed, temp);
	}
	strcat(stuffed , double_end);
	printf("Data after character stuffing : %s\n",stuffed);
	return 0;
}
/*output:
enter the data to be stuffed:
goodday
enter the starting delimiter character:
d
enter the ending delimiter character:
g
Data after character stuffing : ddggooddddaygg*/

	
