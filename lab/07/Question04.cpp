#include<iostream>
using namespace std;

class person{
     string name;
     int age;
    public:
        person(string name,int age){
            this->name = name;
            this->age = age;
        }

        void display(){
            cout<<"Name is: "<<name<<endl;
            cout<<"Age is: "<<age<<endl;
        }
};

class student : public person{
      string id;
      string grade_level;

    public:
        student(string name, int age , string id, string grade_level):person(name,age)
        {
            this->id = id;
            this->grade_level = grade_level;
        }

        void display(){
             person::display();
             cout<<"Id is: "<<id<<endl;
             cout<<"Grade Level: "<<grade_level<<endl;

        }
};

class Teacher : public person{
        string subject;
        int Room_number;
    public:
        Teacher(string name,int age,string subject,int Room_number) : person(name,age){
            this->subject = subject;
            this->Room_number = Room_number;
        }  

        void display(){
            person::display();
            cout<<"Subject: "<<subject<<endl;
            cout<<"Room number: "<<Room_number<<endl;
        }
};

class GraduateStudent : public student,public Teacher{
    public:
        GraduateStudent(string name_student,int age_student, string id_student, string grade_student,string name_teacher,int age_teacher,string subject,int Room_number):
        student(name_student,age_student,id_student,grade_student),Teacher(name_teacher,age_teacher,subject,Room_number){

        }

        void display(){
            cout<<"\nDisplaying Gradute Student Information:"<<endl;
            student::display();
            cout<<"\nTeacher Information:"<<endl;
            Teacher::display();
        }
        
};

int main(int argc, char const *argv[])
{
    GraduateStudent obj("Talha Rusman",19,"23k-0065","A","Talha Shahid",28, "OOP", 7);
    obj.display();
    
    return 0;
}
