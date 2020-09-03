#include <iostream>
using namespace std;

const int MAX = 100;
void year100(char terrain[MAX][MAX], int m, int n)
{
	bool changed[MAX][MAX]; // за да знаем кои 4ки са от текущата и от предишна итерация
	char object;
	int count = 0;
	for (int year = 0; year < 10; year++)
	{
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				changed[i][j] = 0;
			}
		}

			
	
			for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				object = terrain[i][j];
				switch (object) {
				case '1': terrain[i][j] = '2'; break;
				case '2': terrain[i][j] = '3'; break;
				case '3':terrain[i][j] = '4';
					changed[i][j] = 1;
					break;
				}


				if (terrain[i][j] == '4')
				{

					for (int t = i - 1; t <= i + 1 && t < m; t++)
					{

						for (int p = j - 1; p <= j + 1 && p < n; p++)
						{

							if (p >= 0 && t >= 0 && terrain[t][p] == '4' && changed[t][p] == 0)
							{
								count++;
						
							}

						}
					}
					if (count >= 4)
						terrain[i][j] = '3';

					count = 0;
				}
					
			}
		}




		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cout << terrain[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
int main()
{


	 char terrain[MAX][MAX] = { {'R', 'R', '1', '1', '2', '2'},
						{'1', 'R', 'R', 'R', '1', '2' },
						{'S', '1', 'R', 'R', '2', '3'},
						{'4', '4', 'S', 'S', 'R', 'R' }};



	year100(terrain, 4 ,6);

	



	system("pause");
	return 0;
}