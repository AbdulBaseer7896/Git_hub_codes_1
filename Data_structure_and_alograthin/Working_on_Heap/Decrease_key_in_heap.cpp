#include<iostream>
using namespace std;

class heap
{
    int * arr;
    int size;
    int capacity;
    public:
    heap(int c)
    {
        this->arr = new int(c);
        this->size = 0;
        this->capacity = c;
    }


    void in_val()
    {
        cout<<"enter val"<<endl;
        for(int i=0; i<6; i++)
        {
            cin>>arr[i];
            size++;
        }
    }
    int left_child(int i)
    {
        int num;
        num = (2*i + 1);
        // cout <<"The left child is = "<<arr[num];

        return num;
    }


    int right_child(int i)
    {
        int num;
        num = (2*i +2);
        // cout<<"The right child is = "<<arr[num];
        
        return num;
    }


    int parent_Of_node(int i)
    {
        int num;
        num = (i-1)/2;

        // cout<<"the parent of node is = "<<arr[num]<<endl;

        return num;
    }


    void heapify(int i)
    {
        int left = left_child(i);
        int right = right_child(i);
        int smallest = i;

        if(left < size && arr[left] < arr[smallest])
        {
            smallest = left;
        }

        if(right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        
        if(smallest != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;

            heapify(smallest);
        }
    }

    void display()
    {
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" -> ";
        }
        cout<<endl;
    }

    void decrease_key_in_heap(int index , int val)
    {
        arr[index] =val;

        while( index != 0 && arr[index] < arr[parent_Of_node(index)])
        {
            int temp = arr[index];
            arr[index] = arr[parent_Of_node(index)];
            arr[parent_Of_node(index)] = temp;
            index = parent_Of_node(index);
        }

    }


};
int main()
{


heap h(6);
h.in_val();
h.display();
h.decrease_key_in_heap(3 , 5);
h.display(); 


return 0;
}