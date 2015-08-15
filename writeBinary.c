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
    r = rand()/RAND_MAX;
    points[i].x = sqrt(3.0)*r-2*sqrt(3.0) ;
    points[i].y = sqrt(5.0)*r-2*sqrt(5.0) ;
  }

  fwrite(points,sizeof(struct NODE), 1000,fp);
  fclose(fp);
  return 0;
}
