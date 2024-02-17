/*Programer: Talha Rusman
  Roll_N0: 23K0065
  */
#include<iostream>
using namespace std;
class Book{
    string book_name;
    string auther_name;
    int ISBN_Number;
    int Pages_read;
    public:
    int total_page;
    Book(){
      total_page = 1000;
      Pages_read = 0;

    }
    //setter
    void setremaing(string name,string auther,int ISBN){
        book_name = name;
        auther_name = auther;
        ISBN_Number = ISBN;
    }
    //getter
    string getName(){
        return book_name;
    }
    string getAuther(){
        return auther_name;
    }
    int getISBN(){
        return ISBN_Number;
    }
    int getRead(){
        return Pages_read;
    }
    int getTotal(){
        return total_page;
    }
};
// mathod display all detail
void showBookInfo(Book a){
    cout<<"Book name: "<<a.getName()<<endl;
    cout<<"Auther name: "<<a.getAuther()<<endl;
    cout<<"ISBN number: "<<a.getISBN()<<endl;
    cout<<"total pages: "<<a.getTotal()<<endl;
    cout<<"page readed: "<<a.getRead()<<endl;
}


int main(int argc, char const *argv[])
{
    Book a;
    a.setremaing("Physics","anton",30);
    showBookInfo(a);
    
    return 0;
}
