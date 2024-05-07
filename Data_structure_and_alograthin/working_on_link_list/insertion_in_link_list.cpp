#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void display_function_using_loop(struct node *ptrss)
{
    int num = 1;
    while (ptrss != NULL)
    {
        cout << "The data at index " << num << " is = " << ptrss->data << endl;
        ptrss = ptrss->next;
        num++;
    }
}


struct node * insertion_at_first(struct node *head , int data)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}


struct node* insertion_at_end(struct node *head , int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
 
 return head;
};

struct  node * instertion_after_give_node(struct node * head , struct node *priveious_node, int data)
{

    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->next = priveious_node->next;
    ptr->data = data;
    priveious_node->next = ptr;
    return head;
};



struct  node* instertion_in_between_to_elements(struct node *head, int data, int index)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    struct node * p = head;

    int i =0;
    while (i!=index -1)
    {
        p = p->next;
        i++;
    }
    ptr = p->next;
        
    ptr->data = data;
    p->next = ptr;
    return head;
    
};


void insert_function()
{

}

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

    // head = insertion_at_first(head, 5555);
    // head = instertion_in_between_to_elements(head, 9999, 1);
    // head = insertion_at_end(head , 666);
    head = instertion_after_give_node(head ,secound , 4444);
    display_function_using_loop(head);

    return 0;
}