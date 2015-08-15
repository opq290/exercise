#include <stdio.h>
long factorial(int n);
int i;
main(){
   for (i= 0; i <= 20; ++i ){
    printf("%d\t%ld\n",i,factorial(i)); }
      return 0;
}

long factorial(int n ){
  int i;
  long p;
    p = 1;
    for (i=1; i <= n; ++i){
	p=p*i;}
  return p;
}
    

