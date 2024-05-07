#include <iostream>
#include<queue>
using namespace std;
int adj[4][4];

class graph
{
public:
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


    void BFS(int start, int vert)
    {
        queue<int> q;

        bool visited[vert] = {0,0,0,0};

        cout<<start<<" -> ";
        visited[start] = 1;
        q.push(start);
 

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

                for(int j=0; j<vert; j++)
                {
                    if(adj[node][j] == 1 && visited[j]== 0)
                    {
                        cout<<j<<" -> ";
                        visited[j] = 1;
                        q.push(j);
                    }
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

    g.BFS(3, 4);
    // g.display();

    return 0;
}