#include <iostream>
using namespace std;

void subsample(float img[10][10], int M, int N)
{
	float s[5][5];
	float avg = 0;
	int count = 0;

	for (int i = 0; i < (M+1)/2; i++)
	{
		for (int j =0; j <( N+1)/2; j++)
		{
			for (int y = i*2; y <= i*2+1 && y<M; y++)
			{

				for (int x = j * 2; x <= j * 2 + 1 && x<N; x++)
				{
					avg = avg + img[y][x];
					count++;
				}
			}
			s[i][j] = avg/count;
			cout << s[i][j] << " ";
			avg = 0;
			count = 0;
		}
		cout << endl;
	}
}



int main()
{
	
	float img[10][10] = { {1.0,  2.0, 3.0},
						  {4.5,  6.5, 7.5} };
	subsample(img, 2, 3);

	system("pause");
	return 0;
}