#include <iostream>
#include <queue>
using namespace std;

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// Preorder: 1 2 4 5 7 3 6
// Inorder: 4 2 5 7 1 3 6
// Postorder: 4 7 5 2 6 3 1
/*
    Level order
    1
    2 3
    4 5 6
    7
*/

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

// Levelorder Traversal
void printLevelorder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        if (temp == NULL)
        {
            cout << endl;
            q.pop();

            // Insert new null for next level
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            q.pop();
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

Node *levelorderBuild()
{
    int d;
    cin >> d;

    Node *root = new Node(d);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int child1_data, child2_data;
        cin >> child1_data >> child2_data;

        if (child1_data != -1)
        {
            current->left = new Node(child1_data);
            q.push(current->left);
        }

        if (child2_data != -1)
        {
            current->right = new Node(child2_data);
            q.push(current->right);
        }
    }

    return root;
}

int main()
{
    Node *root = levelorderBuild();
    printLevelorder(root);
}
