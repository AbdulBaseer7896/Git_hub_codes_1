#include<iostream>
using namespace std;

class max_heap
{
    public:
    int * arr;
    int size;
    int capaciy;

    max_heap(int c)
    {
        arr = new int[c];
        size = -1;
        capaciy = c;
    }

    int left_child(int i)
    {
        int num;
        num = (2*i + 1);
        if (num >=capaciy)
        {
            cout<<"left child is not exist";
        }
        cout <<"The left child is = "<<arr[num];

        return num;
    }


    int right_child(int i)
    {
        int num;
        num = (2*i +2);
        cout<<"The right child is = "<<arr[num];
        
        return num;
    }


    int parent_Of_node(int i)
    {
        int num;
        num = (i-1)/2;

        // cout<<"the parent of node is = "<<arr[num]<<endl;

        return num;
    }

    void Inserting_in_max_heap(int val)
    {

        if(size == capaciy)
        {
            cout<<"The array is full"<<endl;


            
            return;
        }
        size++;
        arr[size] = val;
        int temp;
        
        for(int i =size; i!=0 && arr[parent_Of_node(i)] > arr[i];)
        {
                temp = arr[i];
                arr[i] = arr[parent_Of_node(i)];
                arr[parent_Of_node(i)] = temp;

                i = parent_Of_node(i);
        }

    }

    void display_heap()
    {
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" -> ";
        }
    }
};
int main()
{

max_heap min(9);

min.Inserting_in_max_heap(45);
min.Inserting_in_max_heap(10);
min.Inserting_in_max_heap(20);
min.Inserting_in_max_heap(15);
min.Inserting_in_max_heap(8);
min.Inserting_in_max_heap(50);
min.Inserting_in_max_heap(100);
min.Inserting_in_max_heap(235);
min.Inserting_in_max_heap(45);
min.display_heap();
cout<<endl;

min.left_child(1);

return 0;
}