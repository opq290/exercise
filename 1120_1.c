#include <stdio.h>
#include <stdlib.h>
int main(void){
int *p;
p = (int *) malloc(sizeof(int));
*p = 235;
return 0;
}
