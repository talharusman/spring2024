#include"iostream"
using namespace std;

class calender{
   public:
   string year[12][31]={NULL};
   void Addition(){
      int day,month;
      cout<<"enter month of task you want to add:";
      cin>>month;
      cout<<"enter day of task you want to add:";
      cin>>day;

      cout<<"enter the task:";
      cin>>year[month][day];
    return;
   }
   void removel(){
    int day,month;
      cout<<"enter month of task you want to remove:";
      cin>>month;
      cout<<"enter day of task you want to remove:";
      cin>>day;

      year[month][day]= {NULL};
   }
   void display(){
      for (int i = 0; i < 12; i++)
      {
        for (int j= 0; j < 31; j++)
        {
            if(year[i][j]!=""){
              cout<<"month of task is "<<i<<endl;
              cout<<"day of task is "<<j<<endl;
              cout<<"task is ->"<<year[i][j]<<endl<<endl;
            }
        }
        
      }
      
   }
};
int main(int argc, char const *argv[])
{  
    calender ob;
    int choice;
    while (1)
    {    
        cout<<"\n\n";
        cout<<"Menu:";
        cout<<"1. Add task\n2. Remove task\n3.Display task\n4. Exit";
        cout<<"Enter your choice:";
        cin>>choice;

        switch (choice)
        {
        case 1:
            ob.Addition();
            break;
        case 2:
            ob.removel();
            break;
        case 3:
            ob.display();
            break;
        case 4:
           return 1;
        default:
            cout<<"Error! enter coreact choice:";
            break;
        }
    }
    
    
    return 0;
}
