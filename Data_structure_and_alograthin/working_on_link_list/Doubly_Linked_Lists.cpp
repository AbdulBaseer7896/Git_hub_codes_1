#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    head->prev = fourth;

    secound->data = 2;
    secound->next = third;
    secound->prev = head;

    third->data = 3;
    third->next = fourth;
    third->prev = secound;

    fourth->data = 4;
    fourth->next =head;
    fourth->prev = third;



return 0;
}