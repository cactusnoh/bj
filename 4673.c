#include <stdio.h>

void d(int a[], int n);
int main(void)
{
	int a[10035] = {0};
	for(int i = 1; i <= 10000; i++)
		d(a, i);
	for(int i = 0; i < 10000; i++)
		if(a[i] == 0)
			printf("%d\n", i+1);
	
	return 0;
}

void d(int a[], int n)
{
	int sum = n;
	while(n) {
		sum += n % 10;
		n /= 10;
	}
	a[sum-1]++;
}