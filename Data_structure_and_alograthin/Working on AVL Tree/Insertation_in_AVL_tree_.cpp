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
    // node * root;

public:
    void InOreder_display(node *root)
    {
        if (root != NULL)
        {
            InOreder_display(root->left);
            cout << root->data << " -> ";
            InOreder_display(root->right);
        }
    }

    int height(node * root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else{
            return (max(height(root->left) , height(root->right)) +1);
        }
    }

    bool IsBalanced(node * root)
    {
        bool cheek = true;
        Inorder_util(root , cheek);

        return cheek;
    }

    void Inorder_util(node * root, bool &cheek)
    {
        if(root != NULL)
        {
            Inorder_util(root->left , cheek);
            int data = root->data;

            int distance_1 = height(root->left);
            int distance_2 = height(root->right);

            int different =(distance_1 - distance_2);

            if(different > 1)
            {
                cheek = cheek && false;
            }
            Inorder_util(root->right, cheek);
        }

    }

    node * Right_rotate(node * y_node)
    {
        node * x_node = y_node->left;
        node * T2 = x_node->right;
        x_node->right = y_node;
        y_node->left = T2;
    }

    node * left_rotate(node * x_node)
    {
        node * y_node = x_node->right;
        node * T2 = y_node->left;

        y_node->left = x_node;
        x_node->right = T2;
    }


    node * insertation_in_ALV_tree(node * root , int data)
    {
        node *new_node = new node(data);
        if(root == NULL)
        {
            root = new_node;
        }

        if(root->data > data)
        {
            root->left = insertation_in_ALV_tree(root->left , data);
        }
        else if(root->data < data)
        {
            root->right = insertation_in_ALV_tree(root->right , data);
        }
        else
        {
            cout<<"Nothing";
        }

        int bf = IsBalanced(root);

        // left Left case
        if(bf > 1 && data < root->left->data)
        {
            Right_rotate(root);
        }
        // Right right case

        if(bf >1 && data > root->left->data)
        {
            root->left = left_rotate((root->left));
            left_rotate(root);
        }

        // Left Right case
        if(bf < -1 && data < root->right->data)
        {
            root->right = Right_rotate((root->left));
            left_rotate(root);
        }

        // if()
    }

};
int main()
{

    tree t;
    node *root = NULL;
    // cout << "hello";
    t.insertation_in_ALV_tree(root, 7);
    t.insertation_in_ALV_tree(root, 23);
    t.insertation_in_ALV_tree(root, 34);
    t.insertation_in_ALV_tree(root, 59);
    t.insertation_in_ALV_tree(root, 8);
    t.insertation_in_ALV_tree(root, 9);
    // t.insert_in_AVL(root, 3);
    // t.insert_in_AVL(root, 1);

    t.InOreder_display(root);
    cout<<"\nThe height of tree = "<<t.height(root)<<endl;
    // bool a = true;
    // t.Inorder_util(root , a);

    cout<<"THis will tell us that your tree is balanced or not "<<t.IsBalanced(root)<<endl;

    // t.Right_rotate(root);
    // t.left_rotate(root);

  cout<<"\n\nTHis will tell us that your tree is balanced or not "<<t.IsBalanced(root)<<endl;



    return 0;
}