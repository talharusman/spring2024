#include<iostream>
using namespace std;

class Table{
  int totalSeats;
    int occupied;
    bool clean;

    public:
    Table(){
        totalSeats = 4;
        occupied = 0;
        clean = true;
    }

    Table (int totalSeats): totalSeats((totalSeats == 8) ? 4 : 8)
    {
        occupied = 0;
        clean = true;
    }

    void occupy(){
        if(!clean){
            cout<<"\n\nTable is not clean anyone can't set there:"<<endl<<endl;
        }
        occupied = totalSeats;
        clean = false;
        return;
    }

    bool isclean(){
        return clean;
    }

    void lunch(){
        if(occupied!=0){
            cout<<"People are set on this table:\nyou can't lunch heare:"<<endl<<endl;
            clean = false;
        }else cout<<" Table is free; You can seat:"<<endl<<endl;
        return;
    }

    void Leave(){
        occupied = 0;
        clean = true;
        return;
    }

    void TableClean(){
        if(occupied==0){
            clean = true;
            return;
        }else cout<<"you can't clean Table Because some people are seaded on the table:"<<endl<<endl;
    }

     bool isFullyOccupied()
    {
        return occupied == totalSeats;
    }

    int gettotalseats(){
        return totalSeats;
    }

    int getOccupide(){
        return occupied;
    }

    int getfreeseats(){
        return totalSeats - occupied;
    }
};

void table_occupide(Table *Tables,int group_Member_no){
    for (int i = 0; i < 4; i++)
    {
        if(!Tables[i].isFullyOccupied()&&Tables[i].isclean()){
            Tables[i].occupy();
            cout<<"Group of "<<group_Member_no<<" member can set at Table "<<i+1<<endl<<endl;
            return;
        }
    }
     cout << "No available table for a group of " << group_Member_no << ".\n";
    return;
}

void leave_tabel(Table &table)
{
    table.Leave();
    cout << "Table emptied.\n";
}

int main(int argc, char const *argv[])
{
    Table Tables[4] = {Table(4),Table(8),Table(8),Table(4)};

    table_occupide(Tables,7);
    table_occupide(Tables,4);

    Tables[0].lunch();
    Tables[0].Leave();
    Tables[0].TableClean();

    leave_tabel(Tables[0]);


    return 0;
}
