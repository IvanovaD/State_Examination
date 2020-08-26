#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct Node
{
	Node* first = nullptr;
	Node* second = nullptr;
	Node* third = nullptr;
	char letter;


};


void readLast(Node* tree, char letter, string &word, int level, int &maxLevel)
{
	if (tree==nullptr)
	{
		if (level > maxLevel)
		{
			maxLevel = level;
			word = letter;
		}
		else if (level == maxLevel)
		{
			word += letter;
		}

		return;
	}
	letter = tree->letter;
	readLast(tree->first, letter, word, level+1, maxLevel);
	readLast(tree->second, letter, word, level+1, maxLevel);
	readLast(tree->third, letter, word, level+1, maxLevel);

	
}

void word(Node* tree)
{

	string word = "";
	int maxLevel = 0;
	readLast(tree, ' ', word, 0, maxLevel);


	for (int i = 0; i < word.length(); i+=3)
	{
		cout << word.at(i);
	}
}

void serialize(ostream& os, Node* tree)
{
	if (tree == nullptr)
	{
		os << '*';
		return;
	}
	os << "( ";
	os << tree->letter;
	serialize(os, tree->first);
	serialize(os, tree->second);
	serialize(os, tree->third);
	os << ") ";

}

int main()
{

	Node* c = new Node;
	

	c->letter = 'c';

	Node* a = new Node;
	a->letter = 'a';

	Node* t = new Node;
	t->letter = 't';


	Node* b = new Node;
	b->letter = 'b';

	Node* x = new Node;
	Node* y = new Node;

	b->first = x;
	b->second = y;


	x->letter = 'x';


	Node* p = new Node;
	y->letter = 'y';

	Node* q = new Node;
	p->letter = 'p';

	Node* r = new Node;
	q->letter = 'q';

	x->first = p;
	x->second = q;
	x->third = r;


	Node* s = new Node;
	r->letter = 'r';

	r->first = c;
	r->third = a;

	s->letter = 's';
	y->third = s;
	
	s->letter = 's';
	s->second = t;



	word(b);
	ofstream os;
	os.open("treetext.txt");
	serialize(os, b);
	
	os.close();

	system("pause");
	return 0;
}