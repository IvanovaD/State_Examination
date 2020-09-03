#include <iostream>
using namespace std;
 class Base 
{
public: 
	Base()
	{ cout << "Base::Base()\n"; }   
	Base(const Base&) 
	{ cout << "Base::copy()\n"; }  
	virtual void f()
	{ cout << "Base::f()\n"; }    
	virtual ~Base() 
	{ cout << "Base::~\n"; } 
 }; 

class Der : public Base 
{ public:    
	Der()
	{ cout << "Der::Der()\n"; }  
	Der(const Der&) 
	{ cout << "Der::Copy()\n"; }   
	void f()
	{ cout << "Der::f()\n"; }   
	~Der() 
	{ cout << "Der::~\n"; } 
}; 

void g1(Base a)
{
	cout << "F:";  
	a.f();
}
void g2(Der a) 
{
	cout << "F:";  
	a.f(); 
} 
void g3(Base& a)
{
	cout << "F:"; 
	a.f(); 
}

void main() 
{
	cout << "1:\n"; 
	Der d; 
	//Base::Base()
	//Der::Der()
	//

	cout << "2:\n"; 
	g1(d); //�������� ����� �� ������, ������ ������ ����������� �� �� ������

	//Base::Copy()
	//F: 
	//Base::f()
	//Base::~\n


	cout << "3:\n";   
	g2(d); 
	// ���� ��� ����� ������������
	//Base::Base() 
	//copy ������������ ������� ������� ����������� �� Base ����� 
	//��� �� ��� �������� ������� ����������, �� ��������� �� ������� ���� ������������ �� ������� ����
	//Der::Copy()

	//F: 
	//Der::f()
	//Der::~\n"
	//Base::~\n" 


	cout << "4:\n";//������ �� �������� �����, ���� ����� �� ����������� �� scope-a
	g3(d); 
	//F: 
	//Der::f()

	cout << "5:\n";  //��������������� ����� ���� �������� �� ���� ���� �� ���� �� ������� � cout-��
    //Der::~
	//Base::~

	system("pause");

}

//��� ����� ���� ����� �� ��� ������� ���� - ������� ������������ �� �������� ��� ���� ���� �� � ������� ������
//�� ����� ����� �� ������� -
//������������ �� ����������� ������  �������
//������������ �� ���� �������� �������
//������������ �� ���������
//������ �� ������������




//��� ����������� - 
//� ������� ��� - 
//������ �� �����������
//����������� �� ���������
//������������� �� �������� �������
//������������� �� ����������� ������  �������
