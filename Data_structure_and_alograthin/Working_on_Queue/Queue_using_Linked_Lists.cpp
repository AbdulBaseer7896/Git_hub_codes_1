#include <iostream>
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


class quee_using_link_list
{
    node * first;
    node * last;

public:
    quee_using_link_list()
    {
        this->first = NULL;
        this->last = NULL;
    }

    void display()
    {
        cout<<"I am display"<<endl;
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void enque(int val)
    {
        node *newnode = new node(val);

        if(newnode == NULL)
        {
            cout<<"The quee is full"<<endl;
            return;
        }

        if (first == NULL)
        {
            first = newnode;
            return;
        }

        node *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

        

    void enque_in_quee_properly(int val)
    {
        node *newnode = new node(val);
        if(newnode == NULL)
        {
            cout<<"The quee is full"<<endl;
        }
        else
        {
            newnode->data = val;
            newnode->next = NULL;
            if(first == NULL)
            {
                first = last = newnode;
            }
            else
            {
                last->next = newnode;
                last =  newnode;
            }
        }
    }
    void deque()
    {
        node *ptr = first;
        if(ptr == NULL)
        {
            cout<<"quee is empty"<<endl;
            return;
        }
        cout<<"This element is dquee = "<<ptr->data<<endl;
        first = first->next;
        free(ptr);
    };
};
int main()
{

quee_using_link_list q;
q.enque_in_quee_properly(5);
q.enque_in_quee_properly(4);
q.enque_in_quee_properly(3);
q.enque_in_quee_properly(2);
q.enque_in_quee_properly(1);

q.deque();
q.deque();
q.deque();
q.deque();
q.deque();
// cout<<"hell";
q.display();


return 0;
}