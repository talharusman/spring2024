#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[4]={2,7,11,15};
    int a,b; 
    bool flag=false;
    for(int i=0; i< 4;i++){
        for(int j=i; j< 4;j++){
            if(arr[j]+arr[i]==9){
                a=i;
                b=j;
                flag=true;
                break;
            }
        }
    }

    if(flag){
        
        cout<<"["<<a<<","<<b<<"]"<<endl;
        cout<<"Because nums["<<a<<"] + nums["<<b<<"] == 9";
    }else cout<<" number is not found:";
    

    return 0;
}
