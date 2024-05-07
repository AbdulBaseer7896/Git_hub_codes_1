#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class tree
{
    node *roots;

public:
    tree()
    {
        roots = NULL;
    }
    void inorder_triversal(node *root)
    {
        if (root != NULL)
        {
            inorder_triversal(root->left);
            cout << root->data << " -> ";
            inorder_triversal(root->right);
        }
    }

    node *searching_in_BST(node *root, int val)
    {
        static int i = 0;
        if (root != NULL)
        {
            i++;
            if (val == root->data)
            {
                cout << "The vlaue is found: root" << endl;
                cout << "The i = " << i << endl;
                return root;
            }
            else if (val > root->data)
            {
                return searching_in_BST(root->right, val);
            }
            else
            {
                return searching_in_BST(root->left, val);
            }
            cout << "The value in not found in this tree :" << endl;
        }
    }
};
int main()
{

    node *root = new node(9);
    node *left_chile = new node(4);
    node *right_chile = new node(11);

    node *left_sub_left = new node(2);
    node *left_sub_right = new node(7);

    node *right_sub_left = new node(10);
    node *right_sub_right = new node(14);

    root->left = left_chile;
    root->right = right_chile;

    left_chile->left = left_sub_left;
    left_chile->right = left_sub_right;

    right_chile->left = right_sub_left;
    right_chile->right = right_sub_right;

    tree t;
    cout << "Ther traversal in Tree using IN -order concept" << endl;
    t.inorder_triversal(root);
    cout << endl;
    t.searching_in_BST(root, 7);

    return 0;
}