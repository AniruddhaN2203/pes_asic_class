#include <stdio.h>
int main()
{
int n = 5;
int sum = 0;
for(int i = 1; i < n+1; i++)
{
	sum = sum + i;
}
printf("sum = %d\n",sum);
return 0;
}

