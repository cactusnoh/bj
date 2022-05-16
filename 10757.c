#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int A[10000], B[10000], C[10001], ch, i = 0, A_len, B_len, C_len;
	int carry = 0;
	
	while(!isspace(ch = getchar()))
		A[i++] = ch - '0';
	A_len = i;
	i = 0;
	while((ch = getchar()) != EOF && !isspace(ch))
		B[i++] = ch - '0';
	B_len = i;
	
	if(A_len > B_len)
		C_len = A_len + 1;
	else
		C_len = B_len + 1;
	
	i = C_len - 1;
	while(A_len || B_len) {
		//printf("C_len = %d", C_len);
		if(A_len && B_len) {
			C[i] = (carry + A[A_len-1] + B[B_len-1]) % 10;
			carry = (carry + A[A_len-1] + B[B_len-1]) / 10;
			A_len--; B_len--;
		} else if(A_len) {
			C[i] = (carry + A[A_len-1]) % 10; 
			carry = (carry + A[A_len-1]) / 10; 
			A_len--;
		} else if(B_len) {
			C[i] = (carry + B[B_len-1]) % 10; 
			carry = (carry + B[B_len-1]) / 10; 
			B_len--;
		}
		//printf(" %d\n", C[C_len-1]);
		i--;
	}
	C[0] = carry;
	
	if(C[0])
		i = 0;
	else
		i = 1;
	
	for(;i < C_len; i++)
		printf("%d", C[i]);
	
}