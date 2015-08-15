//学籍番号　141168G
//氏名　　石　欣洋

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct NODE{
  double x;
  double y;
};
struct NODE points[1000];


int main(){

  FILE *fp = fopen("points.bin","wb");
  int i;
  double r;
  for(i = 0; i < 1000; i++){
    r =(double)rand()/(double)RAND_MAX;
    points[i].x =(double)sqrt(3.0)*2*r-(double)sqrt(3.0) ;
    points[i].y =(double)sqrt(5.0)*2*r-(double)sqrt(5.0) ;
  }

  fwrite(points,sizeof(struct NODE), 1000,fp);
  fclose(fp);
  return 0;
}
