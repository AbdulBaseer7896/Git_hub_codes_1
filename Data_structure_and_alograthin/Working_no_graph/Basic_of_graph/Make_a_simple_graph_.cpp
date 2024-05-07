#include <iostream>
using namespace std;
int adj[4][4];

class graph
{
public:
    int vert;
    int datas;

public:
    graph()
    {
        this->vert = 0;
        // this->adj = 0;
        this->datas = 0;
    }

    graph(int v)
    {
        this->vert = v;
        // this->adj = 0;
        this->datas = 0;

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void data(int x, int y, int weight)
    {
        adj[x][y] = weight;
        // adj[y][x] = 1;
    }

    void display()
    {
        for (int i = 0; i < this->vert; i++)
        {
            cout << i << " = ";
            for (int j = 0; j < vert; j++)
            {
                if (adj[i][j] != 0)
                {
                    // cout<<"helo";
                    cout << adj[i][j]  << " -> ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{

    int vert = 4;

    graph g(vert);

    g.display();
    g.data(0, 2, 4);
    g.data(1, 2, 8);
    g.data(2, 0, 4);
    g.data(2, 1, 8);
    g.data(2, 4, 2);
    g.data(2, 5, 4);
    g.data(3, 4, 9);
    g.data(4, 2, 2);
    g.data(4, 3, 9);
    g.data(5, 2, 11);
    // g.data(0, 1, 11);
    // g.data(0, 2, 11);
    // g.data(1, 0, 11);
    // g.data(0, 2, 11);
    // g.data(2, 0, 11);
    // g.data(2, 1, 11);
    // g.data(2, 3, 11);
    // g.data(3, 2, 11);

    g.display();

    return 0;
}