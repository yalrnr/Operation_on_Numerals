#include<stdio.h>
long int productOfTwoNumbers(int binary1,int binary2);
int binaryAddition(int binary1,int binary2);
int main(){

    int binary1,binary2,sumoftwonumbers;
    long int product;

    printf("Enter the two binary numbers\n");
    scanf("%ld %ld",&binary1,&binary2);
    sumoftwonumbers=binaryAddition(binary1, binary2);   
    printf("The Sum is %ld\n",sumoftwonumbers);
    product=productOfTwoNumbers(binary1, binary2);
    printf("The Product is %ld\n", product);
   
   return 0;
}
int binaryAddition(int binary1,int binary2){
    
    int i=0,remainder = 0,sum[20];
    int binarySum=0;

    while(binary1!=0||binary2!=0){
         sum[i++] =  (binary1 %10 + binary2 %10 + remainder ) % 2;
         remainder = (binary1 %10 + binary2 %10 + remainder ) / 2;
         binary1 = binary1/10;
         binary2 = binary2/10;
    }

    if(remainder!=0)
         sum[i++] = remainder;
    --i;

    while(i>=0)
         binarySum = binarySum*10 + sum[i--];

    return binarySum;
}
long int productOfTwoNumbers(int binary1,int binary2){

    long int product=0;
    int digit,factor=1;

    while(binary2!=0){
         digit =  binary2 %10;

         if(digit ==1){
                 binary1=binary1*factor;
                 product = binaryAddition(binary1,product);
         }
         else
             binary1=binary1*factor;
   
         binary2 = binary2/10;
         factor = 10;
    }

    return product;
}