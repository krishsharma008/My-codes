#include <stdio.h>
// This system control the leap year 
int isleap(int year){
if(year%400==0)return 1;
if(year%100==0) return 0;
if(year%4==0) return 1;
return 0;
          }
// change days in month
int daysinmonth(int month, int year){
if(month==2) return isleap(year)?28:29;
if(month==4||month==6||month==9||month==11) return 30;
return 31; 
          }
// calculate first day of the month 
int firstday( int month, int year){
int d=1;
if(month<3){
 month+=12;
 year--;}
           int k = year % 100;
    int j = year / 100;

    int f = d + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    return (f + 6) % 7;}// convert sunday=0
    // Main function 
int main(){
int month, year;
printf("Enter the month(1-12): ");
scanf("%d",&month);
printf("Enter the year: ");
scanf("%d",&year);
if(month<1||month>12||year<=0){
printf("INVALID CHOICE\n");
return 0;}
int startday=firstday(month , year);
int days= daysinmonth(month,year);
printf("\nSun Mon Tue Wed Thr Fri Sat\n");
for(int i=0; i<startday; i++)
   printf("    ");
for(int d=1; d<=days; d++){
   printf("%3d ", d);
    if((d+startday)%7==0)
    printf("\n");}
     printf("\n");
       return 0;
       }
   