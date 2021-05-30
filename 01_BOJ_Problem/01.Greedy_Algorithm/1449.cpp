#include <iostream>
//acmicpc.net/problem/1449

/*
문제명: 수리공 항승
TL: 2s
ML: 128MB



G
1. arr에 정수를 담는거보다 bool형 사용이 조금더 객관적이었다.
2. case 분리해서 일찍끝나게 하였다.
3. do while을 적절히 사용했다.

B
1. 구상은 잘했는데, 구현하는 도중에 이를 해맸다. 구상한 것들을 메모장에 적어놓으면 좋을 것 같다.
2. 구현력이 부족하여 시간이 오래 걸렸다.
3. 논리적으로 이해하기 보다 실행시켜보며 찾은 경향이 있다. (이러한 방식이 지속가능한지 고민해보아야 한다.)



TU: ?m
TS: 0ms
MS: 2016KB
*/

int find_next_idx(int last,bool* data)
{
	int i= last;
	for(;i<1001;i++)
		if(data[i])
			return i;
	return 0;
}
int main()
{
	int N,L,cnt = 0;
	bool data[1001] = {false,};
	scanf("%d %d ",&N,&L);
	if(L == 1)
	{
		printf("%d",N);
		return 0;
	}
	if(N == 1)
	{
		printf("1");
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		int num;
		scanf("%d",&num);
		data[num] = true;
	}
	int idx=find_next_idx(0,data);
	do
	{
		idx += L;
		cnt++;
		if(cnt > 100) break;
	}
	while(idx = find_next_idx(idx,data));
	printf("%d",cnt);
}

/*
 적어놨떤거
6 3
1 2 3 4 5 6	d : 5
3

5 3
1 2 3 4 5	d : 4
2

4 3
1 2 3 4		d : 3
2


3 3
1 2 3		d : 2
2

2 3
1 2			d : 1
1

L이 3일 때,
d+2  <= L*n을 만족하는, 최소 n이 사용된 테이프의 수이다.

1~5일 때,
5끝에 붙였냐
5.5에 붙였냐
6.5에 붙였냐
.
.
.
7끝에 붙였냐 까지 붙였냐의 경우가 있음.

수[1]의 L-0.5[2]까지는 커버가 됨.
3부터는 영향이 있음.  -> 5까지는 연속이라도 칭해도 된다.
4부터는 영향이X

arr[i] - idx >= L 		영향X	
1,4경우 기준점은 4가된다. cnt =

arr[i] - idx >= L -1	연속 찾는데는 영향O 테이프 갯수는 영향X	
1,3경우 기준점은 4(idx+L)가된다. cnt =

arr[i] - idx >= L -2	연속 찾는데도 영향O 테이프 갯수에도 영향O	
1,2의 경우 기준점은 4(idx+L)가 된다. cnt+

연속 찾는다는게 기준점인 idx를 어디로 옮기느냐를 의미함.

*/