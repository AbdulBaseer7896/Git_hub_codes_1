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

    int pop()
    {
        node *temp;
        if (top == NULL)
        {
            cout << "The expressing is not right )" << endl;
            return -1;
        }
        else
        {
            temp = top;
            // cout<<"This is element = "<<temp->data<<endl;
            top = temp->next;
            // n = n->next;
            free(temp);
        }
        return 0;
    }

    void parenthesis_matching(char *exp)
    {
        node * temp = new node();

        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(')
            {
                push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                if (top == NULL)
                {
                    cout << "This expressing is not well" << endl;
                    return;
                }
                pop();
            }
        }

        if (top == NULL)
        {
            cout << "This expresing is right" << endl;
        }
        else
        {
            cout << "This expressing is not right" << endl;
        }
    }
};

int main() 
{

    stack s;
    char * exp = "a +b (7+9)";
    s.parenthesis_matching(exp);
    return 0;
}