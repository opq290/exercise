#include <stdio.h>
#include <string.h>

#define LENBUF  (150000)
#define NofWRD  (25000)
#define NSHOW   (15)

char allocbuf[LENBUF];
char *allocp = allocbuf;

void bubble( char *wrdptr[], int N )
{
  int i, j;
  char *ptr;
 for ( i = 0 ; i < N-1 ; i++ ) {
    for ( j = N-1 ; j > i ; j-- ) {

      if(strcmp(wrdptr[j-1],wrdptr[j]) > 0){
	ptr =wrdptr[j];
	wrdptr[j] = wrdptr[j-1];
	wrdptr[j-1] = ptr;
      }

    }
  }
  // バブルソートを使って，wrdptr[] を昇順に並び替える
  // Sort wrdptr[] in ascending order using "bubble
  // sort" algorithm.
}





int main( void )
{
  int c, type,in, nwrd, i,j,sum;
  char *wrdptr[NofWRD];
  char *word[NofWRD];
  int time[NofWRD];
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
  bubble (wrdptr,nwrd);

  
  for(j = 0; j <NofWRD-1;j++ ){
  time[j] = 0;
  }
  j = 0;
  word[0] = wrdptr[0];
  for (i = 0; i< nwrd &&(wrdptr[i] != NULL);i++){
    if (strcmp(word[j],wrdptr[i])== 0){
      time[j] += 1;
    }
    else{
      j += 1;
      word[j] = wrdptr[i];
      time[j] +=1;
    }
    
  }
  for (i = 0; i <nwrd-1 && (word[i] != NULL);i++){
    printf ("%s : %d\n",word[i],time[i]);
  }
  sum =0;
  for (i = 0; i <nwrd-1 && (word[i] != NULL);i++){ /*確認のため単語の総数を求めた*/
    sum = sum + time[i];
  }
  printf ("%d\n",sum);
      
  
}
