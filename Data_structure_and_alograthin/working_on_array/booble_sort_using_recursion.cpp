#include<iostream>
using namespace std;

void booble_sort(int arr[], int n)
{

    if(n==1)
    {
        return;
    }
    int count=0;

    for(int i =0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            count++;
        }
    }
    if(count == 0)
    {
        return;
    }

    booble_sort(arr,n-1);
}


int searchElement(int arr[], int size, int x) {
     
    size--;
     
    // Base case (Element not present in the array)
    if (size < 0) {
        return -1;
    }
    // Base case (Element found, return its position)
    if (arr[size] == x) {
        return size;
    }
 
    // Recursive case
    return searchElement(arr, size, x);
 
}
int main()
{
int arrar[] = {5,3,6,7,8,3,42, 1, 2};
int size = 9;

int a = searchElement(arrar , size-1, 8);
cout<<"This is  = "<<a;

booble_sort(arrar , size);
for (int i = 0; i < size; i++)
{
    cout<<arrar[i]<<" ";
}

return 0;
}