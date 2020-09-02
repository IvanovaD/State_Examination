#include <iostream>
using namespace std;

void changeMatrix(int matrix[11][11])
{
	int avg;
	int n = 10;
	for (int i = 0; i < 11; i++)
	{
	for (int j = 0; j < 11; j++)
	{
	
			if (i == j || i+j == n)
			{
				avg = (matrix[i][j] + matrix[n - i][n - j]) / 2;
				matrix[i][j] = avg;
				matrix[n - i][n - j] = avg;
			}
			else
			{
				avg = (matrix[i][j] + matrix[j][i] + matrix[n - i][n - j] + matrix[n - j][n - i]) / 4;
				matrix[i][j] = avg;
				matrix[j][i] = avg;
				matrix[n - j][n - i] = avg;
				matrix[n - i][n - j] = avg;
			}


		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout <<endl;
	}
	cout << endl;
}

int main()
{

	int matrix[11][11] = {
	{1, 1, 0, 8, 2, 9, 1, 8, 8, 8, 7},
	{4, 3, 3, 0, 2, 5,6, 4, 6, 8, 7},
	{9, 0, 7, 8, 2, 3,7, 1, 8, 6, 9},
	{6, 5, 4, 2, 3, 6,3, 4, 4, 9, 2},
	{3, 6, 3, 1, 5, 8,4, 8, 2, 5, 5},
	{7, 0, 4, 4, 1, 0,5, 6, 8, 8, 6},
	{3, 4, 8, 9, 5, 9,2, 6, 6, 6, 5},
	{0, 7, 4, 5, 0, 1,9, 3, 1, 3, 2},
	{9, 2, 6, 9, 0, 6,5, 7, 4, 0, 9},
	{5, 5, 6, 1, 7, 5,6, 7, 5, 9, 5},
	{9, 4, 7, 1, 8, 2,4, 9, 5, 5, 4 } };

	changeMatrix(matrix);
	system("pause");
	return 0;
}