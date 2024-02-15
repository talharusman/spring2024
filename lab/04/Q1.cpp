#include<iostream>
using namespace std;
class Book{
    string book_name;
    string ather_name;
    int ISBN_Number;
    int total_page_cont;
    public:
    int total_page;
    Book(){

    }
    Book(string name,string author,int cont,int total){
        book_name = name;
        ather_name = author;
        total_page_cont = cont;
        total_page=total;
    }

    // method
     void Pages_read(){
         if(total_page_cont==total_page){
            cout<<"finished the book"<<endl;
         }
         else cout<<"total page count "<<total_page_cont<<endl;
        return;
     }
};

int main(int argc, char const *argv[])
{
    Book a("physics","Talha",300,300);
    a.Pages_read();
    return 0;
}
