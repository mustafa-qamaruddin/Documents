#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

typedef unsigned long long ll;

const int MAXA = 12; // 10^18 -> A = 10 , B = 11 , X = 79
const int MAXB = 12;
const ll TENP18 = 1000000000000000000ULL;
const int MAXI = 80;
ll mem[MAXI];

// maintain min
int minA = 0;
int minB = 0;
int minX = 0;
ll minDiff = 0;

ll N;

ll fib(int index, int base_0, int base_1)
{
	if( index == 0)
		return base_0;
	if( index == 1)
		return base_1;

	ll& ret = mem[index];
	if(ret != 0)
		return ret;

	return ret = fib(index-2, base_0, base_1) + fib(index-1, base_0, base_1);
} // end fib

int main()
{
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++)
	{
		if(t > 100000)
			break;
		cin >> N; // 1 <= N <= 10^18
		if(N < 1 || N > TENP18)
			continue;
		// TRY
		for(int i = 0; i < MAXA; i++)
		{
			for(int j = i; j < MAXB; j++)
			{
				if( j == i )
					continue;
				memset(mem, 0, sizeof(mem));
				for(int k = 0; k < MAXI; k++)
				{
					ll fibk = fib(k, i, j);
					ll newDiff;
					if(fibk > N)
						newDiff = fibk - N;
					else
						newDiff = N - fibk;
					// reset
					if(i == 0 && j == 1 && k == 0)
					{
						minDiff = newDiff;
						minA = i;
						minB = j;
						minX = k;
						continue;
					}
					// compare
					if( newDiff < minDiff)
					{
						minDiff = newDiff;
						minA = i;
						minB = j;
						minX = k;
					}
					if( newDiff == minDiff)
					{
						if(i < minA)
						{
							minDiff = newDiff;
							minA = i;
							minB = j;
							minX = k;
						}
						if( i == minA && j < minB)
						{
							minDiff = newDiff;
							minA = i;
							minB = j;
							minX = k;
						}
					}
					if( fibk > N)
						break;
				} // for k -> MAXI: 10000
			} // for j -> 100
		} // for i -> 100
		cout << "Case " << t << ": " << minA << " " << minB << " " << minX << endl;
	} // end for t -> tc:100,000
	return(0);
} // end main
