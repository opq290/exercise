#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct NODE{
  float x;
  float y;
};
struct NODE points[1000];
void genrate_points(){
  int i;
  double r;
  for(i = 0; i < 1000; i++){
    r = rand()/RAND_MAX * 2 * M_PI;
    points[i].x = sqrt(3) * cos(r);
    points[i].y = sqrt(5) * sin(r);
  }
}




int main(){
  FILE *fp = fopen("points.bin","wb");
  fwrite(points,sizeof(struct NODE), 1000,fp);
  fclose(fp);
  return 0;
}
