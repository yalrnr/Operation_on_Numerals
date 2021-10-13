#include<stdio.h>
#include <string.h>
int to_decimal(char roman[]){
    int d[100]={0};
    for(int i=0;i<strlen(roman);++i){
      switch(roman[i]){
         case 'I': d[i]= 1;
         break;
         case 'V': d[i]= 5;
         break;
         case 'X': d[i]= 10;
         break;
         case 'L': d[i]= 50;
         break;
         case 'C': d[i]= 100;
         break;
         case 'D': d[i]= 500; 
         break;
         case 'M': d[i]=1000;
      }
   }
   int ans=0;
   for(int i=0;i<strlen(roman);++i){
      if(d[i+1]<=d[i]||i==strlen(roman)-1)
         ans+=d[i];
      else
         ans-=d[i];
   }
    return ans;
}
void print_Roman(int num);
int main(){
   char num1[100],num2[100];
   printf("Enter Two numbers to get the sum and product\n");
   scanf("%s %s",num1,num2);
   int val1,val2;
   val1=to_decimal(num1);
   val2=to_decimal(num2);
   int sum,product;
   sum=val1+val2;
   product=val1*val2;
   printf("The Sum of the two numbers is \n");
   print_Roman(sum);
   printf("\n");
   printf("And The Product of the two numbers is \n");
   print_Roman(product);
   printf("\n");
   return 0;
}
void print_Roman(int num){
    while(num!=0){
        if (num >= 1000){
           printf("M");
           num-=1000;
        }
        else if (num>=900){
           printf("CM");
           num-=900;
        }
        else if (num>=500){           
           printf("D");
           num-=500;
        }
        else if (num>=400){
           printf("CD");
           num-=400;
        }
        else if (num>=100){
           printf("C");
           num-=100;                       
        }
        else if (num>=90){
           printf("XC");
           num-=90;                                              
        }
        else if (num>=50){
           printf("L");
           num-=50;                                                                     
        }
        else if (num>=40){
           printf("XL");           
           num-=40;
        }
        else if (num>=10){
           printf("X");
           num-=10;           
        }
        else if (num >= 9){
           printf("IX");
           num-=9;                         
        }
        else if (num>=5){
           printf("V");
           num-=5;                                     
        }
        else if (num>=4){
           printf("IV");
           num-=4;                                                            
        }
        else if (num>=1){
                printf("I");
                num-=1; 
        }
    }
    return;
}