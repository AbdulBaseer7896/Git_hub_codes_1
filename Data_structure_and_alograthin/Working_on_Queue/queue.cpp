#include <iostream>
using namespace std;

class queue
{
public:
    int data;
    int size;
    int first;
    int back;
    int array[];

    queue()
    {
        this->data = 0;
        this->first = 0;
        this->back = 0;
        this->size = 10;
        this->array[10];
    }

    void enqueue(int val)
    {
        if (isfull() == 99) 
        {
            cout << "The queue is FuLL" << endl;
            return;
        }
        else
        {
            array[back] = val;
            back ++;
        }
    }

    void prints()
    {

        for (int i = 0; i < size - 1; i++)
        {
            cout << array[i] << endl;
        }
    }

    int isempty()
    {
        if (back == first)
        {
            cout << "The queue is Empty" << endl;
            return 99;
        }
        return 0;
    }

    int isfull()
    {

        if (back == size - 1)
        {
            cout << "The queue is full" << endl;
        return 99;
        }
        return 0;
    }


    int deques()
    {
        int val;
        if(isempty() == 99)
        {
            return -1;
        }
        else
        {
            val = array[first];
            first++;
        }
        return val;
    }

    
};
int main()
{

    queue q;

    // q.isempty();
    q.enqueue(34);
    q.enqueue(564);
    q.enqueue(784);
    q.enqueue(898);
    q.enqueue(898);
    q.enqueue(898);
    q.enqueue(898);
    q.enqueue(898);
    q.enqueue(898);
    q.enqueue(7778);
    q.enqueue(9998);
    q.deques();
    // q.isfull();
    q.prints();

    return 0;
}