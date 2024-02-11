#include<iostream>
#include <string>

struct store{
    std::string product_id;
    std::string product_name;
    int price;
    int quantity;
    std::string other;
};
///
void Add_Product(store *data, int &size) {
    store new_product;
    
    std::cout << "\n\nEnter the id of product: ";
    std::cin >> new_product.product_id;
    std::cout << "Enter name of product: ";
    std::cin >> new_product.product_name;
    std::cout << "Enter price of product: ";
    std::cin >> new_product.price;
    std::cout << "Enter Quantity of product: ";
    std::cin >> new_product.quantity;
    std::cin.ignore();  // Clear the newline character from the input buffer
    std::cout << "Enter any other detail of product: ";
    std::getline(std::cin, new_product.other);

    data[size] = new_product;
    size++;
    return;
}


void Display(store *data,int size){
     
     for (int i = 0; i < size; i++)
     {
        std::cout<<"\n\ndetail of product "<<i+1<<std::endl;
        std::cout<<"Id of product "<<data[i].product_id<<":\n";
        std::cout<<"Name of product "<<data[i].product_name<<":\n";
        std::cout<<"Price of product "<<data[i].price<<":\n";
        std::cout<<"Quentity of product "<<data[i].quantity<<":\n";
        std::cout<<"other detail of product "<<data[i].other<<":";
     }
     
    return;
}

void search(store *data,int size){
     std::string id_find;
     std::cout<<"\n\nEnter ID of product which's detail you want to find: ";
     std::cin>>id_find;
     bool flage = false;
     for (int i = 0; i < size; i++)
     {
        if(id_find==data[i].product_id){
          std::cout<<"Id of product "<<data[i].product_id<<":\n";
          std::cout<<"Name of product "<<data[i].product_name<<":\n";
          std::cout<<"Price of product "<<data[i].price<<":\n";
          std::cout<<"Quentity of product "<<data[i].quantity<<":\n";
          std::cout<<"other detail of product "<<data[i].other<<":"; 
          flage =true;
          break; 
        }
     }
     if(!flage){
         std::cout << "Invalid ID. Please try again.\n";
     }
   return;  
}

void update_product(store *data,int size){
    std::string Id;
    std::cout<<"\n\nEnter ID of product which's detail you want to update: ";
    std::cin>>Id;

    for (int i = 0; i < size; i++)
    {
        if(Id==data[i].product_id){
            std::cout<<"Detail of product :"<<std::endl;
            std::cout<<"Id of product "<<data[i].product_id<<":\n";
            std::cout<<"Name of product "<<data[i].product_name<<":\n";
            std::cout<<"Price of product "<<data[i].price<<":\n";
            std::cout<<"Quentity of product "<<data[i].quantity<<":\n";
            std::cout<<"other detail of product "<<data[i].other<<":\n\n"; 
            //it will print all detail of product before update

            int choice;
            std::cout<<"Menu:\n";
            std::cout<<"1. Update product ID:"<<std::endl;
            std::cout<<"2. Update Product Name:"<<std::endl;
            std::cout<<"3. Update product price:"<<std::endl;
            std::cout<<"4. Update product Quantity:"<<std::endl;
            std::cout<<"5. Update product all details:"<<std::endl;
            std::cout<<"Enter your choice: ";
            std::cin>>choice;

            switch (choice)
            {
            case 1:
                std::cout<<"Enter New id of product: ";
                std::cin>>data[i].product_id;
                break;
            case 2:
                std::cout<<"Enter New name of product: ";
                std::cin>>data[i].product_name;
                break;
            case 3:
                std::cout<<"Enter New price of product: ";
                std::cin>>data[i].price;
                break;
            case 4:
                std::cout<<"Enter New Quantity of product: ";
                std::cin>>data[i].quantity;
                break;
            case 5:
                 std::cout<<"\n\nEnter New id of product: ";
                 std::cin>>data[i].product_id;
                 std::cout<<"Enter New name of product: ";
                 std::cin>>data[i].product_name;
                 std::cout<<"Enter New price of product: ";
                 std::cin>>data[i].price;
                 std::cout<<"Enter New Quantity of product: ";
                 std::cin>>data[i].quantity;
                 std::cin.ignore();  // Clear the newline character from the input buffer
                 std::cout<<"Enter New other detail of product: ";
                 getline(std::cin,data[i].other);
                break;
            
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;

            }//end of switch statment
        }//end of if condition
    }// end of for loop 
    
    return;
}

int main(int argc, char const *argv[])
{
    int choice;
    int maxnumber=100;
    int size=0;
    store data[maxnumber];
    while(1){
      std::cout<<"\n\n";
      std::cout<<"Menu:"<<std::endl;
      std::cout<<"1. Add a new product:"<<std::endl;
      std::cout<<"2. Display the  all detail: "<<std::endl;
      std::cout<<"3. Search detail by product id: "<<std::endl;
      std::cout<<"4. Update any product detail by product id:"<<std::endl;
      std::cout<<"5. Quit:"<<std::endl;
      std::cout<<"Enter your choice: ";
      std::cin>>choice;

      switch (choice)
      {
      case 1:
        Add_Product(data,size);
        break;
      case 2:
        Display(data,size);
        break;
      case 3:
        search(data,size);
        break;
      case 4:
        update_product(data,size);
        break;
      case 5:
       return 1;
       break;
      default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
      }
    }
    return 0;
}
