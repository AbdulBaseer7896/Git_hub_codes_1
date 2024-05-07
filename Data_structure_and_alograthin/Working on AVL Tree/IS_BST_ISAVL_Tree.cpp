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
    node *createNode(int key)
    {
        node *nodes = new node(0);
        nodes->data = key;
        nodes->left = NULL;
        nodes->right = NULL;
        nodes->height = 1;
        return nodes;
    }


    int tree_height(node *root)
    {
        if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 0;
        return 1 + max(tree_height(root->left), tree_height(root->right));
    }



int height(node* node) { //get the height means the number of nodes along the longest path from the root
// node down to the farthest leaf node of the tree. 
   if(node == NULL)
      return 0;
   return 1 + max(height(node->left), height(node->right));
}

bool Is_BST__is_AVL_tree(node *root) {
   int lh;
   int rh;
   if(root == NULL)
      return 1;
   lh = height(root->left); // left height
   rh = height(root->right); // right height
   if(abs(lh-rh) <= 1 && Is_BST__is_AVL_tree(root->left) && Is_BST__is_AVL_tree(root->right)) return 1;
   return 0;
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
    // root->left = midle_chile;
    left_chile->left = left_sub_left;
    left_chile->right = left_sub_right;

    right_chile->left = right_sub_left;
    right_chile->right = right_sub_right;

   if(t.Is_BST__is_AVL_tree(root))
      cout << "The Given BST is AVL Tree"<<endl;
   else
      cout << "The Given BST is no AVL Tree "<<endl;
   return 0;
}