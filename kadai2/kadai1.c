# include <stdio.h>

 double gyaku( int n);
int i;
main()
{
  for (i= 1; i <= 20; ++i ){
    printf("%d\t%.3f\n",i,gyaku(i)); }
      return 0;
 }
double gyaku( int n)
{
   double p;
  p = 1.0 /n;
  return p;
}
