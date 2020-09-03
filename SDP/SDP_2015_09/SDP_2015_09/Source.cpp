#include <iostream>

using namespace std;

int N = 100;

struct Graph {

	int size;
	int* vertices;
	bool** edges;


	Graph(int *vertices_, bool edges_[3][3], int size_)
	{
		size = size_;
		vertices = new int[size];
		for (int i = 0; i < size; i++)
		{
			vertices[i] = vertices_[i];
		}
		edges = new bool*[size];
		for (int i = 0; i < size; i++)
		{
			edges[i] = new bool[size];
		}
		for (int u = 0; u < size; u++)
		{
			for (int v = 0; v < size; v++)
				edges[u][v] = edges_[u][v];

		}
	}
};

bool path(Graph g, int i, int j)
{
	if (i == j)
		return true;
	for (int k = 0; k < g.size; k++)
	{
		if (g.edges[i][k])
		{
			if (path(g, k, j))
			{
				return true;
			}
		}
	}

	return false;


}

bool isConnected(Graph g)
{    
	for (int i = 0 ; i<g.size; i++)
	{
		for (int j = i+1; j < g.size; j++)
		{
			if (!path(g, i, j) &&  !path(g, j, i))
			{
				return false;
			}
		}
	}
	return true;


}

int main()
{

	int vertices[3] = { 1, 2, 3 };
	bool edges[3][3] = { {0, 1, 0},
						{0, 0, 1},
						{0, 0, 0} };

	Graph g(vertices, edges, 3);

	//cout<<isConnected(g);


	bool edges2[3][3] = { {0, 0, 0},
						{1, 0, 1},
						{0, 0, 0} };

	Graph g2(vertices, edges2, 3);

	cout << isConnected(g2);
	system("pause");
	return 0;
}