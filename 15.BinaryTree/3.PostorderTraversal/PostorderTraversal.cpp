#include <iostream>
using namespace std;

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// Preorder: 1 2 4 5 7 3 6
// Inorder: 4 2 5 7 1 3 6
// Postorder: 4 7 5 2 6 3 1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Preorder Build of Tree - Root Left Right
Node *buildTree()
{
    int data;
    cin >> data;

    // Base case
    if (data == -1)
        return NULL;

    // Recursive case
    Node *n = new Node(data);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

// Preorder Traversal of Tree
void printPreorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Inorder Traversal of Tree
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Postorder Traversal of Tree
void printPostorder(Node *root)
{
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = buildTree();
    printPostorder(root);
}
