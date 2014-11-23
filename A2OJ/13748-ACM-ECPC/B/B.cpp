#include <iostream>
#include <vector>

using namespace std;

struct node
{
	public:
	int index;
	int weight;
	vector<int> adjList;

	node(int _index, int _weight, vector<int> _al)
	:index(_index), weight(_weight), adjList(_al)
	{}

	node()
	{
	
	}
};

vector<node> graph;

void printGraph()
{
	for(vector<node>::size_type i = 0; i < graph.size(); i++)
	{
		cout << "Node(W= " << graph[i].weight << ") " << i << ":";
		for(vector<int>::size_type j = 0; j < graph[i].adjList.size(); j++)
		{
			cout << " " << graph[i].adjList[j];
		}
		cout << endl;
	}
}

int dp(int index)
{
	
}

int main()
{
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc && t >= 1 && t <= 100; t++)
	{
		int N;
		cin >> N;
		graph.clear();
		graph.resize(N);
		for(int i = 0; i < N && i >= 0 && i <= 50000 - 1; i++)
		{
			int w, m;
			cin >> w >> m;
			vector<int> neighbors;
			neighbors.resize(m);
			for(int j = 0; j < m; j++)
			{
				cin >> neighbors[j];
			} // end for j -> M:0->N
			graph[i] = node(i, w, neighbors);
		} // end for i -> N:1->50,000
////		printGraph();
		int maxRev = 0;
		for(vector<node>::size_type i = 0; i < graph.size(); i++)
		{
			if( dijkstra
		} // end for i -> graph.size():1->N(50,000)
	} // end for t -> tc:1->100
} // end main
