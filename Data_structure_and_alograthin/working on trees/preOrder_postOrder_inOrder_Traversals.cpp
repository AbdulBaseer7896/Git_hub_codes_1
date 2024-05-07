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

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder_traversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " --> ";
        preOrder_traversal(root->left);
        preOrder_traversal(root->right);
    }
}
void postOrder_traversal(node * root)
{
    if(root != NULL)
    {
        postOrder_traversal(root->left);
        postOrder_traversal(root->right);
        cout << root->data << " --> ";
    }
}

void inOrder_traversal(node * root)
{
    if(root != NULL)
    {
        inOrder_traversal(root->left);
        cout << root->data << " --> ";
        inOrder_traversal(root->right);
    }
}
void traversal(node *root)
{
    node *temp = root;
    node *rights;
    node *lefts;
    if (temp == NULL)
    {
        cout << "The tree is empty" << endl;
        return;
    }
    cout << temp->data << " --> ";
    while (true)
    {
        rights = temp->left;
        lefts = temp->right;

        cout << rights->data << " --> ";
        cout << lefts->data << " --> ";

        if (rights->left == NULL && lefts->right == NULL)
        {
            temp == NULL;
            return;
        }
    }
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

cout<<"Ther traversal in Tree using Per-order concept"<<endl;
preOrder_traversal(root);


cout<<" \n\nTher traversal in Tree using post-order concept"<<endl;
postOrder_traversal(root);

cout<<"\n\nTher traversal in Tree using In-order concept"<<endl;
inOrder_traversal(root);

    return 0;
}
