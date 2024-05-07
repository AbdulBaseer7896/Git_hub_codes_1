#include<iostream>
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
    // int array[9];

// int i=0;
void inorder_triversal(node * root)
{

    if(root != NULL)
    {
        inorder_triversal(root->left);
        cout<<root->data<<" -> ";
        // array[i] = root->data;    i++;
        inorder_triversal(root->right);
    }
}
// BST = Binary Search Tree. 

void is_sorted(int array[7])
{
    for(int i=0; i<5; i++)
    {
        cout<<array[i]<<" ";
        if(array[i]> array[i+1])
        {
            cout<<endl<<"The array is not sorted and It is not BST."<<endl;
            return;
        }
    }
    cout<<"The tree is bineary search tree BST."<<endl;
}

int j=0;
int array[7];
void cheek_the_tree_in_BST_or_not(node * root)
{
    if(root !=NULL)
    {
        inorder_triversal(root->left);
        cout<<root->data<<" -> ";
        array[j]=root->data;
        j++;
        cout<<array[j]<<" ";
        inorder_triversal(root->right);
    }
    is_sorted(array);
}


int main()
{


node * root = new node(9);
node * left_chile = new node(4);
node * right_chile = new node(11);

node * left_sub_left = new node(2);
node * left_sub_right = new node(7);


node * right_sub_left = new node(12);
node * right_sub_right = new node(14);

root->left = left_chile;
root->right = right_chile;

left_chile->left = left_sub_left;
left_chile->right = left_sub_right;

right_chile->left = right_sub_left;
right_chile->right = right_sub_right;

inorder_triversal(root);
cout<<endl;
// for(int i=0; i<9;i++)
// {
//     cout<<array[i]<<" -> ";
// }
cheek_the_tree_in_BST_or_not(root); 
return 0;
}