#include<iostream>

using namespace std;
class Node{
	public:
		int value;
		Node*next;
		Node(){
			next=NULL;
		}
		
};

class List{
	public:
		Node *rear;
		Node *front;
		int numItems;
		List(){
		
			numItems=0;
			front=rear=NULL;
		}
		void Enque(int val){
			numItems++;
			Node *newNode=new Node();
			cout<<"h";
		    newNode->value=val;
		    cout<<newNode->value;
			if(front==NULL)
			{
			front=rear=newNode;
			}
			else{
				rear->next=newNode;
				rear=newNode;
			}
		}
		bool Deque(int &num){
		
			Node*temp;
			if(isEmpty()){
			cout<<"The list is empty\n";
		    return false;
		   }
			else{
		        num=front->value;
				temp=front->next;
				delete front;
				front=temp;
				numItems--;
				return true;
			}
		}
	
		
	int count(Node *l1){
		 if(l1->next)
		   return 1+count(l1->next);
		   return 1;
}
			bool isEmpty()
		{	
		 if (numItems)
		 	return false;
		else
			return true;
			}
		void print(Node *n){
			if(n){
			
			cout<<n->value<<"   ";
			cout<<endl;
		}
			if(n->next)
			print(n->next);
		}
};

int main(){
	List list;
   list.Enque(5);
   list.Enque(3);
   
   list.print(list.front);
}

