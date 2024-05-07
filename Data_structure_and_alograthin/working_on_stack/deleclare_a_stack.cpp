#include<iostream>
using namespace std;

class stack
{
    public:
    int size;
    int top;
    int *arr;

stack()
{
    size = 5;
    top = -1;
    arr = new int;
}

void push(int num)
{
    if(top == size-1)
    {
        cout<<"you stack is already full"<<endl;
    }
    else
    {

        if(top == size-1)
        {
            cout<<"No need to push more value you stack is full"<<endl;
        }
        top++;
        arr[top] = num;
    }
}


void pop()
{
    if(top== -1)
    {
        cout<<"you stack is empty"<<endl;
    }
    else{
    cout<<"This is number "<<top <<" = "<<arr[top]<<endl;
    top--;
    }

}

void print_stack()
{
    if(top == -1)
    {
        cout<<"You stack is empty"<<endl;
    }
    else{
        int num = top;
        for(int i=0; i<num+1; i++)
        {
            cout<<arr[top]<<endl;
            top--;
        }
    }
}

int peek(int i)
{
    if(top-i+1 <-1 && top-i+1>=top-1)
    {
        cout<<"This unvalid index"<<endl;
    }
    else
        return arr[top -i +1];
}

void top_bottom_in_stack()
{
    if(top == -1)
    {
        cout<<"The stack is full"<<endl;
    }
    else
    {
        cout<<"This is the top most element of stack    = "<<arr[top]<<endl;
        cout<<"This is the bottom most element of stack = "<<arr[0]<<endl;
    }
}

};

int main()
{

stack s;

s.pop();
s.push(23);
s.push(45);
s.push(98);
s.push(56);
s.push(34);
cout<<"The peek of the function is = "<<s.peek(4)<<endl;
s.top_bottom_in_stack();
s.print_stack();
// s.pop();
// s.pop();
// s.pop();
// s.pop();
// s.pop();
// s.pop();
cout<<"This is peek value"<<endl;

cout<<s.peek(-1);
return 0;
}
