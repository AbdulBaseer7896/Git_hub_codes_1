#include<iostream>
using namespace std;
int main()
{
	int n,end;
	cout << " Enter the total number to terms you calculate = ";
	cin>>end;

    int total;
    cout<<"The odd number are : ";
	for(int i=1; i<=end; i++)
	{
		if (i%2!=0)
		{
			cout<<i<<" ";
            total = total +i;
		}
	} 
    cout<<endl<<"The Sum of odd Natural Number  up to "<<end<<" terms : "<<total;
	return 0;
}