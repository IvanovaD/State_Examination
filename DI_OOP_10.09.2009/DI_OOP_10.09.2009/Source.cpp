#include <iostream>

using namespace std;
/*ДасереализираабстрактенкласSequence, представящбезкрайнаредицаотчислаиметодзадостъпдонейнитеелементи 
(попореденномер). ДасереализираткласоветеArithmeticProgression,  PeriodicSequenceиInterleavedSequence,
наследницинакласаSequence, коитопредставятсъответноаритметичнапрогресия, периодичнаредицаикомбинациянадвередици.
Периодичнаредицаетакавабезкрайнаредицаотчисла, 
коятосеполучавакатопоследователноповторениенакрайнаредицаотчислабезкраенбройпъти. 
Комбинациянадвередицииередицата12,,...,,naaa...12,,,,nbbb......1122,,,,,,,nnbababa......
Закласоветедасереализиратподходящиконструктори, мутатори (методизапромянанастойносттанаполетата) 
иакоенеобходимо – деструктори. */


class Sequence
{
public:
	virtual int getElement(int index) const = 0; // може индекса да е unsigned
	virtual ~Sequence() {}

};

class PeriodicSequence : public Sequence
{
	int size;
	int *finiteSequence;
public:
	PeriodicSequence(int * finiteSequence, int size) //ако не искаме да правим голям четворка трябва да ползваме вектор вместо динамичен  масив
	{
		this->size = size;
		this->finiteSequence = new int[size];
		for (int i = 0; i < size; i++)
			this->finiteSequence[i] = finiteSequence[i];

	}
	//трябва ни голямата четворка понеже работим с динамична памет - копи конструктор и оператор за присвояване
	PeriodicSequence(const PeriodicSequence& PQ) : size(PQ.size)// PQ може да вика само конст функции
	{ // директно взимаме размера понеже сме в самия клас
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

	//може с псевдоним или със указател
	//ако е с псевдоним трябва да го инициализираме като константа в инициализиращия списък
	//като указатели - да преценим кой ще се грижи за тях - най добре да оставим външния свят да ги изтрива
	//тоест не пипаме нищо само ги взимаме, т.е в деструктора нищо не правим.
	//ако искаме ние да се грижим за указателите трябва да създадем метод clone в базовия клас
	//това е специален полиморфен констр. Хубаво е да напишем като коментар какво сме решили
	// дори могат да бъдат и константни указатели
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