#include <stdio.h>
#define FIRST 0
#define OTHER 1
#define LAST 2


main(){
  int c,p,state;
  state = LAST;
 
  while( (c=getchar()) != EOF){
   

    if (state == LAST){
      if (c == ' ' || c == '\t' || c == '\n'){
	state = LAST;}
      else 
	state = FIRST;
      putchar(c);}
    else if (state == FIRST){
      if (c == ' ' || c == '\t'){
	state = OTHER;}
      else if (c == '\n'){
	state = LAST;}
      else {
	state = FIRST;
	putchar(c);
       }
    }
    else if (state == OTHER){
      if (c =='\n'){
	state = LAST;}
      else
        state = OTHER;
    }
 
  }


}

	  
	  
    










      

      
    
