#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  FILE *fp;
  fp = fopen("O3decompose.dat0.", "w");
  unsigned seed;
  seed = time(NULL);
  srand(seed);
  int i = 0;
  int k = 0;
  double c[6];
  double k1 = 9.3 * 1000;
  double k_1 = 7.4 * 100;
  double k2 = 3.15 * 1000;
  double k_2 = 1.44 * 10000;
  double k3 = 0.75 * 0.1;
  double k4 = 4.2 * 100000000;
  double kt;
  double u1, u2;
  double t = 0;
  double o3 = 55.2;
  double o3_ = 0, zno, o_ = 0, o2 = 0, h2o = 55.5 * pow(10, 6), h2o2 = 0;
  scanf("%lf", &zno);
  zno = zno / 81.38 * pow(10, 3);
  double kt_c, s;
  fprintf(fp, "MC step, time(s),        [O3](uM)\n");
  while (t < 30) {
    c[0] = o3 * zno * k1;
    c[1] = o3_ * k_1;
    c[2] = o3_ * k2;
    c[3] = o2 * o_ * k_2;
    c[4] = h2o * o_ * k3;
    c[5] = h2o2 * k4;
    if (o3<1){
      c[0]=0;}
    if (o3_<1){
      c[1]=0;
      c[2]=0;}
    if (o2<1 || o_<1){
      c[3]=0;}
    if (h2o<1 || o_<1){
      c[4]=0;}
    if (h2o2<1){
      c[5]=0;}
    u1 = (double)rand() / RAND_MAX * 1;
    kt = c[0] + c[1] + c[2] + c[3] + c[4] + c[5];
    kt_c = u1 * kt;
    c[1] = c[0] + c[1];
    c[2] = c[1] + c[2];
    c[3] = c[2] + c[3];
    c[4] = c[3] + c[4];
    c[5] = c[4] + c[5];
    if (kt_c < c[0]) {
      o3 = o3 - 1;
      zno = zno - 1;
      o3_ = o3_ + 1;
    } else if (kt_c <= c[1] && kt_c > c[0]) {
      o3 = o3 + 1;
      zno = zno + 1;
      o3_ = o3_ - 1;
    } else if (kt_c <= c[2] && kt_c > c[1]) {
      o3_ = o3_ - 1;
      o_ = o_ + 1;
      o2 = o2 + 1;
    } else if (kt_c <= c[3] && kt_c > c[2]) {
      o3_ = o3_ + 1;
      o_ = o_ - 1;
      o2 = o2 - 1;
    } else if (kt_c <= c[4] && kt_c > c[3]) {
      o_ = o_ - 1;
      h2o = h2o - 1;
      h2o2 = h2o2 + 1;
    } else {
      h2o2 = h2o2 - 1;
      zno = zno + 1;
    }
    u2 = (double)rand() / RAND_MAX * 1;
    t = t + (log(1 / u2) / kt);
    s = t * 60;
    i++;
    if (i%100==0){
    fprintf(fp, "%d,     %lf ,     %lf\n", i, s, o3);
    printf("times %d , time=%lf (s) , M=%lf (uM)\n", i, s, o3);}
  }
  fclose(fp);
  return 0;
}