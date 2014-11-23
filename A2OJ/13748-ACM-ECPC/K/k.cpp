#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for(int i = 1; i <= tc; i++)
	{
		if( i > 100)
			break;
		int N;
		string F, L;

		cin >> N >> F >> L;
		cout << "Case " << i << ":" << endl;
		char FF = tolower(F[0]);
		char LL = tolower(L[0]);
		for( int j = 1; j <= N; j++)
		{
			if( j > 100)
				break;

			string Member;
			cin >> Member;
			bool flag = false;
			for(string::size_type k = 0; k < Member.length(); k++)
			{
				if(k >= 100)
					break;
				char MM = tolower(Member[k]);
				if(MM == FF || MM == LL || FF != LL)
				{
					flag = true;
					cout << "YES" << endl;
					break;
				}
			} // end for k -> k:100
			if(!flag)
				cout << "NO" << endl;
		} // end for j -> N:100
	} // end for i -> tc:100
	return(0);
} // end main

