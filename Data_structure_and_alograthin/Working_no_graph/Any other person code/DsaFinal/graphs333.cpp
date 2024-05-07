#include<iostream>
using namespace std;
class Node{
	public:
	int value;
	int cost;
	Node *next;
	Node(){
		next=NULL;
		cost=value=0;
	}
	Node(int v=0,int c=0,Node *n=NULL){
		value=v;
		cost=c;
		next=n;
	}
};

class Graph{
		public:
	Node **adjList;
	int N;

	Graph(int v){
		N=v;
		adjList=new Node*[N];
		for(int i=0;i<N;i++)
		adjList[i]=NULL;
	}
	void addEdge(int from,int to,int cost){
		adjList[from]=new Node(to,cost,adjList[from]);
		adjList[to]=new Node(from,cost,adjList[to]);
	}
	void print(){
		for(int  i=0;i<N;i++){
			cout<<i<<" : ";
			Node *currNode=adjList[i];
			while(currNode){
				cout<<" -> "<<currNode->value;
				currNode=currNode->next;
			}
			cout<<"\n";
		}
	}
};
bool *visited;
bool found;
void Find(Graph g,int from,int to){
	if(from==to)
	{
	found=true;
	return;}
	Node *currNode=g.adjList[from];
	visited[from]=true;
	while(currNode)
	{
		if(!visited[currNode->value])
		 Find(g,currNode->value,to);
		currNode=currNode->next;
	}
}
void BFS(Graph g,int from,int to){
	visited=new bool [g.N];
	for(int i=0;i<g.N;i++)
	visited[i]=false;
    found=false;
    Find(g,from,to);
	if(found)
	cout<<" found :  ";
	else
	cout<<"not found";
}
int main(){
	Graph g(4);
	g.addEdge(1,2,5);
	g.addEdge(0,3,1);
	g.addEdge(2,3,2);
	g.addEdge(3,1,2);
	g.print();
   BFS(g,0,8);
}
