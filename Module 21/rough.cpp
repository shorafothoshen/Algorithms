#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
	{
		printf("%c is Alphabate");
	}
	else if(ch>=48 && ch<=57){ 
	}
	else
	{
		printf("Special Character");
	}
}