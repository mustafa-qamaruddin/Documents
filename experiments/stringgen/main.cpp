#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

char arr[4] = {'.', 'D', 'R', 'Z'};

int main()
{
	fstream fs;
	fs.open("output.o", fstream::out);
	srand(time(NULL));
	for(int j = 0; j < 5; j++)
	{
		fs << 2000000 << endl;
		for(int i = 0; i < 2000000; i++)
		{
			int index = rand() % 3;
			if( j == 3 )
				index = rand() % 4;
			fs << arr[index];
		}
		fs << endl;
	}
	return(0);
}
