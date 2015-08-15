#include <stdio.h>
int main (){
  int name,address;
  FILE *fp = fopen("address.csv","w");

  while((name = getchar()) != '\n'){
  putc (name,fp);
  }
  putc('\n',fp);
 
  while((address = getchar()) != '\n'){
    putc (address,fp);
  }
  putc('\n',fp);
  fclose(fp);
  return 0;
}
