#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 main(int argc, char *argv[]){
  int length = 0;
  float inputnumber[length];
  int counter;
  int i;
  char *token;
  i =0;
 
  for (counter = 0; counter < argc; counter ++){
    switch(*++argv[counter]){
    case 'n':
      length = atoi(argv[counter+1]);
      printf ("length of array = %d\n",length);
      break;
    case 's':
      token = strtok(argv[counter+1],",");
      while (token != NULL){
	inputnumber[i] = atof(token);
	token = strtok(NULL,",");
	i ++;
      }
       break;
		       }
    }
  printf ("The array is: \n");
  for (i =0; i <length; i ++)
  printf (" %f ",inputnumber[i]);
  printf ("\n");

 }
 
      
