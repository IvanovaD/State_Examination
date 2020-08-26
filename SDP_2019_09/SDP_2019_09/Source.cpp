#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	int valueEdgeToParent;
	char labelEdgeToParent;
	vector<Node*> children;
};


int value(pair<Node*, Node*> p);
char label(pair<Node*, Node*> p);
void findWords(Node* u, int sum, string word, vector<pair<int, string>> &paths)
{

	if (u == nullptr)
	{
		paths.push_back(pair<int, string>(sum, word));
	}
	for (Node* child : u->children)
	{
		findWords(child, sum + value(pair<Node*, Node*>(u, child)), word + label(pair<Node*, Node*>(u, child)), paths);
	}

}

void CommonBranches(Node* T, Node* u, Node* v, int k) // другия вариант е да намерим всички думи
// само за единия възел и после да търсим дали всяка от тях може да се изгради от втория, без да генерираме
//всички възможности от втория
{
	vector<pair<int, string>> uWords;
	vector<pair<int, string>> vWords;
	findWords(T, 0, "", uWords);
	findWords(T, 0, "", vWords);


	for (size_t i = 0; i < vWords.size(); i++) {
		for (size_t j = 0; j < vWords.size(); j++) {
			if (vWords.at(i).second == uWords.at(j).second &&
				vWords.at(i).first + uWords.at(j).first == k)
			{
				cout << vWords.at(i).second << endl;
			}
		}
	}
}

