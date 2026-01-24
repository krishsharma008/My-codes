#include <stdio.h>
#include <math.h>
int main() {
int a,b,choice;
printf("Enter you values: ");
scanf("%d %d" , &a ,&b);
while(1){
        printf("\nselect the choice: \n");
        printf("1. ADD \n");
        printf("2. SUBTRACT \n");
        printf("3. DIVIDE \n");
        printf("4. MULTIPLE \n");
        printf("5. AVERAGE \n");
        printf("6. EXIT \n");
        scanf("%d", & choice);
    
        if(choice==1){
        printf("ADD: %d",a+b);}
        else if (choice==2){
        printf("SUB: %d", a-b);}
        else if(choice==3){
        if(b!=0){
        printf("DIVIDE: %f", (float)a/b);}
        else{
        printf("NOT DIVIDED BY ZERO 0\n");}}
        else if(choice==4){
        printf("MULTIPLE: %d", a*b);}
        else if (choice==5){
        printf("AVERAGE: %f",(float) (a+b)/2.0);}
        else if(choice==6){
        printf("EXIT");
            break;}
        else{
        printf("INVALID CHOICE, TRY AGAIN \n");}
                   }
        return 0; }

        
        
        
        
        