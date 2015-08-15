#include <stdio.h>
#include<string.h>
#define LENBUF  (150000)
#define NofWRD  (25000)
#define NSHOW   (15)

char allocbuf[LENBUF];
char *allocp = allocbuf;
int main( void )
{
  int c, type,in, nwrd, i,j,p;
  char *wrdptr[NofWRD];
  char *word[NofWRD];
  int  time[NofWRD];
  nwrd =0;
  in =0;
  type = 1;
  for(i=0; i < LENBUF-1 && ( c = getchar()) != EOF;i++){
    if (c == ' '|| c == '\t' || c == '\n'){
      allocbuf[i] = '\0'; 
      allocp += type;
      in = 0;
    }
    else if(in == 0){
      in = 1;
      strcpy(allocp, allocbuf);
      allocbuf[i] = c;
      allocp += type;
      wrdptr[nwrd++] = (allocp-1);
       
      }
    else{
      allocbuf[i] = c;
      allocp +=type;
    }
  }
  allocbuf[i] = '\0';
  word[0] = wrdptr[0];
  
  for(j = 0; j <NofWRD-1;j++ ){
  time[j] = 0;
  }
  
  j = 0;
 
  for (i=0; i<NofWRD-1 && (wrdptr[i] != NULL);i ++){
    for (j = 0; j < p; j++){
    if( strcmp(word[j],wrdptr[i]) == 0){
      time[j] += 1;
    }
    else{
      j += 1;
      p += 1;
      word[j] = wrdptr[i];
	}
      
   }

  }
  for(i = 0; i <15; i++){
printf ("%s\t%d\n",word[i],time[i]);
  }
}
      
