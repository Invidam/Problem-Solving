#include <iostream>
#include <utility>
//acmicpc.net/problem/2339

/*
문제명: 석판 쪼개기 
TL: 2s
ML: 128MB



Good
1. 끝까지 포기하지 않았다.
2. 문제가 조금 햇갈렸다. () 
3. 너무 재미를 느끼지 못했던 것 같다. 재밌게 풀어야 한다

Bad
1. 구상이 잘 안떠올라 힌트를 보았다. (안 떠올랐다기 보다는 떠오른게 맞는 지 의문이 들었었다..)
2. 지문을잘안읽어서 시간이 오래 소요됐다.
3.

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 안풀려도 조급해하지말고 즐기면서 하자!

TU: 5h
TS: 0ms
MS: 2048KB
*/

typedef std::pair<int , int> p;
int N, imp_idx,jew_idx;
int arr[21][21];
int cnt,max_idx;
p imp[16];
p jew[401];
int solve(int s1,int s2,int r,int c,int flag)
{
	int ret = 0;
	cnt = 0;
	
	for(int i=0;i<max_idx;i++)
	{
		if(i < jew_idx && jew[i].first < s1 + r && jew[i].first >= s1 && jew[i].second < s2 + c && jew[i].second >= s2 && cnt <= 1) //
			cnt++;
		if(i < imp_idx && imp[i].first < s1 + r && imp[i].first >= s1 && imp[i].second < s2 + c && imp[i].second >= s2)
		{
			cnt = 2;
			break;
		}
	}
	
	if(cnt == 1)
		return 1;
	if(cnt == 0)
		return 0;
	//쪼개진 석판에 보석이 1개 있을면 1리턴 없으면 0리턴 둘다 아니면 밑으로 이동

	
	for(int i=0;i<imp_idx;i++)
	{
		if(imp[i].first < s1 + r&& imp[i].first >= s1 && imp[i].second < s2 + c && imp[i].second >= s2)
		{ // 범위안에 imp가 있을 때
			int temp = 1;
			if(flag != 1 && imp[i].first > s1 && imp[i].first < s1 + r - 1)
            {//가로로 쪼개야할 때
				for(int j=s2;j<s2+c;j++)
				{
					if(arr[imp[i].first][j] == 2 || (arr[imp[i].first][j] == 1 && j < imp[i].second))
						{
							temp = 0;
							break;
						}
				}
                if(temp)
				{
					temp *= solve(s1,s2,imp[i].first-s1,c,1);
					temp *= solve(1+imp[i].first,s2,s1+r - imp[i].first-1,c,1);
					
				}


				if(temp)
				{
					
					ret+= temp;
				}
			}
			if(flag != 2 && imp[i].second > s2 && imp[i].second < s2 + c - 1) 
            {//세로로 쪼개야할 때
				
				temp = 1;

				for(int j=s1;j<s1+r;j++)
				{
					
					if(arr[j][imp[i].second] == 2 || (j < imp[i].first && arr[j][imp[i].second] == 1))
						{
							temp = 0;
							break;
						}
				}
			
				
				if(temp)
				{

					temp *= solve(s1,s2,r,imp[i].second - s2,2);
					temp *= solve(s1,1+imp[i].second,r,s2+c - imp[i].second-1,2);	
					
				}
				if(temp)
                    ret+= temp;
                    
			}
		}
	}
	return ret;
}


int main()
{
	scanf("%d",&N);
    
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%1d",&arr[i][j]);
			
			if(arr[i][j] == 2)
				jew[jew_idx++] = p(i,j);
			
			else if(arr[i][j] == 1)
				imp[imp_idx++] = p(i,j);
		}
	}
	max_idx = jew_idx > imp_idx ? jew_idx : imp_idx;
	int tmp = solve(0,0,N,N,0);
	tmp = tmp == 0 ? -1 : tmp;
	printf("%d",tmp);
}