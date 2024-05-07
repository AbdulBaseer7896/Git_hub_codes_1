#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    
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

class link_list
{
    node *head;

public:
    link_list()
    {
        head = NULL;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void insertnode(int val)
    {

        node *newnode = new node(val);

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;

        newnode->data = val;
        newnode->next = NULL;
    }

    void delete_the_first_node()
    {
        node *ptr = head;
        head = head->next;
        free(ptr);
    };

    void delete_the_end_node()
    {
        node *ptr = head;
        node *q = head->next;

        while (q->next != NULL)
        {
            ptr = ptr->next;
            q = q->next;
        }
        ptr->next = NULL;
        free(q);
    };

    void deleating_the_node_form_give_index_in_link_list(int index)
    {
        node *ptr = head;
        node *q = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
            q = q->next;
        }

        ptr->next = q->next;
        free(q);
    }

    void deleating_the_node_of_give_value_from_link_list(int value)
    {
        node *ptr = head->next;
        node *q = head;
        while (ptr->data != value && ptr->next != NULL)
        {
            ptr = ptr->next;
            q = q->next;
        }
        if (ptr->data == value)
        {
            q->next = ptr->next;
            free(ptr);
        }
        else
        {
            cout << "value is not avabil right now" << endl;
        }
    };
};

int main()
{
    link_list num;

    num.insertnode(23);
    num.insertnode(223);
    num.insertnode(233);
    num.insertnode(22333);
    num.insertnode(29993);
    // num.delete_the_end_node();
    num.deleating_the_node_form_give_index_in_link_list(3);
    num.display();

    return 0;
}