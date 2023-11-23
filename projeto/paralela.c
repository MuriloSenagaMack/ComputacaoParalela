#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <gmp.h>

void factorial(mpf_t result, int limit) {
    mpf_set_ui(result, 1);
    for (int i = 2; i <= limit; i++) {
        mpf_mul_ui(result, result, i);
    }
}

void calcTaylor(int limit, mpf_t e) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int local_n = limit / num_threads;
        int start = id * local_n + 1;  
        int end = (id + 1) * local_n;
        if (id == num_threads - 1) {
            end = limit;
        }

        mpf_t frac, elocal;
        mpf_init2(elocal, 67108864);
        mpf_init2(frac, 67108864);
        mpf_set_ui(frac, 1);
        mpf_set_ui(elocal, 0);

        factorial(frac, start);
        mpf_ui_div(frac, 1, frac);

        for (int i = start; i <= end; ++i) {  
            mpf_add(elocal, elocal, frac);
            mpf_div_ui(frac, frac, i + 1);
        }

        #pragma omp critical
        mpf_add(e, e, elocal);

        mpf_clear(frac);
        mpf_clear(elocal);
    }
}

int main(int argc, char *argv[]) {
    unsigned long long max = strtoull(argv[1], NULL, 10);
    mpf_set_default_prec(999999);

    mpf_t euler;
    mpf_init(euler);

    double start = omp_get_wtime();
    calcTaylor(max, euler);
    double end = omp_get_wtime();

    gmp_printf("Aproximação:\n%.10000Ff\n", euler);
    printf("Tempo gasto: %f\n", end - start);

    mpf_clear(euler);

    return 0;
}

