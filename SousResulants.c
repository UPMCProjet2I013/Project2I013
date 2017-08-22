//Calcul de la suite des sous résultants

#include <stdio.h>
#include "fmpq_poly.h"
#include "nmod_poly.h"

void sousResultant(int *polyA, int *polyB, int *res){
        fmpz_poly_t A;
        fmpz_poly_t B;
        fmpz_poly_init(A);
        fmpz_poly_init(B);
        fmpz_poly_t tmp;
        fmpz_poly_init(tmp);
        remplirPolynome(polyA,&A);
        remplirPolynome(polyB,&B
        fmpz r=1;
        int i=2;
        while A
                        
                        
                        ///suggestion : on connait suite des restes euclidiens de A et B : on applique betement la formule : 
                        Res(A, B) = (−1)deg (A) deg (B)lcoeff(B)deg (A)−deg (R)Res(B, R), sans faire de while (a voir avec salome tests)
