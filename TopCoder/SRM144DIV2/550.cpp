#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BinaryCode
{
	private:
		int n;
		int* p;
		int* q;
	public:
		vector<string> decode(string message)
		{
			// init
			n = message.length();
			p = new int[n];
			q = new int[n];

			for(int i = 0; i < n; i++)
			{
				q[i] = message[i] - '0';
			} // end for i -> n

			vector<string> v;
			v.push_back(genP(0));
			v.push_back(genP(1));
			return v;
		} // end decode
		
		string genP(int p0)
		{
			p[0] = p0;
			for(int i = 0; i < n; i++)
			{
				int pi_m_1;
				
				if(i-1 < 0)
					pi_m_1 = 0;
				else
					pi_m_1 = p[i-1];
					
				if(i+1 == n)
					continue;
				p[i+1] = q[i] - p[i] - pi_m_1;

				if(p[i+1] != 0 && p[i+1] != 1)
					return "NONE";

			} // end for i -> n

			if(p[n-2] + p[n-1] != q[n-1])
				return "NONE";
			return genStr();
		} // end genP
		
		string genStr()
		{
			stringstream ss;
			for(int i = 0; i < n; i++)
			{
				ss << p[i];
			} // end for i -> n
			return ss.str();
		} // end genStr
}; // end class

int main()
{
	BinaryCode bc;
	string tmp;
	getline(cin,tmp);
	vector<string> x = bc.decode(tmp);
	cout << x[0] << endl << x[1] << endl;
	return(0);
} // end main
