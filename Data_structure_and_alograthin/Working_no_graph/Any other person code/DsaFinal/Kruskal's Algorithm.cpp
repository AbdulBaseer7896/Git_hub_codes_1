#include<iostream>
using namespace std;
struct QNode
{
	char vertix;
	int weight;
	QNode *next;
};
class Queue
{
	private:
	QNode *front;
	QNode *rear;
	int item;
	public:
	Queue()
	{
		front=0;
		rear=0;
		item=0;
	}
	void enqueue(char num)
	{
		QNode *newnode=new QNode;
		newnode->vertix=num;
		newnode->next=0;
		if(isempty())
		{
			front=newnode;
			rear=newnode;
		}
		else
		{
			rear->next=newnode;
			rear=newnode;
		}
		item++;
	}
	bool dequeue(string &num)
	{
		QNode *temp;
		if(isempty())
		{
			cout<<"Queue is Empty: "<<endl;
			return false;
		}
		else
		{
			num=front->vertix;
			temp=front->next;
			delete front;
			front=temp;
			item--;
		}
		return true;
	}
	bool isempty()
	{
		if(item)
		return false;
		else
		return true;
	}
	void display()
	{
		QNode *cnode=front;
		while(cnode!=0)
		{
			cout<<cnode->vertix<<" ";
			cnode=cnode->next;
		}
	}
	bool search(char s)
	{
		QNode *cnode=front;
		while(cnode!=0)
		{
			if(cnode->vertix==s)
			return true;
			cnode=cnode->next;
		} 
		return false;
	}
};
class PQueue
{
	int front,size,item;
	QNode *list;
	public:
	PQueue(int s)
	{
		list=new QNode[s];
		size=s;
		item=0;
		front=-1;
	}
	bool isEmpty()
	{
		if (item)
		return false;
		else
		return true;
	}
	bool isFull()
	{	
		if(item<size)
		return false;
		else	
		return true;
	}
	void enqueue(QNode *node)
	{
		if (isFull())
		cout << "The queue is full "<<endl;
		else
		{
				front++;
				list[front]=*node;
				item++;
		}
	}
	void sort()
	{
		QNode temp;
		bool check=false;
		int i,j=0;
		while(true)
		{
			i=front;
			j=0;
			check=false;
		for(;i>0;i--)
		{
			if(i%2==0)
			{
				j=i-1;
				j=j/2;
			}
			else
			j=i/2;
			if(list[i].next->weight<list[j].next->weight)
			{
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
				check=true;
			}
		}
			if(check==false)
			break;				
		}
	}
	bool dequeue(QNode &n)
	{
		if(isEmpty())
		return false;
		n=list[0];
		list[0]=list[front];
		item--;
		front--;
		return true;		
	}
	void display()
	{
		if(isEmpty())
		cout<<"Queue Empty"<<endl;
		for(int i=0;i<item;i++)
		{
			cout<<list[i].vertix<<list[i].next->vertix<<" ";
			cout<<list[i].next->weight;
			cout<<endl;
		}
	}
	
};
class Node
{
	public:
	QNode data;
	Node *next;
};
class List
{
	private:
	Node *head;
	public:
	List()
	{
		head=0;
	}
	Node* InsertNode(int index,QNode x) 
	{
	if(index<0) 
	return NULL;	
	int currIndex=1;
	Node *currNode=head;
	while(currNode&&index>currIndex) 
	{
		currNode=currNode->next;
		currIndex++;
	}
	if (index>0&&currNode==NULL)
	return NULL;
	Node *newNode =new	Node;
	newNode->data=x;	
	if (index == 0)
	{
		newNode->next=head;
		head=newNode;
	}
	else 
	{
		newNode->next=currNode->next;
		currNode->next=newNode;
	}
	return newNode;
}
void DisplayList()
{
   	int num=0;
	Node *currNode=head;
  	while(currNode!=NULL)
	{
		cout<<currNode->data.vertix<<currNode->data.next->vertix<<" "<<currNode->data.next->weight<<endl;
		currNode=currNode->next;
		num++;
   	}
}
bool search(char x)
{
	Node *cnode=head;
	while(cnode!=0)
	{
		if(cnode->data.next->vertix==x)
		return true;
		cnode=cnode->next;
	}
	return false;
}
};
class Graph
{
	private:
	int size;
	int total_vertix;
	public:
	QNode *list;
	Graph(int s)
	{
		size=s;
		list=new QNode[size];
		total_vertix=-1;
		for(int i=0;i<size;i++)
		list[i].vertix=0;
	}
	void addedge(char from,char to,int w)
	{
		int i=0;
		bool flag=true;
		for(int i=0;i<size;i++)
		{
			if(list[i].vertix==from)
			{
				QNode *newnode=new QNode;
				newnode->vertix=to;
				newnode->next=0;
				QNode *cnode=list[i].next;
				while(cnode->next!=0)
				{
					cnode=cnode->next;	
				}
				cnode->next=newnode;
				newnode->weight=w;
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
		QNode *newnode1=new QNode;
		newnode1->vertix=from;
		QNode *newnode2=new QNode;
		newnode2->vertix=to;
		newnode1->next=newnode2;
		newnode2->weight=w;
		newnode2->next=0;
		total_vertix++;
		list[total_vertix]=*newnode1;
		}
	}
	void bfs()
 	{
 		Queue q;
 		QNode *cnode;
 		for(int i=0;i<size;i++)
 		{
 			cnode=&list[i];
 			while(cnode!=0)
 			{
 				if(!q.search(cnode->vertix))
 				{
 				q.enqueue(cnode->vertix);
				}
 				cnode=cnode->next;
			}
		}
		q.display();
 			
	}
	void display()
	{
		cout<<list[8].next->weight;
	}
};
int size_cal(Graph g,int s)
{
	QNode *cnode;
	int size=0;
	for(int i=0;i<s;i++)
	{
		cnode=&g.list[i];
		while(cnode->next!=0)
		{
			size++;
			cnode=cnode->next;
		}
	}
	return size;
}
void kruskal_algorithm(Graph g,PQueue pq)
{
	QNode *cnode,node;
	List l;
	int i=0;
	while(true)
	{
		pq.dequeue(node);
		pq.sort();
		if(pq.isEmpty())
		break;
		if(!l.search(node.next->vertix))
		{
		l.InsertNode(i,node);
		i++;
		}	
	}
	l.DisplayList();
		
}
void divide_edges(Graph g,int s,int size)
{
	QNode *cnode;
	PQueue q(s);
	for(int i=0;i<size;i++)
	{
		cnode=&g.list[i];
		q.enqueue(cnode);
		cnode=cnode->next;
		while(cnode->next!=0)
		{
			cnode=cnode->next;
			QNode *newnode=&g.list[i];
			newnode->next=cnode;
			q.enqueue(newnode);	
		}
	}
	q.sort();
	kruskal_algorithm(g,q);
}
int main()
{
	Graph g(9);
	g.addedge('A','B',4);
	g.addedge('A','D',1);
	g.addedge('B','D',4);
	g.addedge('B','C',4);
	g.addedge('B','J',10);
	g.addedge('C','E',2);
	g.addedge('C','F',1);
	g.addedge('D','H',5);
	g.addedge('D','J',6);
	g.addedge('E','G',2);
	g.addedge('F','G',3);
	g.addedge('F','I',5);
	g.addedge('G','I',3);
	g.addedge('G','J',4);
	g.addedge('J','H',2);
	g.addedge('I','J',3);
	int size=size_cal(g,9);
	divide_edges(g,size,9);
}
