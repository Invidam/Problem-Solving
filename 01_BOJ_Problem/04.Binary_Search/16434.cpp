#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
//acmicpc.net/problem/16434

/*
문제명: 드래곤 앤 던전
TL: 1s
ML: 256MB



Good
1. 함수로 나누어 풀었다.
2. 구조체 사용.
3. 구현에 막힌 게 별로 없었다.

Bad
1. 내 코드를 잘 이해하지 못하였다. 1~hi까지 이동하기에, 0은 ans가 될 수 없다.
2. 문제를 잘 이해하지 못하였다. 문제 표현이 부정확한 것도 있지만, 의도파악을 잘 못한 것 같다. (A 혹은 B인 경우 A일 때와 B일 때 2개 다 고려해서 문맥상 옳은 것을 고르자.)
3. 굳이 이분탐색이 아니어도 풀 수 있다고 생각한다.(던전을 돌며 소비되는 피의 양+1 이 max_hp이다. 이러한 경우 배열 선언을 안해도 된다.)
4. 자료형 크기 int = long = 2^31 // long long = 2^63 이다. <-- 이것을 몰라 시간소요가 컷다.

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h 40m
TS: ms
MS: KB
*/

struct data_room
{
	int t;
	int a;
	int h;
};

data_room room[123457];
int N;
ll atk,cur_hp,max_hp,lo,hi,mid,ans;
bool battle(int i)
{
	ll battle_cnt = room[i].h / atk;
	battle_cnt += room[i].h% atk == 0 ? 0 : 1;
	cur_hp = cur_hp - (battle_cnt -1) * room[i].a;
	if(cur_hp <= 0)
		return false;
	else
		return true;
}
void portion(int i)
{
	atk = atk + room[i].a;
	cur_hp = cur_hp + room[i].h;
	if(cur_hp >= max_hp)
		cur_hp = max_hp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll atk_init;
	cin >> N >> atk_init;
	for(int i=0;i<N;i++)
	{
		cin >> room[i].t >> room[i].a >> room[i].h;
	}
	lo = 1;
	hi = 1e12 * N / atk_init;
	while(lo <= hi)
	{
		atk = atk_init;
		mid = (lo + hi) / 2;
		max_hp = mid;
		cur_hp = max_hp;
		int i;
		
		for(i=0;i<N;i++)
		{
			if(room[i].t == 1)
			{
				if(!battle(i))
					break;
			}
			else
				portion(i);
		}
		if(i == N)
		{
			hi = mid - 1;
            if(ans == 0)
                ans = max_hp;
			ans = ans < max_hp ? ans : max_hp;
		}
		else
			lo = mid + 1;
	}
	cout << ans;
}

/*
#include <iostream>
using namespace std;
typedef long long ll;
ll atk,cur,mx;
int N,t,a,h;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> atk;
	for(int i=0;i<N;i++)
	{
		cin >> t >> a >> h;
		if(t==1)
		{
			ll dmg = a*((h/atk) - ((h%atk) ? 0 : 1));
           
            if(dmg > cur)
            {
                mx += (dmg-cur);
                cur = 0;
            }
			else 
                cur -= dmg;
		}
		else
		{
			atk += a;
			cur += h;
			if(cur > mx)
				cur = mx;
		}
	}
	cout << mx+1;
}
*/
