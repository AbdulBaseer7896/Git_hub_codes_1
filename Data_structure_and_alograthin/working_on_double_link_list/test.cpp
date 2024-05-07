#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node * next;

    node()
    {
        data = 0;
        next = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


class Link_list
{
    node * head;
    public:
    Link_list()
    {
        head =NULL;
    }


    void display()
    {
        node * temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
    void inster_function(int val)
    {
        node * newnode = new node(val);

        if(head == NULL)
        {
            head = newnode;
            return;
        }

        node* temp = head;
        while(temp->next != NULL)
        {
            temp =temp->next;
        }
        temp->next = newnode;
    }

};
int main()
{

Link_list num;

num.inster_function(34);
num.inster_function(34);
num.inster_function(3454);
num.inster_function(224);
num.inster_function(14);
num.inster_function(994);
num.display();

return 0;
}