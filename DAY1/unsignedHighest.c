#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long int max = (unsigned long long int) (pow(2,64) - 1);
	printf("Highest number represented by unsigned long long int is %llu\n", max);
	unsigned long long int min = (unsigned long long int) (pow(2,64) *(- 1));
	printf("Lowest number represented by unsigned long long int is %llu\n", min);
	return 0;
}
