#include <iostream>
#include <cstring>
using namespace std;



int findLength(const char* expr) //pointer-а не е константен, тоест може
//да го променяме, но самия стринг е константен и не можем
{
	int len = strlen(expr);
	int len2;
	char first = expr[0]; //*expr

	while (expr)
	{
		len2 = strlen(expr);
		expr = strchr(expr + 1, first);
	}

	return len - len2;
}
 
int findMaxLength(const char* expr)
{
	int size;
	int max = 0;

	while (expr[0] != '\0')
	{
		size = findLength(expr);
		if (size > max)
			max = size;
		expr = expr + 1;
	}
	return max;
}

int main()
{
	
	cout<<findMaxLength("this is just a simple example\0");

	system("pause");
	return 0;
}