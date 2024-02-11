#include<iostream>

bool SubSet(int arr[],int size,int targetSum){
    if (targetSum == 0)
        return true;
    if (size == 0)
        return false;
    
    if (arr[size - 1] > targetSum)
        return SubSet(arr, size - 1, targetSum);
    
     return SubSet(arr, size - 1, targetSum - arr[size - 1]) || SubSet(arr, size - 1, targetSum);
}
int main(int argc, char const *argv[])
{
     int arr[] = {3, 34, 4, 12, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 9;

    if(SubSet(arr, size,targetSum))
      std::cout<<"target sum is find:"<<std::endl;
    else
      std::cout<<"teraget sum is not found:"<<std::endl;
    return 0;
}
