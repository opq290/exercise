#include <stdio.h>
int main(){
  int c;
  FILE *fp = fopen("address.csv","a");
  if(!fp){
    printf("File open failed\n");
    return 1;
  }
  while((c = getchar()) != EOF){
    putc (c, fp);
  }

  fclose(fp);
  return 0;
}
  
