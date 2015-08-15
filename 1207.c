#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WORD{
  char wstr[1000];
  int freq;
  struct WORD *next;
};
 

  int main(){
    FILE *fp;
    fp = fopen("news.txt","r");
    struct WORD first = {" ",0,NULL};
    struct WORD *current = &first;
    
    int state,c;
    int currentchar = 0;
    char buffer[1000];
   
    
    while ((c = getc(fp)) != EOF){
      if ((c == ' ')||(c == '\t')||(c == '\n')){
	buffer[currentchar] = '\0';
	currentchar = 0;
        state = 0;
   	for(current = &first; current->next != NULL; current = current->next){
	 if (strcmp(current->wstr , buffer) == 0){
	   current->freq ++;
	   state =1;
	   break;
  	 }

	}
        if (state == 0){
	  current->next =(struct WORD *)malloc(sizeof(struct WORD));
	  current =current->next;
	  strcpy(current->wstr,buffer);
	  current->freq = 1;
	  current->next = NULL;
	}
      }	
	 
      else{
	buffer[currentchar] = c;
	currentchar++;
      }
      
     }   
    

    int max;
    char maxword[1000];
    max = 0;
    strcpy(maxword, " ");
    for(current = &first; current->next != NULL; current = current->next){
      if((current->freq) > max){
	max = current->freq;
	strcpy(	maxword, current->wstr);
      }
     }   
    printf("%s   %d\n",maxword,max );
    
    
    return 0;
  }
