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



 
// int main(){
//     // Initializing Queue (Array Implementation)
//     quee q;
    
//     // BFS Implementation 
//     int node;
//     int i = 1;
//     int visited[7] = {0,0,0,0,0,0,0};
//     int a [7][7] = {
//         {0,1,1,1,0,0,0},
//         {1,0,1,0,0,0,0},
//         {1,1,0,1,1,0,0},
//         {1,0,1,0,1,0,0},
//         {0,0,1,1,0,1,1},
//         {0,0,0,0,1,0,0}, 
//         {0,0,0,0,1,0,0} 
//     };
//     printf("%d", i);
//     visited[i] = 1;
//     q.enquee(i); // Enqueue i for exploration
//     while (!q.IsEmpty())
//     {
//         cout<<"hello";
//         int node = q.dequee();
//         for (int j = 0; j < 7; j++)
//         {
//             if(a[node][j] ==1 && visited[j] == 0){
//                 printf("%d", j);
//                 visited[j] = 1;
//                 q.enquee(j);
//             }
//         }
//     }
//     return 0;
// }


int main()
{


    int i=1; 
    int num = 7;
    int visited[num];
    int node;
    int adj[num][num] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };;
    for(int i=0; i<num; i++)
    {
        visited[i] = 0;
    }

    quee q;
    cout<<i<<" -> ";
    q.enquee(i);
    visited[i] = 1;
    while(!q.IsEmpty())
    {
        node = q.dequee();
        for(int j=0; j<num; j++)
        {
            if(adj[node][j] == 1 && visited[j]== 0)
            {
                cout<<node<<" -> ";
                visited[j] = 1;
                q.enquee(j);
            }
        }
    }

}