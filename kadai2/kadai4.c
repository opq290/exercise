#include <stdio.h>
#define ODD  0
#define EVEN 1


main(){

  int c,state;
  state= EVEN;
  while ((c = getchar()) != EOF) {
    if (state ==EVEN) {
      state = ODD;}
    else if (state == ODD) {
      state = EVEN;
      putchar(c) ;}
  }
}

    
  
