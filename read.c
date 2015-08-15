#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

struct NODE{
  float x;
  float y;
};



int main(){
  FILE *fp = fopen("points.bin", "rb");
  struct NODE result[MAX];
  fread(result, sizeof(struct NODE),1000,fp);
  int i;
  for(i = 0; i < 1000; i++){
    if(result[i].x > 0 && result[i].y > 0){
      printf("x = %f, y = %f\n", result[i].x, result[i].y);
    }
  }
  fclose(fp);
  return 0;
}
