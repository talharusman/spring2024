#include<stdio.h>

main(){
	int n;
	printf("enter any positive number:");
	scanf("%d",&n);
	if(n>0){ 
	  if(n%2==0){
	  	printf("given number is even");
	  }else{
	  	printf("number is odd");
	  }//end of else of n%2==0
	}else{
		printf("error");
	}//end of else of n>0
	return 0;
}//end main
