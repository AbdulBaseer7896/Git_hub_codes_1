#include<iostream>
using namespace std;

struct Node{
int data;
struct Node *next;
};

// struct Node*head = NULL;

void display_the_data_from_link_list(struct Node* ptr)
{
    cout<<"The data is = "<<ptr->data<<endl;
}


void display_function_using_loop(struct Node *ptrss)
{
    int num = 1;
    while (ptrss != NULL)
    {
        cout<<"The data at index "<<num<<" is = "<<ptrss->data<<endl;
        ptrss = ptrss->next;
        num++;

    }
    
}

int main()
{
    cout<<"This is working now"<<endl;
    struct Node * head;
    struct Node * secound;
    struct Node * third;
    struct Node * fourth;

head = (struct Node*) malloc(sizeof(struct Node));
secound = (struct Node*) malloc(sizeof(struct Node));
third = (struct Node*) malloc(sizeof(struct Node));
fourth = (struct Node*) malloc(sizeof(struct Node));



head->data = 1;
head->next = secound;

secound->data = 2;
secound->next = third;

third->data = 3;
third->next = fourth;

fourth->data = 4;
fourth->next = NULL;

// display_the_data_from_link_list(head);
// display_the_data_from_link_list(secound);
// display_the_data_from_link_list(third);
// display_the_data_from_link_list(fourth);


display_function_using_loop(secound);
cout<<"The program is end now as you see";



return 0;
}