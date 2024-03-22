#include<iostream>

using namespace std;

class appointment{
        static int Appointment_numbers;
        static int Earning;
     public:
        static void Appointment_Add(int numAppoint, int totalEarnings){
            Appointment_numbers += numAppoint;
            Earning += totalEarnings;
        }

        static float calculates(){
             if(Appointment_numbers == 0){
                return  0;
             }
             return (static_cast<float>(Earning) / Appointment_numbers);
        }

};

int appointment::Appointment_numbers = 0;
int appointment::Earning = 0;


int main(int argc, char const *argv[])
{
    appointment::Appointment_Add(5,3000);
    appointment::Appointment_Add(2,2000);

    cout<<"Average cost of per Appointment: "<<appointment::calculates()<<endl;

    return 0;
}
