#include <iostream>
#include <math.h>
#include <algorithm>//1100

int n,a,b,ret,i,idx_a,idx_b;
bool arr_a[16];
bool arr_b[16];
//n ~ 2^15.
//7 7  111 111 (4-1)*2^(2^2)+(4-1) *2^(2^1) + (4-1) * 2^(2^0)               6 2   110 010   2 * 2^4 +  3 * 2^2 +   0 
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	
	for(int temp = a;temp>0;temp/=2,idx_a++);
	
	while(a>0)
	{
		arr_a[i++] = a %2;
		a /=2;
	}
	
	for(int temp = b;temp>0;temp/=2,idx_b++);
	i = 0;
	while(b>0)
	{
		arr_b[i++] = b %2;
		b /=2;
	}
	i = std::max(idx_a,idx_b);
	
	while(n-- >= 0)
	{
		ret += arr_a[n]*2 * (1 << 2*n) + arr_b[n]*1  * (1 << 2 *n);
	}
	printf("%d",ret);
	
	return 0;
}