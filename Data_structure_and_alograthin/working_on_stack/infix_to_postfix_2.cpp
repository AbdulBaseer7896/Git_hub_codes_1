#include<iostream>
using namespace std;

class node
{
    public:
    char data;
    node * next;
    
    node()
    {
        this->data = 0;
        this->next = NULL;
    }

    node(char val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class stack
{
    node * top;
    public:
    stack()
    {
        top = NULL;
    }

    char push(char val)
    {
        node * temp = top;
        node * newnode = new node(val);
        if(top == NULL)
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }


    void pop()
    {
        node * temp = top;
        if(top == NULL)
        {
            cout<<"The stack is underflow empty"<<endl;
            return;
        }
        else
        {
            cout<<"The pop value is = "<<top->data<<endl;
            temp = top;
            top = temp->next;
            delete temp;
        }
    }

    void infix_to_post_pix(char * val)
    {
        node * newnode = new node(val);

        
    }



};
int main()
{

stack s;

s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);

s.pop();
s.pop();
s.pop();


return 0;
}