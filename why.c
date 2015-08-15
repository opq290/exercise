// 学年　２年
//学籍番号　141168G
//氏名　　セキ　キンヨウ


//家でのcompilerで何のerror messageも出てなくてちゃんと実行できますけど、学校のcompilerでsegmentation faultが出るの原因は分かりません。

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_LEN 1000
#define EOSET -1   //集合の終わりの印

typedef struct DOCUMENT *fileptr;
typedef  struct DOCUMENT{
  int id;
  char * body;
  fileptr next;
} document;


typedef struct InvertedIndex *invertedptr;
typedef struct InvertedIndex{
  char *word;
  int *location;
  int freq;
  invertedptr next;
}invertedindex;

document first ={0,NULL,NULL};
invertedindex first2 = {NULL,NULL,0,NULL};



int * find(char *key){  //ある単語のidの集合を探す関数
  int * result; 
  invertedptr current;
  int state = 0;
  int i;
  for(current = &first2; current->next != NULL; current = current->next){
   
    if(current->word != NULL){
     if(strcmp(current->word, key)== 0){
	state = 1;
	result = (int *)malloc(sizeof(int)*(current->freq + 1));
	for(i = 0; i < current->freq; i++){
	result[i]= current->location[i];
	}
	result[i] =EOSET;
	break;
      }
    }
  }
    if(state == 0){
      result = NULL;
    }
    return result;
 }

int * and_find(int *p, int *q){  //二つの集合の積集合を求める関数
  int i, j, state;
  int *result;
  int k = 0;
  int length = 0;
  if(p != NULL && q != NULL){
  while( p[length] != EOSET ){
    length++; 
  }
  state = 0;
  result = (int *)malloc(sizeof(int)*(length+1));
  for(i = 0; p[i] != EOSET; i++){
    for(j = 0; q[j] != EOSET; j++){
      if(p[i] == q[j]){
	result[k] = q[j];
	k++;
	state = 1;
	break;
      }
    }
  }
  result[k] = EOSET;
  if(state == 0)
    result = NULL;
  } 
  else{
    result = NULL;
  }
  return result;
  free(result);
}


int main(int argc, char *argv[]){
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

  document first = {0, NULL,NULL};
  fileptr current = &first;
  FILE *fp = fopen(FileName,"r");
  char buf[MAX_LEN];
  int line = 0;

   while(fgets(buf,MAX_LEN,fp) != NULL){
    
    current->id = line;
    current->body = (char *) malloc(sizeof(char) * (strlen(buf)+1));
     strcpy(current->body,buf);
     current->body[strlen(buf)-1] = '\0'; // 行末の'\n'を削除する
     current->next = (fileptr) malloc(sizeof(document));
     current = current->next;
      current->id = 0;
     current->body = NULL;
     current->next = NULL;
     line++;
  }
 
  fclose(fp);
 
  

  int i;
  int state;
 
  char *tab[line]; //strtokで文を単語に分割する前に文を保存する
  current = &first;
  for(i = 0; i <line; i++){
    tab[i] = (char *)malloc(MAX_LEN * sizeof(char));
    strcpy(tab[i], current->body);
    current = current->next;
  }

  invertedptr current2 = &first2;
  for(current = &first; current->next != NULL; current =current->next){
    char *token = strtok(current->body," ");
   
    while(token != NULL){
      state =0; 
      
    for(current2 = &first2; current2->next != NULL; current2 = current2->next){
      if(state == 1)
	break;
      if(current2->word != NULL){
      if(strcmp(token,current2->word)== 0){
         int tmp[current2->freq];
	
	for(i = 0; i < current2->freq; i++){
	  tmp[i]= *(current2->location + i);
	}
        current2->location =(int *) malloc((current2->freq + 2)*sizeof(int));
        for(i = 0; i < current2->freq; i++ ){
	 *( current2->location +i) = tmp[i];
	}
        *(current2->location + current2->freq) = current->id;
	*(current2->location + current2->freq + 1) = EOSET;
        state = 1;
      (current2->freq)++;
     break;
       }
      }
     
    }
    
    if(state == 0){
	current2->next =(invertedptr)malloc(sizeof(invertedindex));
	current2 = current2->next;
	current2->word = (char*)malloc(strlen(token));
	strcpy(current2->word,token);
	current2->location = (int*)malloc(sizeof(int)*2);
	*(current2->location) = current->id;
	*(current2->location + 1) = EOSET;
	(current2->freq) = 1;
	current2->next = NULL;
      }
     token = strtok(NULL," ");
    }
  }
  int nwrd = 0;
  for(current2 = &first2; current2->next != NULL; current2 = current2->next){
    nwrd += current2->freq;
  }
  nwrd += current2->freq;
  printf("Total number of words in the file = %d\n",nwrd);
  printf("Total number of documents read = %d\n", line);
  printf("Enter Query\n");

  char query[MAX_LEN];
  char *key;
  int *np;
  int *nq;
  fgets(query,MAX_LEN,stdin);
  query[strlen(query)-1] = '\0';  //行末の'\n'を削除する
  while( query != NULL){
  key = strtok(query, " ");
  
  nq = find(key);
  while(key != NULL){
    np = find(key);
    nq = and_find(nq,np);
    key = strtok(NULL, " ");
    
  }
  if (nq == NULL){
    printf("NOT FOUND!\n");
  }
  else{
    int now = EOSET;
  for(i = 0; nq[i] != EOSET; i++){
    if(nq[i] != now){
    printf("%d: %s\n",nq[i], tab[nq[i]]);
    now = nq[i];
    }
  }
  }
  printf("Enter Query\n");
  fgets(query,MAX_LEN,stdin);
  query[strlen(query)-1] = '\0';
  } 
  return 0; 
}
