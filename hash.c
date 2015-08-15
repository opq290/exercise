//学籍番号　141168G
//氏名　   セキ　キンヨウ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nlist *cityptr;

#define BUFSIZE 1000
#define HASHSIZE 101
unsigned hash(char *s);
static cityptr hashtab[HASHSIZE];
typedef struct nlist{
  cityptr next;
  char name[100];
  int popu;
 } citydata;

int main(){
  int c;
  char key[100];
  int currentchar = 0;
  citydata first = {NULL," ",0};
  cityptr current = &first;
  /* while((c = getchar()) != EOF){
   key[currentchar] = c;
   currentchar++;
   }*/
 char buf[BUFSIZE];
 FILE *fp;
 fp = fopen("cities.csv","r");
 while(fgets(buf, BUFSIZE,fp)){
 char *s1 = strtok(buf, ",");
 char *s2 = strtok(NULL, ",");
 current->popu = atoi(s2);
 strcpy(current->name,s1);
  printf("%s\n",current->name);
 current->next = (cityptr) malloc(sizeof(citydata));
 current = current->next;
 current ->popu = 0;
 strcpy(current->name," ");
 current->next = NULL;
 }
 for (current = &first; current->next != NULL; current = current->next){
   printf("name =%s, %d\n", current->name,current->popu);
 }
 
  return 0;
}


cityptr install(char *name){
  cityptr np;
  unsigned hashval;
  if((np = find(name)) == NULL){
  np = (cityptr) malloc(sizeof(citydata));
  hashval = hash(name);
  np->next = hashtab[hashval];
  hashtab[hashval] = np;
  }
  else
    hashtab[hashval]->next = np;
 }


cityptr find(char*s){
  cityptr np;
  for (np = hashtab[hash(s)]; np != NULL; np= np->next){
    if(strcmp(s,np->name) == 0)
      reutrn np;
    else
      return NULL
	}
  
}

unsigned hash(char *s){
  unsigned hashval;
  for(hashval = 0; *s != '\0'; s++)
    hashval = *s + (31 * hashval);
  return hashval % HASHSIZE;
}
