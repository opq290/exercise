# include <stdio.h>

int power2(int n);
int i;

main(){
   for (i= 0; i <= 20; ++i ){
    printf("%d\t%d\n",i,power2(i)); }
      return 0;
}

int power2(int n)
{
  int i, p;
  p = 1;
  for (i=1; i <= n; ++i){
    p=p*2;}
    return p;
  }
    

