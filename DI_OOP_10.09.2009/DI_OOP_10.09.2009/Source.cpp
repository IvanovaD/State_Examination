#include <iostream>

using namespace std;
/*���������������������������Sequence, ��������������������������������������������������������������� 
(��������������). �����������������������ArithmeticProgression,  PeriodicSequence�InterleavedSequence,
�����������������Sequence, ��������������������������������������������, ��������������������������������������.
���������������������������������������������, 
��������������������������������������������������������������������������������. 
�������������������������������12,,...,,naaa...12,,,,nbbb......1122,,,,,,,nnbababa......
����������������������������������������������, �������� (�������������������������������������) 
��������������� � �����������. */


class Sequence
{
public:
	virtual int getElement(int index) const = 0; // ���� ������� �� � unsigned
	virtual ~Sequence() {}

};

class PeriodicSequence : public Sequence
{
	int size;
	int *finiteSequence;
public:
	PeriodicSequence(int * finiteSequence, int size) //��� �� ������ �� ������ ����� �������� ������ �� �������� ������ ������ ���������  �����
	{
		this->size = size;
		this->finiteSequence = new int[size];
		for (int i = 0; i < size; i++)
			this->finiteSequence[i] = finiteSequence[i];

	}
	//������ �� �������� �������� ������ ������� � ��������� ����� - ���� ����������� � �������� �� �����������
	PeriodicSequence(const PeriodicSequence& PQ) : size(PQ.size)// PQ ���� �� ���� ���� ����� �������
	{ // �������� ������� ������� ������ ��� � ����� ����
		finiteSequence = new int[size];
		for (int i = 0; i < size; i++)
			this->finiteSequence[i] = PQ.getElement(i);

	}
	PeriodicSequence& operator=(const PeriodicSequence& PQ)
	{
		if (this != &PQ)
		{
			delete[] finiteSequence;
			size = PQ.size;
			finiteSequence = new int[size];
			for (int i = 0; i < size; i++)
			{
				finiteSequence[i] = PQ.finiteSequence[i];
			}
		
		}

		return *this;
	
	}

	int getElement(int index) const
	{

		int realIndex = index % size;
		return finiteSequence[realIndex];	
	}

	void setFQ(int size, int *finiteSequence)
	{

		delete[] finiteSequence;
		this->size = size;
		finiteSequence = new int[size];
		for (int i = 0; i < size; i++)
			this->finiteSequence[i] = finiteSequence[i];

	}

	int getSize() const
	{
		return size;
	}

	~PeriodicSequence()
	{
		delete[] finiteSequence;
	}
};

class ArithmeticProgression : public Sequence
{
	int base;
	int step;
public:
	ArithmeticProgression(int base, int step) : base(base), step(step)
	{
	}
	int getElement(int index) const
	{
		return  base + step * index;
	}

	void setAP(int base, int step)
	{
		this->base = base;
		this->step = step;
	}

};	

class InterleavedSequence : public Sequence
{

	 Sequence *seq1;
	 Sequence *seq2; 
	 InterleavedSequence(Sequence *seq1, Sequence *seq2) : seq1(seq1), seq2(seq2)
	 {
	 }

	//���� � ��������� ��� ��� ��������
	//��� � � ��������� ������ �� �� �������������� ���� ��������� � ��������������� ������
	//���� ��������� - �� �������� ��� �� �� ����� �� ��� - ��� ����� �� ������� ������� ���� �� �� �������
	//����� �� ������ ���� ���� �� �������, �.� � ����������� ���� �� ������.
	//��� ������ ��� �� �� ������ �� ����������� ������ �� �������� ����� clone � ������� ����
	//���� � ��������� ���������� ������. ������ � �� ������� ���� �������� ����� ��� ������
	// ���� ����� �� ����� � ���������� ���������
	/*const Sequence *seq1;
	const Sequence *seq2;

	InterleavedSequence(const Sequence &seq1, const Sequence &seq2) : seq1(&seq1), seq2(&seq2)
	{
	}*/
	int getElement(int index) const
	{
		if (index % 2 == 0)
			return (*seq1).getElement(index / 2);
		else return seq2->getElement(index / 2);


	}
	void setIS(Sequence *seq1, Sequence *seq2)
	{
		this->seq1 = seq1;
		this->seq2 = seq2;
	}
};


int main()
{




	return 0;
}