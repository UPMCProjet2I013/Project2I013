#include <stdio.h>
#include "fmpq_poly.h"
#include "nmod_poly.h"


//mp_limb_t : unsigned int
//mp_ptr : tab de mp_limb_t
//mp_srcptr : tab de mp_limb_t const

void interpolatePolynomeQ(int *x, int *y, int deg, int nb_val,fmpq_poly_t *poly){
	int i;
	fmpq_poly_t poly2;
	fmpz *xs,*ys;
	xs=_fmpz_vec_init(nb_val);
	ys=_fmpz_vec_init(nb_val);
	for(i=0;i<nb_val;i++){
		fmpz_set_si(xs+i,x[i]);
		fmpz_set_si(ys+i,y[i]);
	}

	fmpq_poly_interpolate_fmpz_vec(poly2,xs,ys,deg);
	*poly=poly2;

	//return poly; faut il clear les variables xs et ys à la fin ?
}

/*Version avec nmod*/
void interpolatePolmod(int *xs, int *ys, int len, int m){
	mp_ptr poly=_nmod_vec_init(len);//initialise un vecteur de longueur n
	_nmod_vec_set(xs, , slong len);
	nmod_t mod;
	nmod_init(mod, m);
	_nmod_poly_interpolate_nmod_vec(poly ,xs, ys , len, mod);
	//return poly;
}



int main(int argc, char const *argv[]) {
	fmpq_poly_t x;
	mp_ptr xm;
	int n=3;
	int k=5;
	int xs[]={1,2,3,4,5};
	int ys[]={2,4,6,8,10};
	interpolatePolynomeQ(xs, ys, n, k,&x);
	interpolatePolmod(xs,ys, k, 5);
	fmpq_poly_print(x); flint_printf("\n");
	fmpq_poly_clear(x);
	_nmod_vec_clear(xm);
	return 0;
}
