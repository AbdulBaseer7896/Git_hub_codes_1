#include <iostream>
using namespace std;

class node
{
public:
    char data;
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
    char cheek_exp;

public:
    stack()
    {
        this->top = NULL;
    }

    void push(char exp)
    {
        cout<<"I am push"<<endl;
        node *temp = new node();

        if (temp == NULL)
        {
            cout << "Stack is over flow" << endl;
            return;
        }
        else
        {
            temp->data = exp;
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        cout<<"I am pop"<<endl;
        node *temp = top;
        if (top == NULL)
        {
            cout << "Your stack is empty" << endl;
            return;
        }
        else
        {
            // cout<<"The value is pop from the stack = "<<temp->data;
            cheek_exp = temp->data;
            top = temp->next;
            free(temp);
        }
        // return cheek_exp;
    }

    int match_function(char a, char b)
    {
        if(a== '(' && b == ')')
        {
            return 0;
        }

        if(a== '[' && b == ']')
        {
            return 0;
        }

        if(a== '{' && b == '}')
        {
            return 0;
        }

        cout<<"The expressing is wrong match"<<endl;
    }

    void Multiple_Parenthesis_Matching(char *exp)
    {

        node *temp = top;
        if (top != NULL)
        {
            cout << "The stack is empty ..." << endl;
            // return;
        }
        else
        {

            for (int i = 0; (exp[i] != '\0'); i++)
            {
                if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                {
                    push(exp[i]);
                }

                else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
                {
                    
                    pop();
                    if (top == NULL)
                    {
                        cout << "The equationis not wright null" << endl;
                        return;
                    }
                    else if (!match_function(cheek_exp, top->data))
                    {
                        cout << "The expression is wrong" << endl;
                        return;
                    }
                }
            }

        }
            cout << "The equation is right" << endl;
    }
};
int main()
{

    stack s;
    char *exp = "3 + 5 [89+ x {45 + 45  + (c - b)]";

    s.Multiple_Parenthesis_Matching(exp);
    return 0;
}