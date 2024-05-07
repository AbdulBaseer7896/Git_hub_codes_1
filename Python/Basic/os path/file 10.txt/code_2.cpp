#include<iostream>
using namespace std;


int main()
{

int total_marks_of_student[5];
string name[5];
int english[5];
int urdu[5];
int comp[5];

int marks[5];


for(int i=0; i<5; i++)
{
    cout<<"\n\nEnter the Name of a student = ";
    cin>>name[i];
        cout<<"Enter the marks of English = ";
        cin>>english[i];
        cout<<"Enter the marks of Urdu = ";
        cin>>urdu[i];
        cout<<"Enter the marks of Comp = ";
        cin>>comp[i];
}

for(int i=0; i<5; i++)
{
    total_marks_of_student[i] = english[i] + urdu[i] + comp[i];
}

for(int i=0; i<5; i++)
{
    cout<<"The name of a student = "<<name[i];
    cout<<"\nThe total marks of a student = "<<total_marks_of_student[i]<<endl<<endl<<endl;
    
}

// cout<<"Enter the marks of a student = ";
// cin>>marks;

// if(marks >=80 && marks <=100)
// {
//     cout<<"The grade of a student is A \n";
// }
// else if(marks >=70 && marks <80)
// {
//     cout<<"The grade of a student is B\n";
// }
// else if(marks >=60 && marks <70)
// {
//     cout<<"The grade of a student is c\n";
// }
// else if(marks >=50 && marks <60)
// {
//     cout<<"The grade of a student is D\n";
// }
// else{
//     cout<<"The student has F grade and he fail\n";
// }

return 0;
}