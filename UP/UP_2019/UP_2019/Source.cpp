#include <cstring>
bool find(int value, int *arr, size_t size)
{
	if (size == 0)
	{
		return false;
	}
	size_t mid = size / 2;
	if (value == arr[mid])
		return true;

	if (value < arr[mid])
		return find(value, arr, mid);
	else (find(value, arr + mid, mid));
}

template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil)
{
	int result = 0;

; for (size_t i = 0; i <size ; ++i)
	result = op(arr[i], Result);
return result; }

int op(char Digit, int Result) { 
	return (Result*10) + (Digit-'0'); }

int str_to_int(const char * str)
{ return (str == nullptr) ? 0 : fold_left(str, strlen(str) , op,  0); 
}
