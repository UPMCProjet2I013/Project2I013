#include <stdio.h>
#include "fmpq_poly.h"
#include "nmod_poly.h"


//mp_limb_t : unsigned int
//mp_ptr : tab de mp_limb_t
//mp_srcptr : tab de mp_limb_t const

void interpolatePolynomeQ(int *x, int *y, int n,fmpq_poly_t *poly){
	int i;
	fmpz *xs,*ys;
	xs=_fmpz_vec_init(n);
	ys=_fmpz_vec_init(n);
	for(i=0;i<n;i++){
		fmpz_set_si(xs+i,x[i]);
		fmpz_set_si(ys+i,y[i]);
	}
	printf("avant appel\n" );
	fmpz_print (xs+3) ;
	flint_printf ( " \n " ) ;
	fmpq_poly_interpolate_fmpz_vec(*poly,xs,ys,n-1);
}

/*Version avec nmod*/
void interpolatePolmod(int *xs, int *ys, int len, int m,mp_ptr *poly){
	//mp_ptr poly=_nmod_vec_init(len);initialise un vecteur de longueur n
	//_nmod_vec_set(*poly,(mp_srcptr)xs,len);
	nmod_t mod;
	nmod_init(&mod, m);
	_nmod_poly_interpolate_nmod_vec(*poly,(mp_srcptr)xs,(mp_srcptr)ys,len,mod);
	//return poly;
}



int main(int argc, char const *argv[]) {
	fmpq_poly_t x;
	int n=4;
	int xs[]={0,1,2,3};
	int ys[]={2,2,4,8};
	//mp_ptr poly=_nmod_vec_init(n);
	printf("main\n" );
	interpolatePolynomeQ(xs, ys, n,&x);
	//interpolatePolmod(xs,ys,n,11,&poly);
	fmpq_poly_print(x); flint_printf("\n");
	//fmpq_poly_print((fmpq_poly_struct)poly); flint_printf("\n");
	fmpq_poly_clear(x);
	//nmod_vec_clear(poly);
	return 0;
}
