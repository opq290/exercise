#include <stdio.h>
#define MAXLEN 100
int main(){
  FILE *fp = fopen("address.csv", "r");
  char buffer[MAXLEN] ;
  if (!fp){
    printf("Failed to open the file!\n");
    return 1;
  }
  while (fgets(buffer,MAXLEN,fp)){
    printf("%s",buffer);
  }
  fclose(fp);
  return 0;
}


