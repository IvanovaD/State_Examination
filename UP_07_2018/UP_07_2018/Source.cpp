#include <iostream>

using namespace std;

int reverse(int N)
{
	int reversed = 0;
	while (N != 0)
	{
		reversed = reversed * 10 + N % 10;
		N /= 10;
	}
	return reversed;
}


bool biggerThan(int n, int m)
{
	int reversedN = reverse(n);
	int reversedM = reverse(m);
	while (reversedN != 0 && reversedM != 0)
	{
		if (reversedN % 10 > reversedM % 10)
			return true;
	    if (reversedN % 10 < reversedM % 10)
			    return false;
		reversedN /= 10;
		reversedM /= 10;

		
	}
	if (reversedN == 0)
	{
		return false;
	}
	return true;

}
void sortLex(int* arr, int n)
{

	int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if ( biggerThan(arr[i], arr[j]) )
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

			}
		}


	}

	for (int i = 0; i < n; i++)
		cout << arr[i]<<" ";

}

int main()
{

	int arr[6] = { 13,14,7,2018,9,0 };
	sortLex(arr, 6);

	system("pause");
}