#include<iostream>
#include<vector>
using namespace std;

void addEdg(vector<int> adj[] , int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for(int i=0; i<v; i++) 
    {
        cout<<i<<" = ";
        for(auto x: adj[i])
        {
            cout<<x<<" ->";
        }
        cout<<endl;
    }
}
int main()
{

int vertes = 10;
    vector<int> adj[vertes];

    addEdg(adj, 0, 1);
    addEdg(adj, 0, 2);
    addEdg(adj, 1, 3);
    addEdg(adj, 1, 2);
    addEdg(adj, 2, 3);
    addEdg(adj, 2, 4);
    addEdg(adj, 3, 4);


    printGraph(adj ,vertes);
    
return 0;
}