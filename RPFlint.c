#include <stdio.h>
#include "fmpz_poly.h"

int main(int argc, char const *argv[]) {
  fmpz_poly_t x;
  fmpz_poly_init(x);
  fmpz_poly_set_coeff_ui(x, 3, 6);
  fmpz_poly_set_coeff_ui(x, 2, 5);
  fmpz_poly_set_coeff_ui(x, 1, 4);
  fmpz_poly_set_coeff_ui(x, 0,  3);
  fmpz_poly_print(x); flint_printf("\n");

fmpz_poly_clear(x);
  return 0;
}
