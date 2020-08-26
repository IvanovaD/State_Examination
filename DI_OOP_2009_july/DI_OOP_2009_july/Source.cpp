#include <iostream>
using namespace std;

class Function {
public:
	virtual int func(int x) const = 0;
	virtual ~Function()
	{}
};


class LinearFunction : public Function {
	int a, b;
public:
	LinearFunction(int a, int b) : a(a), b(b)
	{}
	virtual int func(int x) const
	{
		return a * x + b;
	}
};

class CharacteristicFunction : public Function {
	int* set;
	int size;
public:
	CharacteristicFunction(int* set, int size) : size(size)
	{
		set = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->set[i] = set[i];
		}
	}
	virtual int func(int x) const
	{
		for (int i = 0; i < size; i++)
		{
			if (set[i] == x)
				return 1;
		}
		return 0;	
	}
	CharacteristicFunction(const CharacteristicFunction& CF) : size(CF.size)
	{
		set = new int[size];
	 for (int i = 0; i<size; i++)
	 {
		 set[i] = CF.set[i];
	 }

	}

	CharacteristicFunction& operator=(const CharacteristicFunction& CF)
	{
		if (this != &CF)
		{
			delete[] set;
			size = CF.size;
			set = new int[size];
			for (int i = 0; i < size; i++)
			{
				set[i] = CF.set[i];
			}

		}
		return *this;
	}

	~CharacteristicFunction()
	{
		delete[] set;
	}

};
class SuperPosition : public Function {
	Function *f, *g;
public:
	SuperPosition(Function * f, Function* g) : f(f), g(g)
	{
	
	}
	virtual int func(int x) const
	{
		return f->func((g->func(x)));

	}

};
	




int main()
{



	return 0;

}