#include <iostream>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<double, double> p;
const int INF = 987654321;
const double PI = 2.0 * acos(0);
int N,TC,maxIdx;
double y[101],x[101],r[101],minValue;
p circle[101];

void adjustDegree(double& theta)
{
		while(theta > 2*PI)
			theta -= 2*PI;
		while(theta < 0)
			theta += 2*PI;
}
/*
void coordToDegree()
{
	for(int i=0;i<N;++i)
	{
		double theta = fmod(2*PI + atan2(y[i],x[i]),2*PI);
		double degree = 2.0* asin(r[i]/2.0/8.0);
		
		circle[i] = make_pair(theta - degree,theta + degree);
	}
}
*/
void coordToDegree()
{
	for(int i=0;i<N;++i)
	{
		int idx = (i + maxIdx) % N;
		double theta = fmod(2*PI + atan2(y[idx],x[idx]),2*PI);
		double degree = 2* asin(r[idx]/2.0/8.0);
		double& s = circle[i].first;
		double& e = circle[i].second;
		s = theta - degree;
		e = theta + degree;
		
		if(i == 0) 
			minValue = s;
		
		s -= minValue;
		
		s = fmod(2*PI + s,2*PI);
		e = s + 2*degree;
	}
	sort(circle,circle + N);
}

/*
//[begin,end] 가 덮지 못한 부분이다.
int solveLinear(double begin, double end)
{
	int used = 0, idx = 0;
	while(begin < end)
	{
		double maxCover = -1;
		while(idx < N && circle[idx].first <= begin)
		{
			maxCover = max(maxCover,circle[idx].second);
			++idx;
		}
		
		if(maxCover <= begin) return INF;
		
		begin = maxCover;
		++used;
	}
	return used;
}


int solveCircle()
{
	sort(circle,circle + N);
	int ret = INF;
	for(int i=0;i<N;++i)
	{
		double& s = circle[i].first;
		double& e = circle[i].second;
		
		if(s <= 0 || e >= 2*PI)
		{
			
			double begin = fmod(e,2*PI);
			double end = fmod(s+2*PI,2*PI);
			
			ret = min(ret,1+solveLinear(begin,end));
		}
	}
	return ret;
}
*/


int getMinMembers()
{
	int used = 1, i = 1;
	double e = circle[0].second,eMax;
	while(e < 2.0*PI)
	{
		bool isChanged = false;
		eMax = e;
		while(i < N && circle[i].first <= e)
		{
			eMax = max(eMax,circle[i].second);
			isChanged = true;
			i++;
		}
		
		if(!isChanged)
			return -1;
		
		e = eMax;
		used++;
		
	}
	
	return used;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	
	while(TC--)
	{
		cin >> N;
		for(int i=0;i<N;++i)
		{
			cin >> y[i] >> x[i] >> r[i];
			if(r[maxIdx] < r[i])
				maxIdx = i;
		}
		coordToDegree();
		
		
		// for(int i=0;i<N;++i)
		// {
		// 	cout << "i: " << i <<" s: " << circle[i].first <<" e: " << circle[i].second << '\n';
		// }
		
		int ans = getMinMembers();
		//int ans = solveCircle();
		if(ans == -1)
			cout << "IMPOSSIBLE"<< '\n';
		else 
			cout << ans << '\n';
		
		
	}
}

//1 1 8 0 16.01에 1이 떠야하는데 imp가 뜨는게 맞는 케이스로 되어있다.