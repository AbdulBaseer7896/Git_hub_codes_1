#include<iostream>
using namespace std;



class node
{
    public:
    int data;
    node * next;
    node * prev;

    node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};


class double_link_list
{
    node *head;
    public:
    double_link_list()
    {
        head = NULL;
    }



    void insert_function(int val)
    {
        node * newnode = new node(val);

        if(head == NULL)
        {
            newnode->prev = NULL;
            head = newnode;
            return;
        }
        node *temp = head;
        // node * prev_ptr = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        // temp->prev = 
    }



    void display()
    {
        node* temp = head;
        while(temp!= NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }



};
int main()
{



double_link_list num; 
num.insert_function(23);
num.insert_function(43);
num.insert_function(673);
num.display();
return 0;



}