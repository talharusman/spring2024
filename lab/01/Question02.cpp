#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int marks;
    int total_marks,average;
     int arr[1000][1000], num_Student;

     cout<<"enter the number of student:";
     cin>>(num_Student);

for(int i = 0;i < num_Student; i++){
    for (int j = 0; j < 3; j++)
    {
        cout<<"enter the marks of student"<<i+1<<"in subject "<<j+1;
        cin>>arr[i][j];
    }
    
}   
 
    for (int i = 0; i< num_Student; i++)
    {
        total_marks=0;
        for (int j = 0; j < 3; j++)
        {
            total_marks= total_marks+arr[i][j];
        }//end of for loop
        
        average = (total_marks/3)*100;

        if(average>=90){
            cout<<"Gread of student no"<<i<<"is A";
        }else if (average>=80&&average<=89)
        {
           cout<<"Gread of student no"<<i<<"is B";
        }else if (average>=70&&average<=79)
        {
           cout<<"Gread of student no"<<i<<"is C";
        }else if (average>=60&&average<=69)
        {
           cout<<"Gread of student no"<<i<<"is D";
        }else if (0&&average<60)
        {
           cout<<"Gread of student no"<<i<<"is F";
        }
    }


    return 0;
}
