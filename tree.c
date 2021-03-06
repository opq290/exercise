#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct NODE *nodeptr;

typedef struct NODE{
  int val;
  nodeptr left;
  nodeptr right;
} node;

void insertnode(nodeptr root,int data){
  node first = {0,NULL,NULL};
  nodeptr current = &first;
 
    if(data > root->val){
      current = root->right;
      if(current == NULL){
	current =(nodeptr)malloc(sizeof(node));
	current->val = data;
	current->right = NULL;
	current->left = NULL;
	root->right =current;
      }
      else{
	insertnode(current,data);
      }
    }
    else{
      current = root->left;
      if(current == NULL){
	 current =(nodeptr)malloc(sizeof(node));
	 current->val = data;
	 current->left = NULL;
	 current->right =NULL;
	 root ->left = current;
      }
      else{
	insertnode (current,data);
      }
    }
}

void lftraversal(nodeptr root){
  nodeptr current = root;
  while(current->left != NULL){
    current= current->left;
 }
}

main(){
  nodeptr root;
  nodeptr current;
  node first = {0,NULL,NULL};
  root = &first;
  FILE *fp = fopen("./numbers.txt","r");
  if(!fp){
    printf("Failed to open the file\n");
    exit(1);
  }
  char buf[MAX_LEN];
  int i = 0;
  while(fgets(buf,MAX_LEN,fp)){
    int data = atoi(strtok(buf,"\n"));
    i ++;
    if (i == 1){
      root->val = data;
    }
    insertnode(root,data);
  }
  for(current = root; current->right != NULL; current =current->right){
    printf("%d\n",current->val); 
 }

}
