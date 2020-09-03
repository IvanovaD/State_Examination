#include <iostream> 
using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Base::Base()\n";
		f();
		g();
		//извикванията на функии в конструктор не се се случва полиморфно
		//тоест ще извикаме f от Base - защото нямам обект дерайвд още
		//виртуалната таблица оеще не е създадена	
	}
	Base(Base&)
	{
		cout << "Base::Base(Base&)\n";
		f();
		g();
	}
	virtual void f()
	{
		cout << "Base::f()\n";
		g();
	}
	void g()
	{
		cout << "Base::g()\n";
	}
	virtual ~Base()
	{
	cout << "Base Destructor" << endl;
	}
};
class Derived1 : public Base
{
public:
	Derived1()
	{
		cout << "Derived1::Derived1()\n"; 
		f(); 
		g();
	}
	Derived1(Derived1 &)
	{
		cout << "Derived1::Derived1(Derived1&)\n"; 
		f(); 
		g();
	}
	void f() 
	{
		cout << "Derived1::f()\n"; 
		g();
	}
	virtual void g() 
	{
		cout << "Derived1::g()\n";
	}
	virtual ~Derived1()
	{
		cout << "Derived1 Destructor" << endl;
	}
};
class Derived2 : public Derived1
{
public:
	Derived2()
	{
		cout << "Derived2::Derived2()\n"; 
		f(); 
		g();
	}
	Derived2(Derived2 &)
	{
		cout << "Derived2::Derived2(Derived2&)\n"; f(); g();
	}
	void f()
	{
		cout << "Derived2::f()\n"; 
		g();
	}
	void g()
	{
		cout << "Derived2::g()\n";
	}
	virtual ~Derived2()
	{
		cout << "Derived2 Destructor" << endl;
	}

};
void fCopy(Base obj)
{
	obj.f();         
	obj.g();
}
void main() {
	Base *pBase = new Derived2; //констриураме Derived2
	//а) 

	//cout << "Base::Base()\n";
    //Base::f()\n"
	//cout << "Base::g()\n";
	//cout << "Base::g()\n";
	//Derived1::Derived1()\n
	//cout << "Derived1::f()\n"; 
	//cout << "Derived1::g()\n"; 
	//cout << "Derived1::g()\n"; 
	//Derived2::Derived2()\n
	//cout << "Derived2::f()\n"; 
	//cout << "Derived2::g()\n"; 
	//cout << "Derived2::g()\n"; 
	cout << endl;
	Derived1 *pDerived1 = new Derived2;
	cout << endl;
	//б)
	// cout << "Base::Base()\n";
	// Base::f()\n"
	//	cout << "Base::g()\n";
	//cout << "Base::g()\n";

	//Derived1::Derived1()\n
	//cout << "Derived1::f()\n"; 
	//cout << "Derived1::g()\n"; 
	//cout << "Derived1::g()\n"; 

	//Derived2::Derived2()\n
	//cout << "Derived2::f()\n"; 
	//cout << "Derived2::g()\n"; 
	//cout << "Derived2::g()\n"; 

	cout << endl;
	Derived2 *pDerived2 = new Derived2;
	//в)
		// cout << "Base::Base()\n";
	//Base::f()\n"
	//	cout << "Base::g()\n";
	//cout << "Base::g()\n";

	//Derived1::Derived1()\n
	//cout << "Derived1::f()\n"; 
	//cout << "Derived1::g()\n"; 
	//cout << "Derived1::g()\n"; 

	//Derived2::Derived2()\n
	//cout << "Derived2::f()\n"; 
	//cout << "Derived2::g()\n"; 
	//cout << "Derived2::g()\n"; 


		

	cout << endl;
	pBase->f();
	//cout << "Derived2::f()\n";
	//cout << "Derived2::g()\n";
	cout << endl;
	
	//Г)    
	pDerived1->f();
	//cout << "Derived2::f()\n";
    //cout << "Derived2::g()\n";

	cout << endl;
	//д)   
	pDerived2->f();
	//cout << "Derived2::f()\n";
//cout << "Derived2::g()\n";
	cout << endl;
	//е)   
	fCopy(*pBase);

	//Base::Base(Base&)\n
		//cout << "Base::f()\n";
	//cout << "Base::g()\n";
	//cout << "Base::g()\n";

	//cout << "Base::f()\n";
	//cout << "Base::g()\n";
	//cout << "Base::g()\n";
	//delete base constructor

	//ж)    
	cout << endl;
	delete pBase;
	//delete BaseConstructor
	//delete Derived1Const
	//delete Derived2Const

	cout << endl;
	delete pDerived1;
	//delete BaseConstructor
	//delete Derived1Const
	//delete Derived2Const



	cout << endl;
	delete pDerived2;

	//delete BaseConstructor
	//delete Derived1Const
	//delete Derived2Const

	cout << endl;
	//обектите се унищожават но няма записани cout на деструкторите
	//

	system("pause");
}