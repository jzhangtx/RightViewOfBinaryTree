// RightViewOfBinTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

void ProcessNode(Node* root, int index, std::map<int, Node*>& m)
{
    if (root == nullptr)
        return;

    // if index exists, overwrite it with its right neighbor
    m[index] = root;

    // On the same level, the very next right node will cover the left one

    // The next level, index increments by 1. We must do the left node in
    //  terms of the scenario of right child has a smaller heights
    ProcessNode(root->left, index + 1, m);
    ProcessNode(root->right, index + 1, m);
}

std::vector<int> RightView(Node* root)
{
    std::vector<int> result;
    std::map<int, Node*> m;

    ProcessNode(root, 0, m);

    for (auto& n : m)
        result.push_back(n.second->data);

    return result;
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Values of the tree nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> v[i];

        Node* root = ArrayToTree(v);

        std::vector<int> result = RightView(root);
        if (!result.empty())
            std::cout << result[0];
        for (size_t i = 1; i < result.size(); ++i)
            std::cout << ", " << result[i];
        std::cout << std::endl;

        FreeTree(root);
    }
}
