#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests.h"
#include "vector.h"
#include "matrix.h"
#include "rand.h"
#include "linreg.h"

int main(int argc, char** argv) {
    double A_val[] = {5, 0.1, 0.102,
              3, 0.05, 0.09,
              1, 0.07, 0.1,
              4, 0.02, 0.04};
    struct matrix *A = matrix_from_array(A_val, 4, 3);
    double y_val[] = {1, 0.1, -1, 0.4};
    struct vector *y = vector_from_array(y_val, 4);

    struct linreg *w = linreg_fit(A, y);

    struct vector *beta = w->beta;

    for (int d_r = 0; d_r < beta->length; d_r++) {
        printf("%lf\n", beta->la_obj.data[d_r]);
    }

    return 0;
}