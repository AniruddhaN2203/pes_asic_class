#include <stdio.h>
#include <math.h>

int main()
{
	signed long long int max = (long long int) (pow(2,63) - 1);
	printf("Highest number represented by signed long long int is %lld\n", max);
	signed long long int min = (long long int) (pow(2,63) *(- 1));
	printf("Lowest number represented by signed long long int is %lld\n", min);
	return 0;
}
