#include<iostream>
using namespace std;


class circular_queue
{
    public:
    int data;
    int first;
    int back;
    int array[10];
    int size;


    circular_queue()
    {
        this->data = 0;
        this->back = -1;
        this->first = -1;
        this->size = 10;
        this->array[this->size];
    }

    void inque_in_circular_que(int val)
    {
        if((this->back + 1)%this->size == first)
        {
            cout<<"quee is full"<<endl;
            return;
        }
        cout<<"The element is Enter in enque = "<<val<<endl;
        this->back  = (this->back + 1) % this->size;
        array[this->back]= val;
    }

    void display_quee()
    {
        for(int i=0; i<this->size; i++)
        {
            cout<<"The value at "<<i+1<<" index = "<<this->array[i]<<endl;
        }
        cout<<this->first;
    }
};
int main()
{

circular_queue q;

q.inque_in_circular_que(1);
q.inque_in_circular_que(2);
q.inque_in_circular_que(3);
q.inque_in_circular_que(4);
q.inque_in_circular_que(5);
q.inque_in_circular_que(6);
q.inque_in_circular_que(7);
q.inque_in_circular_que(8);
q.inque_in_circular_que(9);
q.inque_in_circular_que(10);
q.inque_in_circular_que(11);
q.inque_in_circular_que(12);
q.inque_in_circular_que(13);

q.display_quee();


return 0;
}