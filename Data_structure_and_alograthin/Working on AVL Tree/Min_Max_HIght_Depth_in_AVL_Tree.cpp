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

    int getheight(node *root)
    {
        if (root == NULL)
        {
            // cout << "The root is equal to = ";
            return 0;
        }
        // cout << "The height of tree is = ";
        return root->height;
    }

    int balanceFactor(node *root)
    {
        if (root == NULL)
        {
            // cout << "The balance factor of root 0 = ";
            return 0;
        }
        else
        {
            // cout << "The balanc factor of root = ";
            return getheight(root->left) - getheight(root->right);
        }
    }

    node *right_Rotate(node *y)
    {
        node *x = y->left;
        node *t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(getheight(y->right), getheight(y->left)) + 1;
        x->height = max(getheight(x->right), getheight(x->left)) + 1;
        return x;
    }

    node *left_Rotate(node *x)
    {
        node *y = x->right;
        node *t2 = y->left;

        y->left = x;
        x->right = t2;

        y->height = max(getheight(y->right), getheight(y->left)) + 1;
        x->height = max(getheight(x->right), getheight(x->left)) + 1;
        return y;
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

    node *insert(node *node, int data)
    {
        if (node == NULL)
            return createNode(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);

        node->height = 1 + max(getheight(node->left), getheight(node->right));
        int bf = balanceFactor(node);

        // Left Left Case
        if (bf > 1 && data < node->left->data)
        {
            return right_Rotate(node);
        }
        // Right Right Case
        if (bf < -1 && data > node->right->data)
        {
            return left_Rotate(node);
        }
        // Left Right Case
        if (bf > 1 && data > node->left->data)
        {
            node->left = left_Rotate(node->left);
            return right_Rotate(node);
        }
        // Right Left Case
        if (bf < -1 && data < node->right->data)
        {
            node->right = right_Rotate(node->right);
            return left_Rotate(node);
        }
        return node;
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

    void Finding_Min_in_AVL_Tree(node *root)
    {
        if (root == NULL)
        {
            cout << "The Tree is empty:" << endl;
            return;
        }
        while (root->left != NULL)
        {
            root = root->left;
        }
        cout << "The Min Value in this AVT Tree is = " << root->data << endl;
    }

    void Finding_Max_in_AVL_Tree(node *root)
    {
        if (root == NULL)
        {
            cout << "The Tree is empty:" << endl;
            return;
        }
        while (root->right != NULL)
        {
            root = root->right;
        }
        cout << "The Max Value in this AVT Tree is = " << root->data << endl;
    }

int Find_height_of_node(node *root) {
    if (root == NULL) return 0;
    else if (root->left == NULL && root->right == NULL) return 0;
    return 1 + max (Find_height_of_node(root->left), Find_height_of_node(root->right));
 }

int Find_depth_of_node(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int l_depth = Find_depth_of_node(node->left);
        int r_depth = Find_depth_of_node(node->right);
 
        /* use the larger one */
        if (l_depth > r_depth)
            return (l_depth + 1);
        else
            return (r_depth + 1);
    }
}

 


};

int main()
{

    tree t;
    // node *root = new node(99);
    // root = t.insert(root, 6);
    // root = t.insert(root, 2);
    // root = t.insert(root, 8);
    // root = t.insert(root, 9);
    // root = t.insert(root, 5);
    // root = t.insert(root, 89);
    // root = t.insert(root, 12);
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


    t.inorder_triversal(root);
    cout << endl;
    t.Finding_Min_in_AVL_Tree(root);
    t.Finding_Max_in_AVL_Tree(root);
    cout<<"This is depth of given node = ";
    cout<<t.Find_depth_of_node(root);
    cout<<"\nThe hight of given node = ";
    cout<<t.Find_height_of_node(root)<<endl;
	return 0;

}

// node *root = new node(9);
// node *left_chile = new node(4);
// node *right_chile = new node(11);

// node *left_sub_left = new node(2);
// node *left_sub_right = new node(7);

// node *right_sub_left = new node(10);
// node *right_sub_right = new node(14);

// root->left = left_chile;
// root->right = right_chile;

// left_chile->left = left_sub_left;
// left_chile->right = left_sub_right;

// right_chile->left = right_sub_left;
// right_chile->right = right_sub_right;

// void iterative_searching_in_BST(node *root, int data)
// {
//     static int i = 0;
//     while (root != NULL)
//     {
//         i++;
//         if (data == root->data)
//         {
//             cout << "The value is found : i = " << i << endl;
//             return;
//         }
//         else if (root->data > data)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
// }

// void insertion_in_BST(node *root, int data)
// {
//     node *root = NULL;

//     while (root != NULL)
//     {
//         root = root;
//         if (data == root->data)
//         {
//             cout << "This value in already abaiable in tree = " << data << endl;
//             return;
//         }
//         else if (data > root->data)
//         {
//             root = root->right;
//         }
//         else
//         {
//             root = root->left;
//         }
//     }

//     node *newnode = new node(data);

//     if (data < root->data)
//     {
//         root->left = newnode;
//     }
//     else
//     {
//         root->right = newnode;
//     }
// }