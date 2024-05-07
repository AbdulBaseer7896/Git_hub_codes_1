#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * left;
    node * right;

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


void inorder_triversal(node * root)
{
    if(root != NULL)
    {
    inorder_triversal(root->left);
    cout<<root->data<<" -> ";
    inorder_triversal(root->right);
    }

}

int Is_BST(node * root)
{
   static node * prev  = NULL;

    if(root != NULL)
    {
        if(!Is_BST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data )
        {
            return 0;
        }
        prev = root;
        return Is_BST(root->right);
    }
    else{
        return 1;
    }
}
int main()
{


node * root = new node(9);
node * left_chile = new node(4);
node * right_chile = new node(11);

node * left_sub_left = new node(2);
node * left_sub_right = new node(7);


node * right_sub_left = new node(10);
node * right_sub_right = new node(14);

root->left = left_chile;
root->right = right_chile;

left_chile->left = left_sub_left;
left_chile->right = left_sub_right;

right_chile->left = right_sub_left;
right_chile->right = right_sub_right;


cout<<"Ther traversal in Tree using IN -order concept"<<endl;
inorder_triversal(root);

int cheek = Is_BST(root);


    if(cheek == 1)
    {
        cout<<"\nThe tree is Binery search tree"<<endl;
    }
    else
    {
        cout<<"\nThe tree is not a Binery search tree"<<endl;
    }


return 0;
}