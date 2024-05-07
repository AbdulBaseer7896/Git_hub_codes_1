#include<iostream>
using namespace std;

class heap
{
    int * arr;
    int size;
    int capacty;

    public:

    heap(int c)
    {
        arr = new int[c];
        size = 0;
        capacty = c;
    }

    void in_val()
    {
        cout<<"enter val"<<endl;
        for(int i=0; i<10; i++)
        {
            cin>>arr[i];
            size++;
        }

        Heapify(0);
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


    void Heapify(int i)
    {
        int temp;
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
            temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;

            Heapify(smallest);
        }
    }


    void display()
    {
        if(size == 0)
        {
            cout<<"The heap is empty "<<endl;
        }

        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" -> ";
        }
        cout<<endl;
    }

    void Extract_min_vlaue_in_heap()
    {
        if(size == 0)
        {
            cout<<"The heap is emply "<<endl;
            return;
        }
        cout<<"The min value is extract for heap = "<<arr[0];
        int temp = arr[0];
        arr[0] = arr[size-1];
        size--;
        Heapify(0);
    }


};


int main()
{

heap h(10);
h.in_val();
cout<<endl;
h.Extract_min_vlaue_in_heap();
 
cout<<endl;
h.display();


return 0;
}