#include<iostream>
using namespace std;



void bubbles_sort_using_recursion(int arr[],int n)
{

    if(n==1)
    {
        return;
    }

    int count =0;

    for(int i=0; i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            count++;

        }
    }

    if(count==0)
    {
        return;
    }

    bubbles_sort_using_recursion(arr, n-1);
}
void display_function(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{

int arr[] = {7,8,6,9,3,4,5,2,1};
int n = size(arr);

bubbles_sort_using_recursion(arr  , n);
display_function(arr , n);



return 0;
}