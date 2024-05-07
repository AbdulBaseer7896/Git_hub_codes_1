#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
void display_function_using_loop(struct node *ptrss)
{
    int num = 0;
    while (ptrss != NULL)
    {
        cout << "The data at index " << num << " is = " << ptrss->data << endl;
        ptrss = ptrss->next;
        num++;
    }
}

struct node * delete_the_first_node(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};



struct node * delete_the_end_node(struct node * head)
{
    struct node *ptr = head;
    struct node *q = head->next;
    
    while (q->next!=NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);

    return head;
};

struct node * deleating_the_node_form_give_index_in_link_list(struct node *head , int index)
{
    struct node *ptr = head;
    struct node *q = head->next;
    for(int i=0; i<index-1; i++)
    {
        ptr = ptr->next;
        q = q->next;
    }

    ptr->next = q->next;
    free(q);
    return head;
};

struct node * deleating_the_node_of_give_value_from_link_list(struct node *head, int value)
{
    struct node* ptr = head->next;
    struct node*  q = head;
    while (ptr->data != value && ptr->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if(ptr->data == value){
    q->next =ptr->next;
    free(ptr);
    }
    else{
        cout<<"value is not avabil right now"<<endl;
    }
    return head;    
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

    head->data = 1;
    head->next = secound;

    secound->data = 2;
    secound->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    // head = delete_the_first_node(head);
    // head = delete_the_end_node(head);
    head = deleating_the_node_of_give_value_from_link_list(head, 2);
    // head = deleating_the_node_form_give_index_in_link_list(head, 2);
    display_function_using_loop(head);
return 0;
}