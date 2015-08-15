//学籍番号　141168G
//氏名　　　セキ　キンヨウ


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct NODE *nodeptr;

typedef struct NODE{
  int val;
  nodeptr left;
  nodeptr right;
  nodeptr parent;
} node;

void insertnode(nodeptr root,int data){
  node first = {0,NULL,NULL,NULL};
  nodeptr current = &first;
 
    if(data > root->val){
      current = root->right;
      if(current == NULL){
	current =(nodeptr)malloc(sizeof(node));
	current->val = data;
	current->right = NULL;
	current->left = NULL;
	current->parent = root;
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
	 current->parent =root;
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
  printf("%d\n",current->val);

   if( current->right != NULL){
     if(current->parent != NULL){
    nodeptr np = current->parent; 
    current = current->right;
    current->parent = np;
    (current->parent)->left = current;
  }
    else{
      current =current->right;
      current->parent = NULL;
     }
   }
   else if(current->parent != NULL){
  current = current->parent;
  current->left = NULL;
  }

 if(current->right != NULL || current->parent != NULL){
  lftraversal(current);
  }
 else{
   printf("end\n");
 }
}


main(){
  nodeptr root;
  nodeptr current;
  node first = {0,NULL,NULL,NULL};
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
  fclose(fp);

  lftraversal(root);
  return 0;
}
