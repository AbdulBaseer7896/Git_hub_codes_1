#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node()
    {
        this->data = 0;
        this->right = NULL;
        this->left = NULL;
    }
    node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
};

class tree
{
public:
    void inOrder_triversal(node *root)
    {
        if (root != NULL)
        {
            inOrder_triversal(root->left);
            cout << root->data << " -> ";
            inOrder_triversal(root->right);
        }
    }

    void insert_in_BST(node *root, int val)
    {
        node *prev = NULL;
        while (root != NULL)
        {
            prev = root;
            if (root->data == val)
            {
                cout << "This val is already present in tree = " << val << endl;
                return;
            }
            else if (root->data > val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        node *newnode = new node(val);

        if (prev->data > val)
        {
            prev->left = newnode;
        }
        else
        {
            prev->right = newnode;
        }
    }

    node *inoreder_predecessor(node *root)
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }

    node *delete_node_from_tree(node *root, int val)
    {
        if (root == NULL)
        {
            cout << "The tree is empty." << endl;
            return NULL;
        }

        if (root->left == NULL && root->right == NULL)
        {
            cout << "\nThe val is deleated now" << endl;
            free(root);
            return NULL;
        }

        node *ipre;
        
        if (val < root->data)
        {
            root->left = delete_node_from_tree(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = delete_node_from_tree(root->right, val);
        }
        else
        {
            ipre = inoreder_predecessor(root);
            root->data = ipre->data;
            root->left = delete_node_from_tree(root->left, ipre->data);
        }
        return root;
    }
};
int main()
{

    node *root = new node(6);

    tree t;
    t.insert_in_BST(root, 45);
    t.insert_in_BST(root, 5);
    t.insert_in_BST(root, 335);
    t.insert_in_BST(root, 4);
    t.insert_in_BST(root, 923);
    t.insert_in_BST(root, 99);
    t.inOrder_triversal(root);
    // t.inOrder_triversal(root);
    t.delete_node_from_tree(root, 5);
    t.inOrder_triversal(root);
    return 0;
}