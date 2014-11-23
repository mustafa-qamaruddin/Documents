#include <iostream>
#include <cstring>

using namespace std;

const int WIDTH = 3;
const int HEIGHT = 3;
const int BOUND = 9;

int matrix[WIDTH][HEIGHT];
bool vis[BOUND+1];

int n;
int nWays;
int nPerms; // number of permutations

int nextRow(int r, int c)
{
	if( c == WIDTH - 1)
		return r + 1;
	return r;
}

int nextCol(int r, int c)
{
	if( c == WIDTH - 1)
		return 0;
	return c + 1;
}

void print()
{
	cout << endl;
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			cout << matrix[i][j];
			
			if( j != WIDTH - 1)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool sumrows()
{
	for(int i = 0; i < HEIGHT; i++)
	{
		int sum = 0;
		for(int j = 0; j < WIDTH; j++)
		{
			sum += matrix[i][j];
		}
		if( sum != n)
			return false;
	}
	return true;
}

bool sumcols()
{
	for(int j = 0; j < WIDTH; j++)
	{
		int sum = 0;
		for(int i = 0; i < HEIGHT; i++)
		{
			sum += matrix[i][j];
		}
		if( sum != n)
			return false;
	}
	return true;
}

bool validate()
{
	if(!sumrows())
		return false;
	if(!sumcols())
		return false;
	return true;
}

bool preValidate(int newR, int newC)
{
	// if other cells in row is filled and sum > n // return false
	int sum = 0;int cnt = 0;
	for(int j = 0; j < WIDTH; j++)
	{
		if(matrix[newR][j] != -1)
		{
			sum += matrix[newR][j];
			cnt++;
		}
		if(sum > n)
			return false;
	}
	// if all filled, but not equal n // return false
	if(cnt == WIDTH && sum != n)
		return false;
	// if other cells in col is filled and sum > n // return false
	sum = 0; cnt = 0;
	for(int i = 0; i < HEIGHT; i++)
	{
		if(matrix[i][newC] != -1)
		{
			sum += matrix[i][newC];
			cnt++;
		}
		if(sum > n)
			return false;
	}
	// if all filled, but not equal n // return false
	if(cnt == WIDTH && sum != n)
		return false;
	// else return true
	return true;
}

bool bt(int r, int c)
{
	// base case
	if( r == HEIGHT )
	{
		nPerms++;
		if(validate())
		{
			nWays++;
			print();
			return true;
		}
		return false;
	}

	// permutate
	for(int i = 1; i <= BOUND; i++)
	{
		// taken
		if( vis[i])
			continue;
		// mark
		vis[i] = true;
		matrix[r][c] = i;

		// try
		int nr = nextRow(r,c);
		int nc = nextCol(r,c);
		if(preValidate(r,c))
			bt( nr, nc );

		// unmark
		vis[i] = false;
		matrix[r][c] = -1;

	} // end for i -> BOUND
	return false;
}

int main()
{
	while( cin >> n )
	{
		nWays = 0;
		nPerms = 0;
		memset(vis, false, sizeof(vis));
		memset(matrix, -1, sizeof(matrix));
		bt(0, 0);
		cout << "For N=" << n << " ,there are " << nWays << endl;
		cout << "#Permutations= " << nPerms << endl;
	}
	return(0);
}
