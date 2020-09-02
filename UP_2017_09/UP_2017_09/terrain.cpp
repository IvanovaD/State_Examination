#include <iostream>
using namespace std;


void find(char terrain[100][100], int i, int j, int& size, int m, int n)
{
	terrain[i][j] = '0';
	if (i+1 < n && terrain[i+1][j] == '4')
	{ 
		
		find(terrain, i + i, j, ++size, m, n);
	}
	if (j+1< m && terrain[i][j+1] == '4')
	{

		find(terrain, i , j+1, ++size, m, n);

	}
	if ( i-1>=0 && terrain[i - 1][j] == '4')
	{
		find(terrain, i-1, j, ++size, m, n);

	}
	if (j-1>=0 && terrain[i][j-1] == '4')
	{
		find(terrain, i, j-1, ++size, m, n);

	}
}

int maxTerrain(char terrain[100][100], int n, int m)
{
	int max = 0;
	int size = 0;
	for (int i =0; i<m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (terrain[i][j] == '4')
			{
				find(terrain, i, j, size, m, n);
				if (size > max);
						max = size;
			}

		}
	}
	return max;


}
int main()
{
	char forest[100][100] = {
	{'R', 'R', '1', '1', '2', '2'},
	{'1', 'R', '4', 'R', '1', '2'},
	{'S', '4', 'R', 'R', '2', '3'},
	{'4', '4', 'S', 'S', 'R', 'R'} };

	cout<<maxTerrain(forest, 4, 6)<<endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << forest[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}