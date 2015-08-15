
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_LEN 1000

main(int argc, char *argv[]){
  char * FileName;
  int c;
 
  while((c = getopt(argc, argv, "f:h")) != -1){  // ./a.out -f(filename)でファイル名を指定する
    switch(c){
    case 'f' :
      FileName = optarg;
      break;
    case 'h':
      printf("myprogram -f FileName -h(help message)\n");
      break;
    }
  }
   FILE *fp = fopen(FileName,"r");
  char buf[MAX_LEN];
  int line = 0;
  while(fgets(buf,1000,fp)){
    printf("%s\n",buf);
  }
}
