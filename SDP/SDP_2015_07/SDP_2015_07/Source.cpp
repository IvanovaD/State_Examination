#include <iostream>
#include <vector>
using namespace std;


struct Node {
	int data;
	vector<Node*> children;
	Node(int data, vector<Node*> children)
	{

		this->data = data;
		this->children = children;
	}
};

void member(Node *root, int x, bool& has)
{
	if (root == nullptr)
		return;
	if (x == root->data)
		has = true;
		for (Node* child : root->children)
		{
			member(child, x, has);
		}
	
	
}

bool member2(Node *root, int x)
{
	if (root == nullptr)
		return false;
	if (x == root->data)
		return true;
	for (Node* child : root->children)
	{
		if (member2(child, x))
			return true;
	}
	return false;


}

void deleteTree(Node* root)
{
	if (root != nullptr)
	{
		for (Node* child : root->children)
			deleteTree(child);
		delete root;
	}
}

void filterOdd(Node* &root)
{
	if (root == nullptr)
		return;
	
	for (vector<Node*>::iterator it = (root->children).begin(); it != (root->children).end();)
	{
		if ((*it) != nullptr && (*it)->data % 2 == 1)
		{
			Node* p = *it;
			it = root->children.erase(it);
			deleteTree(p);
			
		}
		else
		{
			filterOdd(*it);
			++it;
		}
	}
}
void print(Node* node)
{
	if (node != nullptr)
	{
		cout << node->data;
		for (Node* child : node->children)
		{
			print(child);

		}
	}

}

int main()
{


	vector<Node*> children;
	children.push_back(nullptr);
	Node* six = new Node(6, children);

	Node* five = new Node(5, children);

	Node* four = new Node(4, children);

	Node* two = new Node(2, children);

	children.push_back(four);
	children.push_back(five);
	children.push_back(six);


	Node* three = new Node(3, children);


	vector<Node*> rootChildren;
	rootChildren.push_back(two);
	rootChildren.push_back(three);

	Node* eight = new Node(8, rootChildren);

	bool has = false;
	member(eight, 3, has);
	//cout << has;
	//cout << member2(eight, 3);

	filterOdd(eight);
	print(eight);

	system("pause");

}