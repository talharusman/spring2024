#include<iostream>

void recursiveSwap(int &a,int &b,int n = 3){
  if(!n) return;

  a^=b;
 recursiveSwap(b,a, n - 1);
       return;
}

int main(int argc, char const *argv[])
{
    int a,b;
    std::cout<<"enter a:";
    std::cin>>a;
    std::cout<<"enter b:";
    std::cin>>b;
      
    std::cout<<"Before Swaping"<<std::endl;
    std::cout<<"a is->"<<a<<std::endl<<"b is->"<<b<<std::endl;

    recursiveSwap(a,b);
    std::cout<<"After Swaping:"<<std::endl;
    std::cout<<"a is->"<<a<<std::endl<<"b is->"<<b<<std::endl;
    return 0;
}
