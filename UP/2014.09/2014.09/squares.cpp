#include <iostream>
using namespace std;


void square(float X[], float Y[], int N)
{
	float maxX = X[0], maxY = Y[0], minX=X[0], minY=Y[0];
	for (int i = 0; i < N; i++)
	{
		if (X[i] < minX)
			minX = X[i];
		if (X[i] > maxX)
			maxX = X[i];
		if (Y[i] < minY)
			minY = Y[i];
		if (Y[i] > maxY)
			maxY = Y[i];
	}
	float side1 = abs(maxX) - abs(minX);
	float side2 = abs(maxY) - abs(minY);

	if (side1 > side2)
	{
		cout << "The side has size: " << side1;
		cout << "The coordinates of the center are: x: " << minX + side1 / 2 << " and y: " << minY + side1 / 2 << endl;
	}
	else
	{

		cout << "The side has size: " << side2;
		cout << "The coordinates of the center are: x: " << minX + side2 / 2 << " and y: " << minY + side2 / 2 << endl;

	}

}
int main()
{


	system("pause");
	return 0;
}