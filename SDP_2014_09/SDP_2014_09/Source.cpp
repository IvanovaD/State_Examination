#include <iostream>

using namespace std;


struct Node
{
	Node *next, *prev;
	int data;
	Node(int data, Node* next, Node* prev)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};


bool join(Node* L1, Node* &L2)
{

	while (L1->next != nullptr)
		L1 = L1->next;
	

	Node*	L1_ptr = L1;
	Node *L2_ptr = L2;
	while (L1_ptr->prev != nullptr && L2_ptr->next != nullptr)
	{
		if (L1_ptr->data == L2_ptr->data)
		{

			L1->next = L2_ptr;
			L2->prev = L1_ptr;

			cout << "Make a connection from " << L1->data << " to " << L2_ptr->data << endl;
			cout << "Make a connection from " << L2->data << " to " << L1_ptr->data << endl;

			return true;
		}

		L1_ptr = L1_ptr->prev;
		L2_ptr = L2_ptr->next;
	}

	return false;

}

bool isJoined(Node* start, Node* end)
{
	Node* ptr_start = end;
	Node* ptr_end = start;

	while(ptr_start->prev)
	{
		ptr_start = ptr_start->prev;
	}
	while (ptr_end->next)
	{
		ptr_end = ptr_end->next;
	}

	while (start->next  || ptr_start->next)
	{
		if (!start->next || !ptr_start->next)
			return false;
		if (start->data != ptr_start->data)
		{
			return false;
		}
		start = start->next;
		ptr_start = ptr_start->next;
	}
	while (end->prev || ptr_end->prev)
	{
		if (!end->prev || !ptr_end->prev)
			return false;
		if (end->data != ptr_end->data)
		{
			return false;
		}
		end = end->prev;
		ptr_end = ptr_end->prev;


	}
	return true;

}


int sum(Node* l) // по скоро е по добре да разкачим двата списъка и тогава да ги сумираме
{
	Node* specialNode=nullptr;
	int sum = 0;
	while (l->next)
	{
		if (l->next->prev != l)
			specialNode = l->next;
		else
		   sum += l->data;
		l = l->next;

     }
	while(specialNode->prev)
	{
		sum += specialNode->data;
		if (specialNode->prev->next != specialNode)
			return sum;
		specialNode = specialNode->prev;
	}
	return sum;
}

void print(Node* L)
{

	while (L->next!=nullptr)
	{
		cout << L->data << " ";
		L = L->next;
	}
	while (L->prev != nullptr)
	{
		cout << L->data<<" ";
		L = L->prev;
	}
	cout << L->data << " ";
}
int main()
{
	Node* l1 = new Node(1, nullptr, nullptr);
	Node* l3 = new Node(3, nullptr, l1);
	Node* l5 = new Node(5, nullptr, l3);

	Node* l7 = new Node(7, nullptr, l5);
	Node* l9 = new Node(9, nullptr, l7);
	Node* l6 = new Node(6, nullptr, l9);

	l1->next = l3;
	l3->next = l5;
	l5->next = l7;
	l7->next = l9;
	l9->next = l6;


	Node* x3 = new Node(3, nullptr, nullptr);
	Node* x4 = new Node(4, nullptr, x3);
	Node* x8 = new Node(8, nullptr, x4);

	Node* x5 = new Node(5, nullptr, x8);
	Node* x7 = new Node(7, nullptr, x5);

	x3->next = x4;
	x4->next = x8;
	x8->next = x5;
	x5->next = x7;


	join(l1, x3);
	cout<<isJoined(l1, x7);
	//print(l1);
	cout << sum(l1);
	system("pause");
}