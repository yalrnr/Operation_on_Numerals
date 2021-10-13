#include<stdio.h>
#include<math.h>
#include<string.h>
long long int BinaryToHindu(long long int binary);
long long int HinduToBinary(long long int num);
long long int UnaryToHindu(char str[]);
void HinduToUnary(int num);
long long int RomanToHindu(char roman[]);
void HinduToRoman(int num);
int main(){
    printf("This program is for conversion of numbers from one system to another\n");
    printf("Hindu/Arabic System - 1\nRoman Sytem - 2\nUnary System - 3\nBinary System - 4\n");
    printf("Enter Source System and Destination System numbers respectively\n");
    long long int source,destination;
    scanf("%lld %lld",&source,&destination);
    if(source==1){
        long long int n;
        scanf("%lld",&n);
        if(destination==2)
        HinduToRoman(n);
        else if(destination==3)
        HinduToUnary(n);
        else{
           long long int ans=HinduToBinary(n);
           printf("%lld",ans);
        }
    }
    else if(source==2){
         if(destination==1){
             char roman[100];
             scanf("%s",roman);
             long long int ans=RomanToHindu(roman);
             printf("%lld",ans);
         }
         else if(destination==3){
             char roman[100];
             scanf("%s",roman);
             long long int ans=RomanToHindu(roman);
             HinduToUnary(ans);
         }
         else{
             char roman[100];
             scanf("%s",roman);
             long long int ans=RomanToHindu(roman);
             long long int final_ans=HinduToBinary(ans);
             printf("%lld",final_ans);
         }
    }
    else if(source==3){
            if(destination==1){
                char str[100];
                scanf("%s",str);
                long long int ans=UnaryToHindu(str);
                printf("%lld",ans);
            }
            else if(destination==2){
                char str[100];
                scanf("%s",str);
                long long int ans=UnaryToHindu(str);
                HinduToRoman(ans);
            }
            else{
                char str[100];
                scanf("%s",str);
                long long int ans=UnaryToHindu(str);
                long long int final_ans=HinduToBinary(ans);
                printf("%lld",final_ans);
            }
    }
    else{
        if(destination==1){
            long long int num,ans;
            scanf("%lld",&num);
            ans=BinaryToHindu(num);
            printf("%lld",ans);
        }
        else if(destination==2){
            long long int num,ans;
            scanf("%lld",&num);
            ans=BinaryToHindu(num);
            HinduToRoman(ans);
        }
        else{
            long long int num,ans;
            scanf("%lld",&num);
            ans=BinaryToHindu(num);
            HinduToUnary(ans);
        }
    }

    return 0;
}
long long int UnaryToHindu(char str[]){
    return strlen(str);
}
void HinduToUnary(int num){
    char arr[num];
    for(int i=0;i<num;++i){
        arr[i]='I';
        printf("%c",arr[i]);
    }
    return;
}
long long int BinaryToHindu(long long int binary){
        long long int i=0, remainder;
         long long int ans=0;
            while (binary!=0) {
                remainder=binary%10;
                binary/=10;
                ans+=remainder*pow(2, i);
                ++i;
            }
     return ans; 
}
long long int HinduToBinary(long long int num){
        long long int i=1, remainder;
         long long int ans=0;
            while (num!=0) {
                remainder=num%2;
                num/=2;
                ans+=remainder*i;
                i*=10;
            }
     return ans; 
}
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
void HinduToRoman(int num){
    int reminder,counter,i=0;
    char str[100]={'0'};
    for(counter=1;counter<=num/1000;counter++){
      str[i]='M';
      i++;
}
reminder = num%1000;

for(counter=reminder/900;counter==1;counter++){
       str[i]='C';
       i++;
       str[i]='M';
       i++;
}
reminder = reminder%900;

for(counter=reminder/500;counter==1;counter++){
       str[i]='D';
       i++;
}
reminder = reminder%500;

for(counter=reminder/400;counter==1;counter++){
    str[i]='C';
    i++;
    str[i]='D';
    i++;
}
reminder = reminder%400;

for(counter=1;counter<=reminder/100;counter++){
    str[i]='C';
    i++;
}
reminder = reminder%100;

for(counter=reminder/90;counter==1;counter++){
    str[i]='X';
    i++;
    str[i]='C';
    i++;
}
reminder = reminder%90;

for(counter=reminder/50;counter==1;counter++){
    str[i]='L';
    i++;
}
reminder = reminder%50;

for(counter=reminder/40;counter==1;counter++){
    str[i]='X';
    i++;
    str[i]='L';
    i++;
}
reminder = reminder%40;

for(counter=reminder/10;counter>=1;counter--){
    str[i]='X';
    i++;
}
reminder = reminder%10;

for(counter=reminder/9;counter==1;counter++){
    str[i]='I';
    i++;
    str[i]='X';
    i++;
}
reminder = reminder%9;

for(counter=reminder/5;counter==1;counter++){
    str[i]='V';
    i++;
} 
reminder = reminder%5;

for(counter=reminder/4;counter==1;counter++){
    str[i]='I';
    i++;
    str[i]='V';
    i++;
}
reminder = reminder%4;
for(counter=reminder;counter>=1;counter--){
     str[i]='I';
     i++;
}
for(int j=0;j<i;++j)
   printf("%c",str[j]);
   return;
}