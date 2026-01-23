#include<stdio.h>
#include<conio.h>
void namaste();
void bonjour();
int main(){
printf("Enter F for french and enter I for indian\n");
char ch;
scanf("%c", & ch);
if(ch=='i'){
 namaste();}
else{
  bonjour();}

       return 0 ;
       }
       void namaste(){
       printf("namaste\n");}
       void bonjour(){
       printf("bonjour");}