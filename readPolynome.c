#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readPolynome(FILE *f, int tab[], int deg){
  printf("Polynome de degre: %d\n",deg);
  for(int i=0;i<deg;i++){
    fscanf(f,"%d",&tab[i]);
  }
  printf("\n");
}

double evaluePolynome(int tab[],int deg,double x){
  double res;
  for(int i=0;i<deg;i++){
    res+=tab[i]*pow(x,(double)i);
  }
  return res;
}

int main(int argc, char const *argv[]) {
  FILE *f=fopen("degPoly.txt","r+");
  if(f==NULL){
    printf("ERROR\n");
  }
  int deg;
  fscanf(f,"%d",&deg);
  int poly[deg];
  readPolynome(f,poly,deg);
  fclose(f);
  return 0;
}
