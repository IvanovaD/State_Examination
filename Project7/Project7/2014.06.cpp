#include <iostream>

using namespace std;

struct Node{
	Node*next; 
    int data;
	Node(Node* _next, int _data) : next(_next), data(_data) {}
	Node() { next = nullptr; }
};

Node* precedes(Node* L, Node* start, int M, int N)
{
	if (L->data == M  && L->next->data == N)
		return L;
	if (L->next == start)
		return nullptr;
	return precedes(L->next, start,  M, N);
}

void print(Node* L)
{
	Node* start = L;
	cout << L->data<< "->";
	while (L->next!=start) {
		
		L = L->next;
		cout << L->data << "->";
	}
}
void merge(Node* x, Node* y)
{
	Node* ptr = x;
	Node* y_ptr = nullptr;
	Node* tmp;
	Node* x_ptr = nullptr;
	int max = 0;	
	do 
	{
		if (ptr->data + ptr->next->data > max)
		{
			if (tmp = precedes(y, y, ptr->next->data, ptr->data))
			{
				max = ptr->data + ptr->next->data;
				y_ptr = tmp;
				x_ptr = ptr;
			}
		}
		ptr = ptr->next;


	} while (ptr->next != x);
	tmp = x_ptr->next;
	x_ptr->next = y_ptr->next->next;
	y_ptr->next = tmp->next;

}

void split(Node* L, int M, int N)
{

	Node* ptr = L;
	int min = 1000;
	int dist;
	Node* start;
	Node* end;
	Node *tmp;
	while (ptr != L->next)
	{

		if (ptr->data == M)
		{  
			tmp = find(ptr, N, dist);
			if (dist<min)
			{
				min = dist;
				start = ptr;
				end = tmp;
			}
		}

		ptr = ptr->next;
	}


}
int main()
{
	Node* sixth =  new Node(nullptr, 3);
    Node* fifth = new Node(sixth, 5);
    Node* fourth = new Node(fifth, 4);
	Node* third = new Node(fourth, 3);
	Node* second = new Node(third, 2);
	Node* first = new Node(second, 1);

	sixth->next = first;

	Node* eight = new Node(nullptr, 8);
	Node* five = new Node(eight, 5);
	Node* two = new Node(five, 2);
	Node* three = new Node(two, 3);
	Node* four = new Node(three, 4);

	eight->next = four;

	merge(sixth, eight);
	print(sixth);

	system("pause");
	return 0;

}