#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readPolynome(FILE *f, int *tab){
  int deg;
  fscanf(f,"%d",&deg);
  tab=(int *)malloc(int*(deg+1));
  printf("Polynome de degre: %d\n",deg);
  tab[0]=deg;
  for(int i=1;i<=deg;i++){
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
  int poly[];
  readPolynome(f,poly);
  fclose(f);
  return 0;
}
