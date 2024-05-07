#include <iostream>
using namespace std;
int cost[6][6];
int n = 6;
int total;

void data(int x, int y, int weight)
{
    cost[x][y] = weight;
    // cost[y][x] = 1;
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " = ";
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] != 0)
            {
                // cout<<"helo";
                cout << cost[i][j] << " -> ";
            }
        }
        cout << endl;
    }
}

int get_nearest_Naber(int dist[], bool visited[])
{
    int minvalue = 9999; int min_node = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < minvalue)
        {
            minvalue = dist[i];
            min_node = i;
        }
    }
    return min_node;
}
int display_function_of_Dijkstra(int dist[], int parent[])
{
     int sum;
    for (int i = 0; i < n; i++)
    {
        int temp = parent[i];
        cout << i << "  < -";
        while (temp != -1)
        {
            cout << temp << " <- ";
            temp = parent[temp];
        }
        cout << "\n :::Distance = " << dist[i];
        sum += dist[i];
    }
    return sum;
}
void Dijkstra_Algo(int start)
{
    int parent[n]; int dist[n]; bool visited[n] = {0};
    fill(dist, dist + n, INT_MAX);
    dist[start] = 0; parent[start] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int nearest = get_nearest_Naber(dist, visited);
        visited[nearest] = 1;
        cout << " MIN = " << nearest << endl;
        for (int adj_node = 0; adj_node < n; adj_node++)
        {
            if (!visited[adj_node] && dist[adj_node] > dist[nearest] + cost[nearest][adj_node] && cost[nearest][adj_node] != 9999)
            {
                parent[adj_node] = nearest;
                dist[adj_node] = dist[nearest] + cost[nearest][adj_node];
            }
        }
    }
    total += display_function_of_Dijkstra(dist, parent);
}


int main()
{

    display();
    data(0, 2, 4);
    data(1, 2, 8);
    data(2, 0, 4);
    data(2, 1, 8);
    data(2, 4, 2);
    data(2, 5, 4);
    data(3, 4, 9);
    data(4, 2, 2);
    data(4, 3, 9);
    data(5, 2, 11);

    Dijkstra_Algo(0);

    // g.display_function_of_Dijkstra();
    // g.display();
cout<<"\n\n Total = "<<total;
    return 0;
}
