#include<conio.h>
#include<stdio.h>
int main(){
int sub1, sub2, sub3;
printf("Enter the marks 1: ");
scanf("%d", & sub1);
printf("Enter the marks 2:");
scanf("%d", & sub2);
printf("Enter the marks 3: ");
scanf("%d", & sub3);
// formula of percentage 
float total_percentage= 100*(sub1+sub2+sub3)/300;
if(total_percentage>=40){
printf("Congratulations, You are passed\n");}
else if (total_percentage<=40){
printf("You are failed, Try again");}
else{
printf("INVALID CHOICE");}
printf("Total percentage: %f", total_percentage);
return 0; }