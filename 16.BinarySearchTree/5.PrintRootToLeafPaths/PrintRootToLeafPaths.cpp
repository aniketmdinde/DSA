#include <iostream>
#include <vector>
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

// Helper Function
Node *findInorderSuccesor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete a node
Node *remove(Node *root, int key)
{
    // Search
    if (root == NULL)
        return NULL;
    else if (key < root->data)
        root->left = remove(root->left, key);
    else if (key > root->data)
        root->right = remove(root->right, key);
    else // Node found
    {
        // Three cases
        // Case 1: No children
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2: 1 children - Right Child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
            temp = NULL;
        }
        // Case 2: 1 children - Left Child
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            temp = NULL;
        }
        // Case 3: 2 children
        else
        {
            // Find inorder successor
            Node *temp = findInorderSuccesor(root->right);

            // Copy data
            root->data = temp->data;

            // Delete inorder success from that subtree
            root->right = remove(root->right, temp->data);
        }

        return root;
    }
}

void printInRange(Node *root, int k1, int k2)
{
    // Base case
    if (root == NULL)
        return;

    // Recursive case
    if (root->data >= k1 and root->data <= k2)
    {
        printInRange(root->left, k1, k2);
        cout << root->data << " ";
        printInRange(root->right, k1, k2);
    }
    else if (root->data > k2)
        printInRange(root->left, k1, k2);
    else
        printInRange(root->right, k1, k2);
}

void printRootToLeafPaths(Node *root, vector<int> path)
{
    // Base case
    if (root == NULL)
        return;

    if (root->left == NULL and root->right == NULL)
    {
        // print vector
        for (int node : path)
            cout << node << "->";

        cout << root->data << endl;
        return;
    }

    // Recursive case
    path.push_back(root->data);

    printRootToLeafPaths(root->left, path);
    printRootToLeafPaths(root->right, path);

    // Backtracking
    path.pop_back();
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

    vector<int> path;

    printRootToLeafPaths(root, path);

    return 0;
}
