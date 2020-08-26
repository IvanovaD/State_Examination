#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <cassert>
using namespace std;

void readFile(const string& fileName, string& treeInput)
{
    ifstream fin;
    fin.open(fileName);
    getline(fin, treeInput);
}

void removeSpaces(string& treeInput)
{
    string newTreeInput;
    for (int i = 0; i < treeInput.length(); i++)
    {
        if (treeInput[i] != ' ')
        {
            newTreeInput += treeInput[i];
        }
    }
    treeInput = newTreeInput;
}

int getData(const string& subtree) /// we expect the format of 'subtree' to be "(<number>(...))"
{
    assert(subtree.length() > 2);

    int data = 0;
    int i = 1;
    while (i < subtree.length() && '0' <= subtree[i] && subtree[i] <= '9')
    {
        data = data * 10 + (subtree[i] - '0');
        i++;
    }
    return data;
}

void getChildsFromChildsList(const string& childsList, vector<string>& childs)
{
    int i = 0;
    while (i < childsList.length())
    {
        i++;
        int startChildIdx = i;
        if (childsList[startChildIdx] != '(')
        {
            continue;
        }
        int openBrackets = 1;
        i++;
        while (openBrackets > 0 && i < childsList.length())
        {
            if (childsList[i] == '(')
            {
                openBrackets++;
            }
            else if (childsList[i] == ')')
            {
                openBrackets--;
            }
            i++;
        }
        string child = childsList.substr(startChildIdx, i - startChildIdx);
        childs.push_back(child);
    }
}

void getChilds(const string& subtree, vector<string>& childs)
{
    int i = 1;
    while (i < subtree.length() && '0' <= subtree[i] && subtree[i] <= '9')
    {
        i++;
    }
    string childsList = subtree.substr(i, subtree.length() - i - 1);
    getChildsFromChildsList(childsList, childs);
}

void buildTreeWithBFS(const string& treeInput, unordered_map<int, int>& sonToFather, vector<int>& leafs)
{
    queue <string> q;
    q.push(treeInput);

    while (!q.empty())
    {
        string subtree = q.front();
        q.pop();
        int data = getData(subtree);
        vector<string> childs;
        getChilds(subtree, childs);

        if (childs.size() == 0)
        {
            leafs.push_back(data);
        }

        for (int i = 0; i < childs.size(); i++)
        {
            int childData = getData(childs[i]);
            sonToFather.insert(make_pair(childData, data));
            q.push(childs[i]);
        }
    }
}

int calculateSumFromLeafToRoot(int son, unordered_map<int, int>& sonToFather)
{
    unordered_map<int, int>::iterator it = sonToFather.find(son);
    if (it == sonToFather.end())
    {
        return son;
    }
    int father = it->second;
    return son + calculateSumFromLeafToRoot(father, sonToFather);
}

void solve(const string& treeInput)
{
    unordered_map<int, int> sonToFather;
    vector<int> leafs;
    buildTreeWithBFS(treeInput, sonToFather, leafs);

    int max_sum = leafs[0];
    for (int i = 0; i < leafs.size(); i++)
    {
        int sum = calculateSumFromLeafToRoot(leafs[i], sonToFather);
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }
    cout << max_sum << endl;
}

int main()
{
    string treeInput;
    readFile("input.txt", treeInput);

    removeSpaces(treeInput);

    vector<string> childs;
    getChilds(treeInput, childs);

    solve(treeInput);

    return 0;
}
