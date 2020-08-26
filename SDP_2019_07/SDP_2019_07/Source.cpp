#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;



struct Node
{
	pair<char, int> data;
	vector<Node*> children;

};


char sym(Node* node)
{
	return node->data.first;
}
int val(Node* node)
{
	return node->data.second
 ;
}

void wordBranch(Node* u, string word, int sum, vector<pair<string, int>> &allBranches)
{
	if (u == nullptr)
	{
		allBranches.push_back(pair<string, int> (word, sum));
	}
	word = word + sym(u);
	sum = sum + val(u);
	for (Node* child : u->children)
	{
		wordBranch(child, word, sum, allBranches);
	}
}

int sumVal(Node* T, Node* u, Node* v)
{
	vector<pair<string, int>> VBranches;
	vector<pair<string, int>> UBranches;
	wordBranch(u, "", 0, UBranches);
	wordBranch(v, "", 0, VBranches);
	int sum = 0;
	for (size_t i = 0; i < UBranches.size(); i++)
	{
		for (size_t j = 0; j < VBranches.size(); j++)
		{
			if (UBranches.at(i).first ==  VBranches.at(j).first)
			{ 
				sum = sum + UBranches.at(i).second + VBranches.at(i).second;
			}
		}
	}
	return sum;


}







