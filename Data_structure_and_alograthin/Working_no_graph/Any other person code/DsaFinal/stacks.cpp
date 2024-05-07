#include<iostream>
using namespace std;
struct node
	{
		int data;
		node *next;
	};
class Stack
{

public:
	node *top;
	void Push(int );
	void Pop(int &);
	bool IsEmpty();
	
	Stack(){
		top=NULL;
	}
};


//-------------//
void Stack::Push(int newelement)
{
	node *newptr;
	newptr=new node;
	newptr->data=newelement;
	newptr->next=top;
	top=newptr;
}
 void Stack::Pop(int & returnvalue)
{
	if (IsEmpty()) { cout<<"stack is empty\n";
	  return;}
	 node *tempptr=top;
	returnvalue=top->data;
	top=top->next;
	delete tempptr;
}


  bool Stack::IsEmpty()
{
	if (top==NULL) 
		return true;
	else 
		return false;
}



