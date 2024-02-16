#include <iostream>
#include <iomanip>
using namespace std;

class stationary
{
public:
    string iteam;
    float price;
};

// for addition of detail of items in the  shop
void Add_Detail(stationary data[], int &count)
{
    cout << "\n\n";
    cout << "Enter the name of iteam: ";
    cin >> data[count].iteam;
    cout << "Enter Price of  this iteam: ";
    cin >> data[count].price;
    count++;
    return;
} // end of add detail function

// funtion to retrive 

void Retrieve(stationary data[],int count){
      cout<<"\n\n";
      for (int i = 0; i < count; i++)
      {
        cout<<"iteam "<<i+1<<" is "<<data[i].iteam<<endl;
      }
      
    return;
}


// it will update the price of iteam
void Modifay_price(stationary data[], int count)
{
    string old_name;
    cout << "\n\nEnter the name of iteam which's price you want update: ";
    cin >> old_name;
    bool flage = false;
    for (int i = 0; i < count; i++)
    {
        if (data[i].iteam == old_name)
        {
            cout << "\nEnter the new price of iteam: ";
            cin >> data[i].price;
            flage = true;
        }
    }
    if (!flage)
        cout << "Error! iteam is not found: " << endl;
    return;
} // end of update price function

// it will display the all iteam along with price
void Display(stationary data[], int count)
{
    cout << "\n\n";

    for (int i = 0; i < count; i++)
    {
        cout << "Iteam is " << data[i].iteam
             << "Price is " << data[i].price
             << endl;
    }

} // end of display function

// This function will make a recipeat for coustumer
void receipt(stationary data[], int count)
{
    int no_iteam;
    string iteam_name;

    float total_price = 0;
    cout << "\n\nEnter how many iteam buy: ";
    cin >> no_iteam;
    stationary buy_product[count];
    float price[no_iteam];
    int num = 0;
    int chaker = 0;

    for (int i = 0; i < no_iteam; i++)
    {
            cout << "\nenter the name of iteam " << i + 1 << ": ";
            cin >> iteam_name;
            bool flage = false;

            for (int j = 0; j < count; j++)
            {
                int pices = 0;
                if (data[j].iteam == iteam_name)
                {
                    cout << "Enter The Quentity: ";
                    cin >> pices;
                    price[num] = data[j].price * pices;
                    buy_product[num].iteam = data[j].iteam;
                    buy_product[num].price = data[j].price;
                    total_price += data[j].price * pices;
                    num++;
                    flage = true;
                    break;
                }
            } // end of for loop
            if (flage)
                chaker++;
            else
                cout << "Error! enter the valid iteam name:" << endl;
    }
    if (num > 0)
    {
        cout << "\n\nItem Name" << setw(15) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << left << setw(20) << buy_product[i].iteam << setw(10) << buy_product[i].price << setw(10) << price[i] / buy_product[i].price << setw(10) << price[i] << endl;
        }
        cout << "----------------------------------------------" << endl;
        cout <<left<<setw(40)<< "Total bill: " << total_price << endl;
    }
    return;
} // end of recipeat function

int main(int argc, char const *argv[])
{
    stationary data[200];
    int count = 0;

    while (1)
    {
        int choice;
        cout << "\n\n";
        cout << "-------------Menu-------------" << endl;
        cout << "1. Add items and their prices." << endl
             << "2. Retrieve the list of items." << endl
             << "3. Modify the prices of items." << endl
             << "4. Display all items.         " << endl
             << "5. Generate a receipt.        " << endl
             << "6. exit                       " << endl
             << " Enter your choice.           " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Add_Detail(data, count);
            break;
        case 2:
             Retrieve(data,count);
            break;
        case 3:
            Modifay_price(data, count);
            break;
        case 4:
            Display(data, count);
            break;
        case 5:
            receipt(data, count);
            break;
        case 6:
            return 1;
            break;
        default:
            cout << "Error! Enter a valid choice:";
            break;
        }
    }

    return 0;
}
