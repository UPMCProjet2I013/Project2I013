//Calcul de la suite des sous résultants

#include <stdio.h>
#include <math.h>
#include "fmpq_poly.h"
#include "nmod_poly.h"

void remplirPolynomeQ(int *poly,fmpq_poly_t *p){
        fmpz_poly_t x;
        fmpz_poly_init(x);
        int i;
        for(i=0;i<=poly[0];i++){
                if(poly[i+1]!=0) fmpz_poly_set_coeff_ui(x, i, poly[i+1]);
        }
        fmpq_poly_set_fmpz_poly(*p,x);
}

void sousResultant(fmpq_poly_t *A1, fmpq_poly_t *A2, fmpq_t *res){
        fmpq_poly_t A3;
        fmpq_poly_init(A3);
        fmpq_t coeff;
        fmpq_init(coeff);
        slong aux1,aux2;
        fmpq_t c1,c2,op;
        fmpq_set_si(op,-1,1);
        do{
                fmpq_poly_rem(A3,*A1,*A2);
                printf("A1= %ld A2= %ld A3= %ld\n",fmpq_poly_degree(*A1),fmpq_poly_degree(*A2),fmpq_poly_degree(A3));
                aux1 = fmpq_poly_degree(*A2)*fmpq_poly_degree(*A1);
                aux2 = fmpq_poly_degree(*A1)-fmpq_poly_degree(A3);
                fmpq_poly_get_coeff_fmpq(coeff,*A2,fmpq_poly_degree(*A2));
                fmpq_pow_si(c1,op,aux1);
                fmpq_pow_si(c2,coeff,aux2);
                fmpq_mul(*res,c1,*res);
                fmpq_mul(*res,c2,*res);
                fmpq_poly_set(*A1,*A2);
                fmpq_poly_set(*A2,A3);
                printf("caca\n");
                printf("A1= %ld A2= %ld A3= %ld\n",fmpq_poly_degree(*A1),fmpq_poly_degree(*A2),fmpq_poly_degree(A3));

        }while( !(fmpq_poly_is_zero(A3)));

}

int main(){

        fmpq_poly_t A1;
        fmpq_poly_t A2;
        fmpq_poly_init(A1);
        fmpq_poly_init(A2);
        int poly1[]={3,5,7,1,2};
        int poly2[]={2,1,2,11};
        remplirPolynomeQ(poly1,&A1);
        remplirPolynomeQ(poly2,&A2);
        fmpq_t res;
        fmpq_init(res);
        fmpq_one(res);
        sousResultant(&A1,&A2,&res);
        fmpq_poly_print(A1);
        printf("\n");
        fmpq_poly_print(A2);
        printf("\n");
        return 0;
}







                //div euclidienne : void  fmpq_poly_rem(fmpq_poly_t R, const  fmpq_poly_t  poly1 , const  fmpq_poly_t  poly2)
                //deg polynome : slong fmpq_poly_degree(const fmpq_poly_t poly)  "slong=int" -->27.3
                //recup enieme coeff : void  fmpq_poly_get_coeff_fmpq(fmpq_t x, const  fmpq_poly_t poly , slong n) Retrieves the nth coefficient of poly, in lowest terms -->27.7
               //test poly nul : int  fmpq_poly_is_zero(const  fmpq_poly_t  poly) Returns 1 if poly is the zero polynomial, otherwise returns 0.
                //reinitialise poly : void fmpq_poly_clear ( fmpq_poly_t poly ) Clears the given polynomial, releasing any memory used. The polynomial must be reinitialised in order to be used again.
                //fmpq puissance : void fmpq_pow_si ( fmpq_t res , const fmpq_t op , slong e ) Sets res to op raised to the power e, where e is a slong. If e is 0 and op is 0, then res will be set to 1.
                //copier poly : void fmpq_poly_set ( fmpq_poly_t poly1 , const fmpq_poly_t poly2 ) Sets poly1 to equal poly2.
                //set fmpsq : void fmpq_set_si ( fmpq_t res , slong p , ulong q ) Sets res to the canonical form of the fraction p / q.
                //mult fmpq : void fmpq_mul ( fmpq_t res , const fmpq_t op1 , const fmpq_t op2 )
                //set fmpq_poly : void fmpq_poly_set_fmpz_poly( fmpq_poly_t rop , const fmpz_poly_t op ) Sets the rational polynomial rop to the same value as the integer polynomial op.
                //int fmpq_poly_print ( const fmpq_poly_t poly ) Prints the polynomial to stdout In case of success, returns a positive value. In case of failure, returns a non-positive value.
                //set fmpq to 1 : void fmpq_one ( fmpq_t res ) Sets the value of res to 1
