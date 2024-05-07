#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node * next;
		
		node()
		{
			data=0;
			next=NULL;
		}
		node(int value)
		{
			data=value;
			next=NULL;
		}
		
		
	
};


class link_list
{
	node  * head;
	public:

	link_list()
	{
		head = NULL;
	
	}	
	
	
	void display()
	{
		cout<<"hello iam display";
		node * temp =  head;
		while(temp!=NULL)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}	
	
	void insertatlast(int val)
	{
		node*temp=head;
		node*newnode=new node(val);
		
		while(temp!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		// newnode->next=NULL;
	}	
};





int main()
{
    

	link_list l1;
	// cout<<"i am hear";


	l1.insertatlast(1);
	l1.insertatlast(2);
	l1.insertatlast(3);

	l1.display();

	
}