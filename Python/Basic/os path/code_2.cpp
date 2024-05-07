#include <iostream>
using namespace std;

int total_marks_of_student[5];
string name[5];
int english[5];
int urdu[5];
int comp[5];

int marks[5];

void function_for_getting_data_of_student()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\n\nEnter the Name of a student = ";
        cin >> name[i];
        cout << "Enter the marks of English = ";
        cin >> english[i];
        cout << "Enter the marks of Urdu = ";
        cin >> urdu[i];
        cout << "Enter the marks of Comp = ";
        cin >> comp[i];
    }
}

void cal_total_marks()
{
    for (int i = 0; i < 5; i++)
    {
        total_marks_of_student[i] = english[i] + urdu[i] + comp[i];
    }
}

void display_total_marks_of_student()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "The name of a student = " << name[i];
        cout << "\nThe total marks of a student = " << total_marks_of_student[i] << endl
             << endl
             << endl;
    }
}
int main()
{

function_for_getting_data_of_student();
cal_total_marks();
display_total_marks_of_student();


    return 0;
}