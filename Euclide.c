#include <stdio.h>
#include "fmpz_poly.h"
#include "nmod_poly.h"

void remplirPolynome(int *poly,fmpz_poly_t *x){
	int i;
	for(i=0;i<=poly[0];i++){
		if(poly[i+1]!=0) fmpz_poly_set_coeff_ui(*x, i, poly[i+1]);
	}
}

void euclideRest(int *polyA,int lenA,int *polyB,int lenB,fmpz_poly_t *r0,fmpz_poly_t *r1){
  fmpz_poly_t A;
  fmpz_poly_t B;
  fmpz_poly_init(A);
  fmpz_poly_init(B);
  fmpz_poly_t tmp;
  fmpz_poly_init(tmp);
  remplirPolynome(polyA,&A);
  remplirPolynome(polyB,&B);
  fmpz_poly_rem(*r0,A,B);
  fmpz_poly_rem(*r1,B,*r0);
  int n=lenB-2;
  while(n-1!=0){
    fmpz_poly_rem(tmp,*r0,*r1);
    fmpz_poly_set_trunc(*r0,*r1,n);
    fmpz_poly_set_trunc(*r1,tmp,n-1);
    n--;
  }
}

int main(int argc, char const *argv[]) {
	int polyA[]={7,3,4,5,8,6,10};
  int polyB[]={2,1,3,8,6,5};

  fmpz_poly_t r0;
  fmpz_poly_t r1;
  fmpz_poly_init(r0);
  fmpz_poly_init(r1);
  euclideRest(polyA,7,polyB,6,&r0,&r1);
  flint_printf("r1");
  flint_printf("\n");
  fmpz_poly_print(r1);
  flint_printf("\n");
  flint_printf("r0");
  flint_printf("\n");
  fmpz_poly_print(r0);
  flint_printf("\n");
	return 0;
}
