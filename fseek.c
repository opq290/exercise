// 学籍番号　141168G
//氏名　　セキ　キンヨウ

#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *fp = fopen("news.txt","rb");
  int count = 0;
  char s;
  while(fseek(fp, -(count+1)*sizeof(char), SEEK_END) == 0){
    fread( &s, sizeof(char), 1, fp);
    printf("%c",s);
    count++;
  }
  fclose(fp);
  return 0;
}
    
    
