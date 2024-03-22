#include<iostream>
#include<vector>
using namespace std;



class Course{
     public:
        string Course_code;
        string Course_Name;
        int Credit_Hours;
        Course(string code,string name,int c_h ): Course_code(code),Course_Name(name),Credit_Hours(c_h){}

        

};

class student{
        string I_d;
        string Name;
        vector <Course> Enrolled;
     public:
        student(string id,string S_name):I_d(id),Name(S_name){}

        void Course_enrolled(Course cou){
              Enrolled.push_back(cou);
        }

        void Course_Drop(Course cou){
            bool flage = false;
              for (size_t i = 0; i < Enrolled.size(); i++)
              {
                if(Enrolled[i].Course_code== cou.Course_code){
                    Enrolled.erase(Enrolled.begin() + i);
                    cout<<"Course Droped successfully"<<endl;
                    flage = true;
                }
              }
              if(!flage){
                cout<<"Error! Course is not found: "<<endl;
              }
             return; 
        }

        int getTotalCreditHours() {
        int totalHours = 0;
        for (int i = 0; i < Enrolled.size(); i++) {
            totalHours += Enrolled[i].Credit_Hours;
        }
        return totalHours;
    }

    void printEnrolledCourses(){
        for (size_t i = 0; i < Enrolled.size(); i++)
        {
            cout<<"Detail of Course "<<i + 1<<endl;
            cout<<"Course Code "<<Enrolled[i].Course_code<<endl;
            cout<<"Course Name "<<Enrolled[i].Course_Name<<endl;
            cout<<"Cradit Hours "<<Enrolled[i].Credit_Hours<<endl<<endl;

        }
        
    }
};

int main(int argc, char const *argv[])
{
    Course Course1("s101","Math",3);
    Course Course2("s102","Physics",2);

    student student1("23k-0065","Talha Rusman");

    student1.Course_enrolled(Course1);
    student1.Course_enrolled(Course2);

    cout<<"Total Cradit Hours "<<student1.getTotalCreditHours()<<endl<<endl;

    student1.printEnrolledCourses();

    student1.Course_Drop(Course2);
    cout<<endl<<endl;



    return 0;
}
