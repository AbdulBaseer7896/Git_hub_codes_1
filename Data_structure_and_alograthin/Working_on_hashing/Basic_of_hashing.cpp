#include<iostream>
#include<math.h>
using namespace std;



class hash_tabe
{
    int  arr[][];
    int size;

    public:
    hash_tabe(int s)
    {
        arr = new int[s][2];
        this->size = s;
    }

    void insert()
    {
        int num;
        cout<<"Enter the value in the arr :\n";
        for(int i=0; i<size; i++)
        {
            cin>>num;
            if(num >= 0)
            {
                arr[i][0] = num;
            }   

            else{
                arr[i][1] = num;
            }
        }
    }

    void search_using_hashing(int num)
    {
        if(hash[num] == )
    }


};
int main()
{




return 0;
}