#include <iostream>
using namespace std;

bool member(int x, int a[], int size) {
	if (size == 0)
		return false;
	return a[size / 2] == x ||
		(a[size / 2] < x && member(x, a + size / 2+1, size / 2)) ||
		(member(x, a, size / 2));
}


int main()
{

	int arr[] = { 2, 3, 4, 10, 40, 8};
	int x = 2;
	cout << member(x, arr, 6) << endl;


	int nums[6] = { 20, 3, 4, 7, 3, 2 };

	//пряка селекция
	int N = 6;
	for (int i = 0; i < N; i++)
	{
		int min = i;
			for (int j = i+1; j < N; j++)
			{
				if (nums[j] < nums[min])
					min = j;
			}
		if (min != i)
		{
			int x = nums[i];
			nums[i] = nums[min];
			nums[min] = x;
		}
	}

	for (int i = 0; i < N; i++)
		cout << nums[i] << " ";

	cout << endl;

	//В) Стойноста на result?
	int a = 0;
	int b = 15; 
	int result = -1;
	if (b < 10 && b / a < 10)
		result = 0;
	else  result = 1;

			cout <<"B) result value is: "<< result<<endl;
			//1


 // 6 | 11
// 6 = 110
// 7 = 111
// 8 = 1000
// 9 = 1001
//10 = 1010
//11=1011
//12 = 1100
//1111 = 15;

			//0110
			//1011
			//1111
			int bin = 6 | 11;
			cout << "6|11 is equal to: " << bin << endl;
	system("pause");
	return 0;
}