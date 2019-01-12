#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef unsigned long long int ull;
int fact();
int main()
{

	int n;
	scanf("%d",&n);
	ull f;
	f=fact(n);
	printf("%llu",f);





	return 0;
}

int fact(int a)
{	
	ull x;
	if (a==1)
	{
		return 1;	
	}
	else x=a*fact(a-1);

}















