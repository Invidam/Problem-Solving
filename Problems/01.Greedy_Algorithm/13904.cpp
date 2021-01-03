#include <iostream>
#include <utility>
#include <algorithm>
//acmicpc.net/problem/13904

/*
문제명: 과제
TL: 1s
ML: 256MB



Good
1. 알아낸 것 : 백준에서만 배열 선언시 0,false로 초기화가 안된다. // make_pair을 안쓰고 &p1.first로 입력이 가능하다.
2.  예제를 보고 풀며 그 방식을 논리적 구상에 잘 적용하였다 (피드백이 잘 되었다.)
3. 코드 단축 잘시켰다.

Bad
1. 구상에 시간이 오래 걸렸다.
2. std사용에 있어 어떠한 단점이 있는지 몰랐다. (알고리즘 단계에서는 문제 없지만[메모리, 시간만을 고려], 현업에서는 큰 문제가 된다.)
3. bool int의 차이점 생각해보기. ->[b: 1 / i : 4]
4. pair단축방법에 대해 찾아보기. -> typedef pair<int, int> p 처럼 사용하면 된다.

conceipt:  
solution: 높은 점수순으로 정렬 후, 가장 마지막 날짜에 하며 차있다면 전날로 이동한다. 꽉차있으면 포기한다.

Time : 24m

TS: 0ms
MS: 2016KB
*/


int main()
{
	std::pair<int,int> inp[1001];
	int  N, sum = 0 , idx;
	bool arr[1001] = {false,};
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d %d",&b,&a);
		inp[i] = std::make_pair(a,b);
	}
	
	std::sort(inp,inp+N,std::greater<std::pair<int,int>>());
	
	for(int i=0;i<N;i++)
	{
		for(idx = inp[i].second;arr[idx] == true;idx--);
		
		if(idx ==0)
			continue;
		
		arr[idx] = true;
		sum+= inp[i].first;
	}
	
	printf("%d",sum);
}

/*

끄적인 것들
1934시작 1958
N 입력수 1~1000
d 마감일까지 남은 일1~1000 
w 과제의 점수 1~100


점수 순으로 정렬 후


4 60 [4]
4 40 [3]
1 20
2 50 [2]
3 30 [1]
4 10
6   5 [5]

5 4 2 1 7
스케쥴을 짠다.
4 60 [4일]						4
2 50 [2일]						2
4 40 [4일이었는데 3일]					3	
3 30 [3일이었는데 2일이었다가 1일]				1		
1 20 [1일이었는데 못함]					0	
4 10 [4일이었는데 3일이었다가 2일이었다가 1일이었다가 못함]	0	
6 5 [5일,6일]						5,6
60+50+40+30+5 = 185.

즉, arr[1001]에
4 60이라면, arr[4] = 60
2 50	, arr[2] = 50
4 40	, arr[4]를 보고 이미있으므로 arr[3] = 40;
.
.
.

로 한다.

*/