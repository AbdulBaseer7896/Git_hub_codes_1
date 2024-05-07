#include <iostream>
#include <queue>
using namespace std;
int adj[4][4];

class graph
{
public:
    queue<int> q;
    int vert;
    int datas;
    // string name;

public:
    graph()
    {
        this->vert = 0;
        this->datas = 0;
        // this->name = NULL;
    }

    graph(int v)
    {
        this->vert = v;
        this->datas = 0;
        // this->name = NULL;

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = -1;
            }
        }
    }

    void data(int x, int y, int weight)
    {
        adj[x][y] = weight;
        // adj[y][x] = weight;
    }

    void display()
    {
        for (int i = 0; i < this->vert; i++)
        {
            cout << i << " = ";
            for (int j = 0; j < vert; j++)
            {
                if (adj[i][j] != -1)
                {
                    // cout<<"helo";
                    cout << adj[i][j] << " -> ";
                }
            }
            cout << endl;
        }
    }


    int minweigh(int weight[], bool visited[])
    {
        int v = 4; int min = 9999; int minIndex = -1;
        for (int i = 0; i<v; i++)
        {
            if (visited[i] == false && weight[i] < min)
            {
                min = weight[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    void print_MST(int parent[] , int adj[4][4])
    {
        int mincost = 0;
        cout<<"Edge \t Weith"<<endl;
        for(int i=1; i<vert; i++)
        {
            cout<<parent[i]<<" - "<<"\t"<<adj[i][parent[i]]<<endl;
            mincost+=adj[i][parent[i]];
        }
        cout<<"Total adj is"<<mincost;
    }

    void prim(int start)
    {
        bool visisted[4] = {0, 0, 0, 0};
        int parent[4] = {-1, -1, -1, -1};
        int weight[4];  int len = 4;  int min = 99999; weight[0] = 0;
        for (int i = 0; i < vert-1; i++)
        {
            int u = minweigh(weight, visisted);
            visisted[u] = 1;
            for (int j = 0; j < vert; i++)
            {
                if (adj[u][i] != -1 && !visisted[i] && adj[u][i] < weight[i])
                {
                    parent[i] = u;
                    weight[i] = adj[u][i];
                }
            }
        }
        print_MST(parent, adj);
    }
};

int main()
{

    int vert = 4;

    graph g(vert);

    // g.display();
    g.data(0, 1, 2);
    g.data(0, 2, 8);
    g.data(1, 2, 11);
    g.data(1, 3, 9);
    g.data(1, 0, 2);
    g.data(2, 0, 8);
    g.data(2, 1, 11);
    g.data(2, 3, 12);
    g.data(3, 1, 9);
    g.data(3, 2, 12);

    g.prim(0);
    // g.display();

    return 0;
}