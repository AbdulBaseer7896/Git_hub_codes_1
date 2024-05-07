#include <iostream>
#include<queue>
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

    void data(int x, int y)
    {
        adj[x][y] = 1;
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



bool visisted[4] = {0,0,0,0};

    void DFS(int start)
    {
        cout<<start<<" -> ";

        visisted[start] = 1;
        for(int i=0; i<vert; i++)
        {
            if(adj[start][i] == 1 && visisted[i]== 0)
            {
                DFS(i);
            }
        }
    }

};

int main()
{

    int vert = 4;

    graph g(vert);

    // g.display();
    g.data(0, 1);
    g.data(0, 2);
    g.data(1, 2);
    g.data(1, 3);
    g.data(1, 0);
    g.data(2, 0);
    g.data(2, 1);
    g.data(2, 3);
    g.data(3, 1);
    g.data(3, 2);

    g.DFS(0);
    // g.display();

    return 0;
}