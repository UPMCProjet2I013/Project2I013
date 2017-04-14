#include <stdio.h>
#include "fmpq_poly.h"

int main(int argc, char const *argv[]) {
fmpq_poly_t x;
fmpq_t res;
fmpq_t a;
fmpq_init(res);
fmpq_init(a);
fmpq_set_si(a,1,1);
fmpq_poly_init(x);
fmpq_poly_set_coeff_ui(x, 3, 6);
fmpq_poly_set_coeff_ui(x, 2, 5);
fmpq_poly_set_coeff_ui(x, 1, 4);
fmpq_poly_set_coeff_ui(x, 0,  3);
fmpq_poly_evaluate_fmpq(res,x,a);
fmpq_print(res); flint_printf("\n");
fmpq_poly_print(x); flint_printf("\n");
fmpq_poly_clear(x);
  return 0;
}

