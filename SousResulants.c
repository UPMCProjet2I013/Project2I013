//Calcul de la suite des sous résultants

#include <stdio.h>
#include "fmpq_poly.h"
#include "nmod_poly.h"

void sousResultant(int *polyA, int *polyB, int *res){
        fmpq_poly_t A1;
        fmpq_poly_t A2;
        fmpq_poly_init(A1);
        fmpq_poly_init(A2);
        fmpq_poly_t A3;
        fmpq_poly_init(A3);
        remplirPolynome(polyA,&A1);
        remplirPolynome(polyB,&A2);
        fmpq R=1;
        int i=2;
        int n=len
        while (
                        
                        
                        
                
                
                //div euclidienne : void  fmpq_poly_rem(fmpq_poly_t R, const  fmpq_poly_t  poly1 , const  fmpq_poly_t  poly2)
                //deg polynome : slong fmpq_poly_degree(const fmpq_poly_t poly)  "slong=int" -->27.3
                //recup enieme coeff : void  fmpq_poly_get_coeff_fmpq(fmpq_t x, const  fmpq_poly_t poly , slong n) Retrieves the nth coefficient of poly, in lowest terms -->27.7
               //test poly nul : int  fmpq_poly_is_zero(const  fmpq_poly_t  poly) Returns 1 if poly is the zero polynomial, otherwise returns 0.
