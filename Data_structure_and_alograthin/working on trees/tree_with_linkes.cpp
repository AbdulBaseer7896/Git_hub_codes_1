#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * letf;
    node * right;

    node()
    {
        this->data = 0;
        this->letf = NULL;
        this->right = NULL;
    }
};



int main()
{


node *n1 = new node();
node *n2 = new node();
node *n3 = new node();

n1->data = 34;
n1->letf = n2;
n1->right = n3;


n2->data = 55;
// cout<<"hell0";

n3->data = 56;



cout<<n3->data<<endl;
cout<<(n1->letf)<<endl;


return 0;
} 