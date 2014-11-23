#include <iostream>
#include <fstream>

using namespace std;

const double PRICE = 6666;

int main()
{
	int tc;
	cin >> tc;
	for(int i = 1; i <= tc; i++)
	{
		if(i > 100000)
			break;

		double S, F, M;
		cin >> S >> F >> M;
		cout << "Case " << i << ":";
		double amnt = PRICE - S;
		if( F >= amnt)
			cout << " dad";
		else if( M >= amnt)
			cout << " mom";
		cout << endl;
	} // for i -> tc 100,000
	return(0);
} // end main
