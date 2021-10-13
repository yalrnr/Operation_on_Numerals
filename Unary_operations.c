#include<stdio.h>
#include <string.h>
int main(){
    char num1[100],num2[100];
    printf("Enter Two numbers for Sum and Product\n");
    scanf("%s",num1);
    scanf("%s",num2);
    int length1=strlen(num1);
    strcat(num1,num2);
    printf("The sum is %s\n",num1);
    printf("The Product is ");
    for(int i=0;i<length1;++i){
        printf("%s",num2);
    }
    printf("\n");
    return 0;
}
