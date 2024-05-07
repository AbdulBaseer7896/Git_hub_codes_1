#include<iostream>
using namespace std;


        int visit[7] = {0,0,0,0,0,0,0};
        int a[7][7] =
        {
            {0,1,1,1,0,0,0},
            {1,0,1,0,0,0,0},
            {1,1,0,1,1,0,0},
            {1,0,1,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0}, 
            {0,0,0,0,1,0,0} 
        };

// void DFS(int i) 
// {
//     cout<<i;
//     visit[i] = 1; 
//     for(int j = 0; j<7; j++)
//     {
//         if(a[i][j]  == 1 && !visit[j])
//         {
//             DFS(j);
//         }

//     }
// }
void DFS(int i)
{
    cout<<i;
    visit[i] = 1;
    for(int j=0; j<7; j++)
    {
        if(a[i][j] == 1 && !visit[j])
        {
            DFS(j);
        }
    }
}
int main()
{

cout<<"hello";
DFS(6);
return 0;
}

