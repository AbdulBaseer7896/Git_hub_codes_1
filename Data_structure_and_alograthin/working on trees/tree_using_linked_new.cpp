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
        this->data= 0;
        this->left = NULL;
        this->right = NULL;
    }

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

    node creating_node_of_tree(int val)
    {
        node * newnode = new node(val);

    }
};

void traversal_using_recursion(node * root)
{
    if(root != NULL)
    {
        cout<<root->data<<" --> ";
        traversal_using_recursion(root->left);
        traversal_using_recursion(root->right);
    }
} 
int main()
{

node * root = new node(1);
node * left_chile = new node(2);
node * right_chile = new node(3);

node * left_sub_left = new node(4);
node * left_sub_right = new node(5);


node * right_sub_left = new node();
node * right_sub_right = new node(7);

root->left = left_chile;
root->right = right_chile;

left_chile->left = left_sub_left;
left_chile->right = left_sub_right;

right_chile->left = right_sub_left;
right_chile->right = right_sub_right;

traversal_using_recursion(root);
cout<<"hello";




return 0;
}