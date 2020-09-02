#include <iostream>
using namespace std;



void count(const char * title, int len, int* &pass)
{
	int tmp = 0;

	for (int i = 0; i < len; i++)
	{
		if (title[i] == ' ')
		{
			*(pass) = i-tmp;
			tmp = i;
			++pass;
		
		}
	}
	*(pass) = len - tmp;
	++pass;
}

void revealPassword(const char* library[][20], int m, int n)
{
	int mid;
	if (n%2 == 0)
	   mid = n / 2 - 1;
	else 
		mid = n / 2 + 1;

	int pass[100];
	int* start = pass;
	int symbol = 0;
	
		for (int i = 0; i < m; i++)
		{
			int j = 0;
				while (j < n-1 && strcmp(library[i][j], library[i][j + 1]) <= 0 )
				{
					j++;
				}

				if (j == n-1)
				{
					count(library[i][mid], strlen(library[i][mid]), start);
					
				}
			

		
		}
		while(pass != start--)
			cout << (*start) << " "; 
		
		cout << endl;


}
int main()
{

	const char* library[][20] = { {"Algebra", "Analytical Geometry", "Mathematics analysis"},
	{"UP", "OOP", "SDP"},
	{"Data bases", "Artificial Intelligence", "Functional programming"} };

	revealPassword(library, 3, 3);
	system("pause");
	return 0;
}