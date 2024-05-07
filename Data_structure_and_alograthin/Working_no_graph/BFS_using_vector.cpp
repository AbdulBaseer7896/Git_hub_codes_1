#include<iostream>
using namespace std;



class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


class quee
{
    node * front;
    node * real;

    public:

    quee()
    {
        this->front = NULL;
        this->real = NULL;
    }

    void display()
    {
        node * temp = this->front;
        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
    }

    
    void enquee(int val)
    {
        node * newnode = new node(val);

        if(newnode == NULL)
        {
            cout<<"The quee is over flow"<<endl;
            return;
        }

        if(this->front == NULL)
        {
            this->front = this->real = newnode;
        }
        else
        {
            real->next = newnode;
            real = newnode;
        }
    }

    int dequee()
    {
        node * ptr = this->front;
        int num;
        if(ptr == NULL)
        {
            cout<<"The quee is empty"<<endl;
            return 0;
        }
        else
        {
            // cout<<"The deleating element = "<<ptr->data<<endl;
            num = ptr->data;
            this->front = front->next;
            free(ptr);   
        }
        return num;
    }

    int IsEmpty()
    {
        if(this->front == this->real)
        {
            return 1;
        }
        return 0;
    }

 
};


class graph
{
    public:
    int vertes;
    int ** adj;

    graph()
    {
        this->vertes = 5;

        this->adj[vertes][vertes];

    }

void addEdg(int u, int v)
{
    this->adj[u][v] = 1;
    this->adj[v][u] = 1;
}

void printGraph(int v)
{
    for(int i=0; i<v; i++)
    {
        cout<<"hello";
        for(int j=0; j<v; j++)
        {
            cout<<adj[i][j];
        }
        cout<<endl;
    }
}


void BFS_using_vector(int v , int sorce)
{
    bool visited[v];

    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }


    quee q;


    q.enquee(sorce);
    visited[sorce] = true;

    while(!q.IsEmpty())
    {
        int u = q.dequee();
        // q.dequee();
        cout<<u<<" ->";

        for(int i=0; i<v; i++)
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                cout<<i;
                q.enquee(i);
            }
        }

    }

}

};
int main()
{

graph g;
int vertes = 5;
     
    g.addEdg(0, 1);
    g.addEdg(0, 2);
    g.addEdg(1, 3);
    g.addEdg(1, 2);
    g.addEdg(2, 3);
    g.addEdg(2, 4);
    g.addEdg(3, 4);

cout<<"Hello"<<endl;
    // BFS_using_vector(vertes , 0);



    g.printGraph(vertes);
    cout<<endl; 

    
return 0;
}