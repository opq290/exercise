#include <stdio.h>

int getdays (int,int,int);
main(){
  int year = 2012;
  int month = 11;
  int day = 2;
  int totaldays, i;
  
  totaldays = getdays(year,month,day);
  i = totaldays % 7;
  switch (i){
    case 0:
    printf ("%d-%d-%d is a Monday\n",year,month,day);
    break;
    case 1:
    printf ("%d-%d-%d is a Tuesday\n",year,month,day);
    break;
    case 2:
    printf ("%d-%d-%d is a Wednesday\n",year,month,day);
    break;
     case 3:
    printf ("%d-%d-%d is a Thursday\n",year,month,day);
    break;
     case 4:
    printf ("%d-%d-%d is a Friday\n",year,month,day);
    break;
     case 5:
    printf ("%d-%d-%d is a Saturday\n",year,month,day);
    break;
     case 6:
    printf ("%d-%d-%d is a Sunday\n",year,month,day);
    break;
    
  }
  printf ("%d\n", totaldays);
  return 1;
}

int getdays(int year, int month, int day){
  int sum;
  int leap,i;
  int monthlength[12]; /*month i の日数をmonthlength[i-1]に格納する。*/
  sum =0;

  for (i= 2001;i < year;i++){
  if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
    sum += 366;
  }
  else{
   sum +=365;
  }
  }
  
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
    leap = 1;
  }
  else{
    leap =0;
  }
  
 monthlength[0]=31;
 monthlength[1]=28 +leap;
 monthlength[2]=31;  
 monthlength[3]=30;
 monthlength[4]=31;
 monthlength[5]=30;
 monthlength[6]=31;
 monthlength[7]=31;
 monthlength[8]=30;
 monthlength[9]=31;
 monthlength[10]=30;
 monthlength[11]=31;
  for (i=0; i < month-1; i++){
    sum += monthlength[i];
  }
  sum += (day-1);
  return sum;
}
