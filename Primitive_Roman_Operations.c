#include<stdio.h>
#include<math.h>
#include<string.h>
long long int RomanToHindu(char roman[]){
    long long int d[100]={0};
    for(long long int i=0;i<strlen(roman);++i){
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
   long long int ans=0;
   for(long long int i=0;i<strlen(roman);++i){
      if(d[i+1]<=d[i]||i==strlen(roman)-1)
         ans+=d[i];
      else
         ans-=d[i];
   }
    return ans;
}
void print_Roman(char num1[]){
   int length=strlen(num1),k=0;
    char final_answer[100]={'\0'};
    int values_in_order[7]={0};//to store the count of M,D,C,L,X,V,I
    for(int i=0;i<length;++i){
        if(num1[i]=='M')
        values_in_order[0]++;
        else if(num1[i]=='D')
        values_in_order[1]++;
        else if(num1[i]=='C')
        values_in_order[2]++;
        else if(num1[i]=='L')
        values_in_order[3]++;
        else if(num1[i]=='X')
        values_in_order[4]++;
        else if(num1[i]=='V')
        values_in_order[5]++;
        else
        values_in_order[6]++;
    }
    for(int i=0;i<7;++i){
        if(i==0){
           for(int j=0;j<values_in_order[i];j++){
               final_answer[k++]='M';
           }
        }
        else if(i==1){
           for(int j=0;j<values_in_order[i];j++){
               final_answer[k++]='D';
           }
        }
        else if(i==2){
           for(int j=0;j<values_in_order[i];j++){
               final_answer[k++]='C';
           }
        }
        else if(i==3){
           for(int j=0;j<values_in_order[i];j++){
               final_answer[k++]='L';
           }
        }
        else if(i==4){
           for(int j=0;j<values_in_order[i];j++){
               final_answer[k++]='X';
           }
        }
        else if(i==5){
           for(int j=0;j<values_in_order[i];j++){
               final_answer[k++]='V';
           }
        }
        else {
            for(int j=0;j<values_in_order[i];j++){
               final_answer[k++]='I';
           }
        }
    }
    printf("%s\n",final_answer);
}
void product(char num1[],char num2[]){
   long long int no_1=RomanToHindu(num1);
   char ans[100]={'\0'};
   for(int i=0;i<no_1;++i){
      strcat(ans,num2);
   }
   print_Roman(ans);
   return;
}
int main(){
    char num1[100],num2[100],sum[100];
    printf("Enter Two numbers For Sum and Product\n");
    printf("(Disclaimer-STRICTLY RESTRICTED to Primitive Types i.e. No XIV but XIIII)\n");
    scanf("%s %s",num1,num2);
    strcpy(sum,num1);
    strcat(sum,num2);
    printf("The Sum is \n");
    print_Roman(sum);
    printf("The Product is \n");
    product(num1,num2);
    return 0;
}