#include<iostream>

using namespace std;

 class  SmartPhone{
       string Brand;
       string Model;
       int Resolution;
       int RAM;
       int ROM;
       int Storage;
        public:

        //setter
        void setbrand(string Brand){
            this->Brand = Brand;
        }
        void setModal(string Modal){
            this->Model = Model;
        }
        void setResolution(int Resolution){
            this->Resolution = Resolution;
        }
        void setRam(int RAM){
            this-> RAM= RAM;
        }
        void setRom(int ROM){
            this->ROM=ROM;
        }
        void setStorage(int Storage){
            this ->Storage = Storage;
        }

        //getter
        string getbrand(){
            return this->Brand;
        }
        string getMOdal(){
            return this->Model;
        }
        int getresolution(){
            return this->Resolution;
        }
        int getram(){
            return this->RAM;
        }
        int getrom(){
            return this->ROM;
        }
        int getstorge(){
            return this->Storage;
        }

        //methods
        void phonecall(){
            cout << "phone calling" << endl<<endl;
        } 
        void Send_messages(){
            cout<<"Massage is sand:"<<endl<<endl;
        }
        void wifi(){
            cout<<"Connecting to Wi-Fi"<<endl<<endl;
        }
        void Browsing(){
            cout<<"internat Browsing"<<endl<<endl;
        }

 };
int main(int argc, char const *argv[])
{
    SmartPhone Vivo;
    Vivo.setbrand("Vivo");
    Vivo.setModal("V21");
    Vivo.setResolution(120);
    Vivo.setRam(16);
    Vivo.setRom(20);
    Vivo.setStorage(258);

    //call getters
    string temp;
      temp = Vivo.getbrand();
      cout<<"Brand is "<<temp<<endl;
      temp = Vivo.getMOdal();
      cout<<"Modal is "<<temp<<endl;
    int temp1;
      temp1 = Vivo.getresolution();
      cout<<"Resolution is "<<temp1<<endl;
      temp1 = Vivo.getram();
      cout<<"Ram is "<<temp1<<"GB:"<<endl;
      temp1 = Vivo.getrom();
      cout<<"Rom is "<<temp1<<"GB:"<<endl;
      temp1 = Vivo.getstorge();
      cout<<"storage is "<<"GB"<<endl<<endl;

    Vivo.phonecall();
    Vivo.Send_messages();
    Vivo.wifi();
    Vivo.Browsing();
      
    return 0;
}