#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
main(int argc, char *argv[]){
  int length = 0;
  int c;
  float inputnumber[length];
  int i = 0;
  char *token;

  while((c = getopt( argc, argv, "n:s:")) != -1){
    switch(c){
    case 'n':
      length = atoi(optarg);
      printf ("length of array = %d\n",length);
      break;
    case 's':
      token = strtok(optarg,",");
      while ( token != NULL){
	printf("%s\n",token);
	inputnumber[i] = atof(token);
	printf("%f\n",inputnumber[i]);
	token = strtok(NULL,",");
	i ++;
      }
      break;
    }
  }
  printf("%d\n",i);
  printf ("The array is: \n");
  for (i =0; i <length; i++){
  printf (" %f",inputnumber[i]);
  }
  printf("\n");
 }   
