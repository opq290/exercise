//学籍番号　141168G
//氏名　　　石　欣洋


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

struct NODE{
  double x;
  double y;
};



int main(){
  FILE *fp = fopen("points.bin", "rb");
  struct NODE points[MAX];
  fread(points, sizeof(struct NODE),1000,fp);
  int i;
  for(i = 0; i < 1000; i++){
    if(points[i].x > 0 && points[i].y > 0){
      printf("x = %f, y = %f\n", points[i].x, points[i].y);
    }
  }
  fclose(fp);
  return 0;
}
