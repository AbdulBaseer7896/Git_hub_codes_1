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

    void iterative_searching_in_BST(node *root, int val)
    {
        static int i=0;
        while(root!= NULL)
        {
            i++;
            if(val == root->data)
            {
                cout<<"The value is found : i = "<<i<<endl;
                return;
            }
            else if(root->data > val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }

    void insertion_in_BST(node * root, int val)
    {
        node * prev = NULL;

        while(root != NULL)
        {
            prev = root;

            if(root->data == val)
            {
                cout<<"You repeat the node in the tree = "<<val<<endl;
                return;
            }
            else if(root->data < val)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        node * newnode = new node(val);

        if(prev->data >val)
        {
            prev->left = newnode;
        }
        else
        {
            prev->right = newnode;
        }
    }

    void deletion_the_leaf_node_in_BST(node * root , int val)
    {
        node * prev = NULL;

        while(root !=NULL)
        {
            if(root->data ==val && root->left == NULL && root->right == NULL)
            {
                cout<<"The node is delete now "<<val;
                free(root);
                return;
            }
            else if(root->data >val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        cout<<"The value in not found in the tree at leaf nodes."<<endl;
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
    // node *right_sub_right = new node(19);

    root->left = left_chile;
    root->right = right_chile;

    left_chile->left = left_sub_left;
    left_chile->right = left_sub_right;

    right_chile->left = right_sub_left;
    right_chile->right = right_sub_right;

    tree t;
    // t.insertion_in_BST(root , 12);
    // t.insertion_in_BST(root , 4);
    // t.insertion_in_BST(root , 7);
    // t.insertion_in_BST(root , 10);
    // t.insertion_in_BST(root , 3);
    cout << "Ther traversal in Tree using IN -order concept" << endl;
    t.inorder_triversal(root);
    cout << endl;
    t.deletion_the_leaf_node_in_BST(root , 7);
    cout<<endl;
    t.inorder_triversal(root);
    // t.iterative_searching_in_BST(root, 4);



    return 0;
}