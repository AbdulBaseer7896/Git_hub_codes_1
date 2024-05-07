// #include<iostream>
// using namespace std;

// class node
// {
//     public:
//     int data;
//     node * next;

//     node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }
// };



// class stack
// {
//     node * top;
//     public:
//     stack()
//     {
//         this->top = NULL;
//     }

//     void push(int num)
//     {
//         node * temp = new node();

//         if(temp =
//         = NULL)
//         {
//             cout<<"The stack is overflow"<<endl;
//             return;
//         }
//         else
//         {
//             temp->data = num;
//             temp->next = top;
//             top = temp;
//         }
//     }

//     char pop()
//     {
//         char exp1;
//         node * temp = top;
//         if(top == NULL)
//         {
//             cout<<"The stack is empty"<<endl;
//             return 'a';
//         }
//         else{
//             exp1 = temp->data;
//             top = temp->next;
//             free(temp);
//         }
//         return exp1;
//     }



//     void postfix(char * exp)
//     {
//         node * temp = top;

//         int i, j=0;
//         char * post_exp;

//         cout<<"hello "<<endl;
//         while(exp[i] != '\0')
//         {
//             if(!operat_cheeking(exp[i]))
//             {
//                 post_exp[j] = exp[i];
//                 j++;
//                 i++;
//             }

//             else
//             {
//                 char cheek = temp->data;
//                 if(exp[i] > predicens_matching(cheek))
//                 {
//                     push(exp[i]);
//                     i++;
//                 }
//                 else
//                 {
//                     post_exp[j] = pop();
//                     j++;
//                 }
//             }
//         }

//         while(temp!= NULL)
//         {
//             post_exp[j] = pop(); 
//             j++;
//         }
//         post_exp[j]= '\0';
//         cout<<"This is the postfix expressiin = "<<post_exp<<endl;
//     }

//     int predicens_matching(char cheek)
//     {
//         if(cheek == '*' || cheek == '/')
//         return 3;
//         else if(cheek == '+' || cheek == '-')
//         return 2;
//         else
//         return 0;
//     }


//     int operat_cheeking(char cheek)
//     {
//         if(cheek == '*' || cheek == '/' ||cheek == '+' || cheek == '-')
//             return 1;
//         else
//             return 0;
//     }
// };
// int main()
// {

// char * exp = "x+y*z";
// stack s;
// cout<<"hello";
// s.postfix(exp);
// return 0;
// }