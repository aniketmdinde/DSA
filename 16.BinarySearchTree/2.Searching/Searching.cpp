#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->data = key;
        left = right = NULL;
    }
};

Node *insert(Node *root, int data)
{
    // Base case
    if (root == NULL)
    {
        return new Node(data);
    }

    // Recursive case
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void printInorderTraversal(Node *root)
{
    // Base case
    if (root == NULL)
        return;

    // Recursive case
    printInorderTraversal(root->left);
    cout << root->data << " ";
    printInorderTraversal(root->right);
}

bool search(Node *root, int key)
{
    // Base case
    if (root == NULL)
        return false;

    // Recursive case
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    Node *root = NULL;

    int data[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int d : data)
    {
        root = insert(root, d);
    }

    printInorderTraversal(root);
    cout << endl;

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    cout << search(root, key) << endl;

    return 0;
}
