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

    void insert_in_AVL(node *root, int data)
    {
        node *prev = NULL;

        while (root != NULL)
        {
            prev = root;
            if (root->data == data)
            {
                cout << "This data is already present in tree " << endl;
                return;
            }

            else if (root->data > data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        node *new_node = new node(data);

        if (prev->data > data)
        {
            prev->left = new_node;
        }
        else
        {
            prev->right = new_node;
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

            int different = abs(distance_1 - distance_2);

            if(different > 1)
            {
                cheek = cheek && false;
            }
            Inorder_util(root->right, cheek);
        }

    }

    void Right_rotate(node * y_node)
    {
        node * x_node = y_node->left;
        node * T2 = x_node->right;
        x_node->right = y_node;
        y_node->left = T2;
    }

    void left_rotate(node * x_node)
    {
        node * y_node = x_node->right;
        node * T2 = y_node->left;

        y_node->left = x_node;
        x_node->right = T2;
    }

};
int main()
{

    tree t;
    node *root = new node(6);
    // cout << "hello";
    t.insert_in_AVL(root, 7);
    t.insert_in_AVL(root, 8);
    // t.insert_in_AVL(root, 3);
    // t.insert_in_AVL(root, 1);

    t.InOreder_display(root);
    cout<<"\nThe height of tree = "<<t.height(root)<<endl;
    // bool a = true;
    // t.Inorder_util(root , a);

    cout<<"THis will tell us that your tree is balanced or not "<<t.IsBalanced(root)<<endl;

    // t.Right_rotate(root);
    t.left_rotate(root);

  cout<<"\n\nTHis will tell us that your tree is balanced or not "<<t.IsBalanced(root)<<endl;



    return 0;
}