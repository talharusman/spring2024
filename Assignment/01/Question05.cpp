#include <iostream>
#include <vector>
using namespace std;

class Restaurant
{
    string Name, Location, Menu_List[3];
    float price_List[3];
    int valid_CouponCodesList[15];
    static int couponsRedeemedCount;

    int bill[20];
    float totalbill;

public:
    Restaurant(string name, string venue)
    {
        this->Name = name;
        this->Location = venue;
    }

    static const int totalMenu = 3;

    void setMenu(string m1, string m2, string m3, float p1, float p2, float p3)
    {
        Menu_List[0] = m1, Menu_List[1] = m2, Menu_List[2] = m3;
        price_List[0] = p1, price_List[1] = p2, price_List[2] = p3;
    }

    void displayMenu()
    {
        cout << endl
             << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << Menu_List[i] << " -$" << price_List[i] << endl;
        }
        return;
    }
    int generateBill()
    {
        return 1;
    }
    int applyDiscount()
    {
        return 1;
    }
};

class BOGOCoupon
{
    string couponCode;
    string restaurantCode;
    string valid_From;
    string valid_Until;

    friend class User;

public:
    BOGOCoupon() {}
    BOGOCoupon(string c, string f, string u, string rc) : couponCode(c), valid_From(f), valid_Until(u), restaurantCode(rc) {}

    bool is_Valid(string time)
    {
        return valid_From < time && time < valid_Until;
    }
};

class User
{
    string User_name, redeemedCoupons[15];
    BOGOCoupon coupons[15];
    int userAge;
    int mobile_Number;

public:
    User() {}
    User(string User_name, int user_age, int mobile_Number)
    {
        this->User_name = User_name;
        this->userAge = user_age;
        this->mobile_Number = mobile_Number;
    }

    int counter = 0;
    void Accumulate_coupon()
    {
        string couponCode, restaurantCode;
        string validFrom, validUntil;

        cout << "Enter restaurant code: ";
        cin >> restaurantCode;
        cout << "Enter coupon code: ";
        cin >> couponCode;
        cout << "Enter valid from: ";
        cin >> validFrom;
        cout << "Enter valid until: ";
        cin >> validUntil;

        coupons[counter] = BOGOCoupon(couponCode, validFrom, validUntil, restaurantCode);

        if (hasValidCoupon(coupons[counter], couponCode) && redeemCoupon(couponCode))
        {
            cout << "COUPON IS VALID  " << endl;
            counter++;
        }
    }

    bool hasValidCoupon(BOGOCoupon &bg, string coupon)
    {
        if (coupon[0] == bg.restaurantCode[0] && coupon[1] == bg.restaurantCode[1])
        {
            return true;
        }
        else
        {
            cout << "RESTAURANT CODE AND COUPON CODE ARE DIFFERENT " << endl;
            return false;
        }
    }

    bool redeemCoupon(string redeemCoupon)
    {
        for (int i = 0; i < counter; i++)
        {
            if (redeemCoupon == redeemedCoupons[i])
                return false;
        }
        redeemedCoupons[counter] = redeemCoupon;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Restaurant r1("Food Haven", "City Center"), r2("Pixel Bites", "Cyber street");
    r1.setMenu("Sushi", "Pad Thai", "Mango Tango", 150.0, 200.5, 235.8);
    r2.setMenu("Chaat", "Qorma", "Fatair", 500.0, 780.0, 900.5);

    cout << "\nDISPLAYING MENU OF FOOD HAVEN" << endl;
    r1.displayMenu();
    cout << "\nDISPLAYING MENU OF PIXEL BITES" << endl;
    r2.displayMenu();

    User u1, u2;
    u1 = User("Talha", 18, 25468);
    u2 = User("Talha", 35, 12584);
    u1.Accumulate_coupon();
    u2.Accumulate_coupon();

    return 0;
}
