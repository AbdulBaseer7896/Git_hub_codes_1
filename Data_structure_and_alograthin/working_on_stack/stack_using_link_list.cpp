#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    void push(int num)
    {
        node *temp = new node();

        if (temp == NULL)
        {
            cout << "The stack is overflow" << endl;
            return;
        }
        else
        {
            temp->data = num;
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        node *temp;
        if (top == NULL)
        {
            cout << "The stack is empty" << endl;
        }
        else
        {
            temp = top;
            cout << "This is element = " << temp->data << endl;
            top = temp->next;
            // n = n->next;
            delete temp;
        }
    }

    void display()
    {
        node *temp;

        // Check for stack underflow
        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                // Print node data
                cout << temp->data;

                // Assign temp link to temp
                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }

    int peek(int num)
    {
        cout << "i am peek" << endl;
        node *temp = top;

        if (top == NULL)
        {
            cout << "You stack is empty" << endl;
        }
        else
        {
            for (int i = 0; (i < num - 1 && temp != NULL); i++)
            {
                temp = temp->next;
            }
            // cout<<endl<<"The peek value of "<<num<<" = "<<temp->data<<endl;
        }
        int fine = temp->data;
        return fine;
    }

    void top_botton_in_stack()
    {
        node *temp = top;
        cout << "\nThe top must element in the stack is = " << top->data << endl;

        while (temp != NULL)
        {
            temp = temp->next;
        }
        cout << "The bottom most value in the stack is  = " << temp->data << endl;
    }

    void list_trivisal()
    {
        node *temp = top;
        int i = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            cout << "Value at position " << i + 1 << " = " << peek(i + 1) << endl;
            i++;
        }
    }
};
int main()
{

    stack s;
    s.push(23);
    s.push(10);
    s.push(89);
    // s.pop();4
    s.push(999);
    // s.pop();
    // s.display();
    // s.list_trivisal();
    // s.top_botton_in_stack();
    return 0;
}
