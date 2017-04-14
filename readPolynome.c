#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readPolynome(FILE *f, int tab[], int deg){
  printf("Polynome de degre: %d\n",deg);
  int i;
  for(i=0;i<=deg;i++){
    fscanf(f,"%d",&tab[i]);
  }
  printf("\n");
}

double evaluePolynome(int tab[],int deg,double x){
  double res;
  int i;
  for(i=0;i<=deg;i++){
    res+=tab[i]*pow(x,(double)i);
  }
  return res;
}

int evaluePolynomeZp(int tab[],int deg,int x,int p){
  int res;
  int i;
  for(i=0;i<=deg;i++){
    res+=tab[i]*pow((double)x,(double)i);
  }
  return res%p;
}

int main(int argc, char const *argv[]) {
  FILE *f=fopen("degPoly.txt","r+");
  if(f==NULL){
    printf("ERROR\n");
  }
  int deg;
  fscanf(f,"%d",&deg);
  int poly[deg+1];
  readPolynome(f,poly,deg);
  printf("%lf\n",evaluePolynome(poly,deg,-1.5));
  printf("%d\n",evaluePolynomeZp(poly,deg,1,5));
  return 0;
}
