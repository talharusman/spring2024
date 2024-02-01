#include<iostream>
using namespace std;
struct Register
{
    string course_id;
    string course_name;
};

struct student : Register
{
    string studentId;
    string first_name;
    string last_name;
    int call_no;
    string email;
};

void display(student *student_data){
    
    for (int i = 0; i < 5; i++)
    {
        cout<<"studnt id is: "<<student_data[i].studentId<<endl;
        cout<<"student first name is: "<<student_data[i].first_name<<endl;
        cout<<"student last name is: " <<student_data[i].last_name<<endl;
        cout<<"student call no is: "<<student_data[i].call_no<<endl;
        cout<<"student email is: "<<student_data[i].email<<endl;
        cout<<"course id is: "<<student_data[i].course_id<<endl;
        cout<<"course name is: "<<student_data[i].course_name<<endl;
    }
    
     
    return;
}

int main(int argc, char const *argv[])
{
    student student_data[5];
    //this loop take input from user
    for (int i = 0; i < 5; i++){
        cout<<"enter the student id:";
        cin>>student_data[i].studentId;
        cout<<"enter the first name of student:"<<endl;
        cin>>student_data[i].first_name;
        cout<<"enter the last name of student:"<<endl;
        cin>>student_data[i].last_name;
        cout<<"enter the call noumbr of student:"<<endl;
        cin>>student_data[i].call_no;
        cout<<"enter the email addrace of student:"<<endl;
        cin>>student_data[i].email;
        cout<<"enter the course Id you want to ragister:"<<endl;
        cin>>student_data[i].course_id;
        cout<<"enter course name which you want to ragister:"<<endl;
        cin>>student_data[i].first_name;
     }

     //display the data
      display(student_data);
    return 0;
}
