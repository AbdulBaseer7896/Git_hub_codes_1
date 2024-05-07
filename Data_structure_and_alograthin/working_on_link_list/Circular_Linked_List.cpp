#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

void display_function_using_loop(struct node *head)
{
    int num = 0;
    struct node* ptr = head;
    ptr = ptr;
    do
    {
        cout << "The data at index " << num << " is = " << ptr->data << endl;
        ptr = ptr->next;
        num++;
    } while (ptr != head);
    
};

int main()
{

    struct node *head;
    struct node *secound;
    struct node *third;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    secound = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 11;
    head->next = secound;

    secound->data = 2;
    secound->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next =head;

    display_function_using_loop(head);


return 0;
}