#include<iostream>
#include<fstream>
#include <vector>

using namespace std;

struct Node
{
	int value;
	vector<Node*> children;
};
Node* search(istream& fi)
{
	Node* tree = new Node();
	char c;
	c = fi.get();

	if (c == ')')
	{
		return nullptr;
	}

	int n = 0;
	fi >> n;
	if (!fi)
	{
		fi.clear();
	}
	tree->value = n; 
	//cout << tree->value<<endl;

	while ((c = fi.get()) != ')')
	{
		if (c == '(')
		{
			tree->children.push_back(search(fi));
		}
		if (c == ',')
		{
			fi.get();
			tree->children.push_back(search(fi));
		}
}
	  return tree;
}

int maxSum(Node* tree, int sum, int& curr_max)
{
	if (tree == nullptr)
	  { 
		if (sum > curr_max)
		{
			curr_max = sum;
		}
		return curr_max;
	  }
	sum += tree->value;

	for (Node* child : tree->children) //Така ли се записва?
	{
		maxSum(child, sum, curr_max);
	}
	return curr_max;

}
Node* readFromFile(const char* filename)
{
	ifstream fi;
	fi.open(filename);
	return search(fi);
}

void deleteTree(Node* tree)
{
	if (tree == nullptr)
	{
		return;
	}
	for (Node* child : tree->children)
	{
		deleteTree(child);
	}
	delete tree;
}

int main()
{
	Node* tree = readFromFile("treeFile.txt");
	int curr_max = 0;
	cout<<maxSum(tree, 0, curr_max)<<endl;x
	deleteTree(tree);

	system("pause");

	return 0;

}