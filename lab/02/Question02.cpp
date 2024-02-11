#include"iostream"

struct book
{
   std:: string title;
   std:: string author;
   int year_of_publication;
   std:: string genre;
};

void Add_new_book(book *librarey,int &book_num){
     book new_book;
             
        std::cout<< "\n\nEnter the tital of Book:";
        std::cin>>new_book.title;
        std::cout<< "Enter the auther of Book:";
        std::cin>>new_book.author;
        std::cout<< "Enter the year of publication of Book:";
        std::cin>>new_book.year_of_publication;
        std::cout<< "Enter the generation of Book:";
        std::cin>>new_book.genre;
        std::cout<<"\n\n";
        librarey[book_num]=new_book;
        book_num++;
    return;
}

void display(book *librarey, int n){
    std::cout<<"\n\n";
    for (int i = 0; i < n; i++)
    {
        std::cout<<"Detail of Book "<<i+1<<std::endl;
        std::cout<<"Book tital is "<<librarey[i].title<<":"<<std::endl;
        std::cout<<"Book auther is "<<librarey[i].author<<":"<<std::endl;
        std::cout<<"Book's Year of publication is "<<librarey[i].year_of_publication<<":"<<std::endl;
        std::cout<<"Book's genreation is "<<librarey[i].genre<<":\n\n";
        
    }
    
   return;
}

void search(book *librarey, int n){
    std::string find_tital,find_auther;
    
    std::cout<<"\n\nEnter Book tital you want to find:";
    std::cin>>find_tital;
    std::cout<<"Enter Book auther's Name you want to find:";
    std::cin>>find_auther;
    bool flag=false;
    for (int i = 0; i < n; i++)
    {
        if(librarey[i].title==find_tital && librarey[i].author==find_auther){
          std:: cout<<"\n\nDetail of Book you want to find:\n\n";
          std::cout<<"Book tital is "<<librarey[i].title<<":"<<std::endl;
          std::cout<<"Book auther is "<<librarey[i].author<<":"<<std::endl;
          std::cout<<"Book's Year of publication is "<<librarey[i].year_of_publication<<":"<<std::endl;
          std::cout<<"Book's genreation is "<<librarey[i].genre<<":\n\n";
          flag=true;
          break;
        }
    }
    if(!flag) std::cout<<"\n\nError! this book is not found:\n\n";

    return;
}

int main(int argc, char const *argv[])
{
     int max_book=200;
     int book_num=0;
   
     book library[max_book];
     do{

        int choice;
        std::cout << "Menu:\n";
        std::cout << "1. Add a new book\n"<< "2. Display all books\n"<< "3. Find a book by title or author\n"<< "4. Quit\n";
        std::cout<<"Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
           Add_new_book(library,book_num);
           break;

        case 2:
          display(library,book_num);
          break;

        case 3:
          search(library,book_num);
          break;

        case 4:
           return 1;
           break;

        default:
            std::cout << "Error! Choose the correct choice." <<std::endl;
            break;

        } 
     }while(1);
  
    return 0;
}
