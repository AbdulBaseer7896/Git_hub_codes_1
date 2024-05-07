#include <iostream>
using namespace std;

class node
{
public:
    int data;
    int height;
    node *left;
    node *right;

    node()
    {
        this->data = 0;
        this->height = 0;
        this->left = NULL;
        this->right = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }

    int tree_height(node *root)
    {
        if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 0;
        return 1 + max(tree_height(root->left), tree_height(root->right));
    }

    int height(node *node)
    { 
        if (node == NULL)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    bool Is_BST__is_AVL_tree(node *root)
    {
        int lh;
        int rh;
        if (root == NULL)
            return 1;
        lh = height(root->left);  // left height
        rh = height(root->right); // right height
        if (abs(lh - rh) <= 1 && Is_BST__is_AVL_tree(root->left) && Is_BST__is_AVL_tree(root->right))
            return 1;
        return 0;
    }

    int maxValue(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int value = root->data;
        int leftMax = maxValue(root->left);
        int rightMax = maxValue(root->right);

        return max(value, max(leftMax, rightMax));
    }

    int minValue(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int value = root->data;
        int leftMax = minValue(root->left);
        int rightMax = minValue(root->right);

        return min(value, min(leftMax, rightMax));
    }

    bool IS_tree_is_BST(node *root)
    {
        if (root == NULL)
            return 0;

        /* false if the max of the left is > than us */
        if (root->left != NULL && maxValue(root->left) > root->data)
            return 1;

        /* false if the min of the right is <= than us */
        if (root->right != NULL && minValue(root->right) < root->data)
            return 1;

        /* false if, recursively, the left or right is not a BST
         */
        if (!IS_tree_is_BST(root->left) || !IS_tree_is_BST(root->right))

            return 1;

        /* passing all that, it's a BST */
        return 0;
    }

    void Is_Tree_is_AVL(node *root)
    {
        // cout<<"This is tree"<<endl;

        if (IS_tree_is_BST(root) == 1)
        {
            if (Is_BST__is_AVL_tree(root) == 1)
            {
                cout << "The Given Tree is also BST and Its also AVL Tree" << endl;
                return;
            }
            else
            {
                cout << "The Given Tree is BST but Not a AVL Tree" << endl;
                return;
            }
        }
        else
        {
            cout << "The Given Tree is not BST tree. SO It also not a AVL Tree." << endl;
            return;
        }
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
};
int main()
{

    tree t;
    node *root = new node(9);
    node *left_chile = new node(45);
    node *right_chile = new node(11);
    node *midle_chile = new node(18);

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
    cout<<"The Tree no InOrder Triversal:"<<endl;
    t.inorder_triversal(root);
    cout<<endl;
    t.Is_Tree_is_AVL(root);
    return 0;
}