#include<iostream>
using namespace std;


void tree(int array[], int size)
{
    int i=0;
    while(i<size)
    {
        if(i==0)
        {
        cout<<"Enter is root vlaue = ";
        cin>>array[i];
        i++;
        }
        else{
            if(i%2 == 0){
            cout<<"Enter the value of node "<<i<<" right child = ";
            cin>>array[i];
            i++;
            }
            else if(i%2 != 0)
            {
                cout<<"Enter the value of node "<<i<<" right child = ";
                cin>>array[i];
                i++;
            }
        }
        
    }
}

void display_tree(int array[] , int size)
{

     for(int i=0; i<size; i++)
     {
        cout<<array[i]<<" --> ";
     }

}
int main()
{

int size;
cout<<"Enter the size of tree in term of nodes = ";
cin>>size;
int array[size];

tree(array , size);
display_tree(array , size);

return 0;
}