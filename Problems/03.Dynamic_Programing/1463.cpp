#include <iostream>
#include <algorithm>
//1463

/*
G
1 쉬운문제여서 딱히 배운게 X
2
3

B
1 빨리푸느라 좀 햇갈려함.
2
3

*/
int arr[1000001];
int N;

int solve(int n)
{
	if(arr[n] != -1)
		return arr[n];
	
	int temp = solve(n-1);
	if(n % 3 == 0)
		temp = std::min(temp,solve(n/3));
	else if(n %2 == 0)
		temp = std::min(temp,solve(n/2));
	arr[n] = ++temp;
	return temp;
	
}

int main()
{
	scanf("%d",&N);
	
	for(int i=2;i<=N;i++)
		arr[i] = -1;
	printf("%d",solve(N));
}