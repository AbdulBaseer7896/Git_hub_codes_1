#include<iostream>
using namespace std;
struct Node{
	char data;
	Node *next;
	Node *prev;
	bool encountered;
	Node(){
		encountered=false;
	}
};
class List{
	public:
		Node*head;
		Node*tail;
		List(){
			head=NULL;
			tail=NULL;
		}
		Node* insertNode(int index,char x){
		if(index<0)
		return NULL;
		int currIndex=1;
		Node* currNode=head;
		while(currNode && index>currIndex)
		{
			currNode=currNode->next;
			currIndex++;
		}
		if(index>0 && currNode == NULL)
		return NULL;
		Node*newNode=new Node;
	   if(index==0){
	   	newNode->next=head;
	   	head=newNode;
	   	head->data=x;
		head->prev=NULL;
		tail=head;
	   }
 else{
    newNode->data = x;

    newNode->next = currNode->next;
    currNode->next = newNode;
    newNode->prev = currNode;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
		return newNode;
	}}

		void displayList(){
			Node *currNode=head;
			while(currNode){
				cout<<currNode->data<<" ";
				currNode=currNode->next;
			    
			}
			cout<<"\n";
		}
			int nodeCount(){
			Node *currNode=head;
			int count=0;
			while(currNode){
				currNode=currNode->next;
				count++;
			}
			return count;
		}
		void frequencyCount(Node *n)
		{
			    int count=0;
			    char key=n->data;
			    Node*currNode=n;
				while(currNode && currNode->encountered==false){
				if(key==currNode->data)
				{
				count++;
				currNode->encountered=true;
			}
				currNode=currNode->next;
			}
			if(count>0)
			cout<<"Frequency of "<<key<<" is : "<<count<<" \n";
			if(n->next)
            frequencyCount(n->next);
		}
};
int main(){
	List list;
	char x;
	int index=0;
	cout<<"Enter char : ";
	cin>>x;
	while(x!='0'){
		cout<<"Enter char or 0 to exit: ";
		list.insertNode(index++,x);
			cin>>x;
	}
	        cout<<"\nDisplaying list \n";
	         list.displayList();
	         int n=list.nodeCount();
	         list.frequencyCount(list.head);
}
