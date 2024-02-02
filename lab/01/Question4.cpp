#include<iostream>
using namespace std;

// int maxarea(int height[] ,int n){
//     int max_whater=0;
//     int left=0;
//     int right=n-1;

//     while(right > left){
//       int h = min(height[left], height[right]);
//       int w = right - left;

//       max_whater = max(max_whater, h*w);

//       if (height[left] < height[right]) {
//             left++;
//         } else {
//             right--;
//         }
//     }
//     return max_whater;
// }
int maxarea(int height[], int n){
    int maxh = 0;
    for(int i =0; i<n ; i++){
        for(int j = 0; j < n ; j++){

            if(i!= j)
                maxh = max(maxh, (i-j) * min(height[j],height[i]));
        }
    }
    return maxh;
}

int main(int argc, char const *argv[])
{
    int hight[]={1,8,6,2,5,4,8,3,7};//hight of the towers
    int n=sizeof(hight)/sizeof(int);
    
    int result=maxarea(hight,n);
    cout<<"maximum amount of whater is ="<<result;
    
    return 0;
}
