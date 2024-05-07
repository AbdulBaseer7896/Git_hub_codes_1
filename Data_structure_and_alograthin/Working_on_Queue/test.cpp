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
    }
    void delete_the_first_node()
    {
        node *ptr = head;
        head = head->next;
        delete ptr;
    };
    void delete_end_node()
    {
    	node *ptrs1 = head->next;
    	node* ptrs2 = head;
    	while(ptrs1->next!=NULL)
    	{
    	ptrs1 = ptrs1->next;
    	ptrs2 = ptrs2->next;
    	
	}
	delete ptrs1;
	ptrs2->next = NULL;
}
void delete_index(int index)
{
	node* ptr1 = head->next;
	node* ptr2 = head;
	for(int i = 1;i<index;i++)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr1->next;
	delete ptr1;
	
	
}
};

int main()
{
    link_list num;

    num.insertnode(23);
    num.insertnode(223);
    num.insertnode(233);
    num.insertnode(22333);
    num.insertnode(29993);



    num.delete_index(2);
    num.display();
    return 0;
}