#include<iostream>
int GCD(int a ,int b){
    if(!b){
        return a;
    }
    return GCD(b, a % b );
}

int LCM(int a, int b){
    static int high = std::max(a,b), low = std::min(a,b), res = high;
    if(!(res % low)) return res;
    res += high;
    return LCM(a,b);
}

int main(int argc, char const *argv[])
{
    int a,b;
    
    std::cout<<"enter number 1: ";
    std::cin>>a;
    std::cout<<"enter number 2: ";
    std::cin>>b;

    std::cout<<"GCD is "<<GCD(a,b)<<":"<<std::endl<<std::endl;
    std::cout<<"LCM is "<<LCM(a,b)<<":"<<std::endl<<std::endl;

        return 0;
}
