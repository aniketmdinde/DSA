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

int heightOfTree(Node *root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Recursive case
    int h1 = heightOfTree(root->left);
    int h2 = heightOfTree(root->right);
    return 1 + max(h1, h2);
}

int diameter(Node *root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Recursive case - 3 cases
    int D1 = heightOfTree(root->left) + heightOfTree(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}

// Optimized Diameter
class HDPair
{
public:
    int diameter;
    int height;
};

HDPair optimizedDiameter(Node *root)
{
    HDPair p;
    // Base ase
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }

    // Recursive Case
    HDPair Left = optimizedDiameter(root->left);
    HDPair Right = optimizedDiameter(root->right);

    // Calculate height
    p.height = max(Left.height, Right.height) + 1;

    // Calculate Diameter
    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;

    p.diameter = max(D1, max(D2, D3));
    return p;
}

int main()
{
    Node *root = levelorderBuild();
    printLevelorder(root);
    cout << "Diameter: " << optimizedDiameter(root).diameter << endl;

    return 0;
}