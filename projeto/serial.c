#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>

void factorial(mpf_t result, int limit) {
    mpf_set_ui(result, 1);
    for (int i = 2; i <= limit; i++) {
        mpf_mul_ui(result, result, i);
    }
}

void calcTaylor(int limit, mpf_t e) {
    mpf_t frac, elocal;
    mpf_init2(elocal, 67108864);
    mpf_init2(frac, 67108864);
    mpf_set_ui(frac, 1);
    mpf_set_ui(elocal, 0);

    factorial(frac, 1);
    mpf_ui_div(frac, 1, frac);

    for (int i = 1; i <= limit; ++i) {
        mpf_add(elocal, elocal, frac);
        mpf_div_ui(frac, frac, i + 1);
    }

    mpf_set(e, elocal);

    mpf_clear(frac);
    mpf_clear(elocal);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <limite>\n", argv[0]);
        return 1;
    }

    unsigned long long max = strtoull(argv[1], NULL, 10);
    mpf_set_default_prec(999999);

    mpf_t euler;
    mpf_init(euler);

    clock_t start_time = clock();
    calcTaylor(max, euler);
    clock_t end_time = clock();

    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    gmp_printf("Aproximação:\n%.10000Ff\n", euler);
    printf("Tempo gasto: %f segundos\n", execution_time);

    mpf_clear(euler);

    return 0;
}

