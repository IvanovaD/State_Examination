#include <iostream>
using namespace std;


struct List
{
	Node* numberList;
	List* nextList;
};

struct Node
{
	int data;
	Node* child;

};


bool sorted(Node* node)
{

	while (node != nullptr)
	{

		if (node->data > node->child->data)
			return false;
	}
	return true;

}
Node* merge(List* list)
{

	List* ptr = list;
	Node* ptr_node;
	Node* merged = new Node;
	while (ptr != nullptr)
	{

		ptr_node = ptr->numberList;
		if (sorted(ptr_node)) {
			while (ptr_node != nullptr)
			{

				if (merged->data < ptr_node->data && merged->child == nullptr)
				{

					Node* nextNode = new Node;
					merged->child = nextNode;
					nextNode->data = ptr_node->data;
					ptr_node = ptr_node->child;
				}
				else if (merged->data < ptr_node->data && ptr_node->data < merged->child->data)
				{
					Node* nextNode = new Node;
					nextNode->data = ptr_node->data;
					nextNode->child = merged->child;
					merged->child = nextNode;
					ptr_node = ptr_node->child;

				}
				else
				{
					merged = merged->child;
				}
			}
			ptr = list->nextList;
		}
		}
	
	return merged;
}

int main()
{





	return 0;

}