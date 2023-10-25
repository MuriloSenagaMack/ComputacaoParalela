#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double f(double x); 
double Local_trap(double a, double b, int n);

double f(double x){
  return exp(x);
}

int main(int argc, char* argv[]){
    int thread_count = strtol(argv[1], NULL, 10);

    double a, b;
    int n;
    printf("Insira a, b e n\n");
    scanf("%lf %lf %d", &a, &b, &n);

    double global_result = 0.0;
    #pragma omp parallel num_threads(thread_count)
    {
        double local_result = Local_trap(a, b, n);
        #pragma omp critical
        global_result += local_result;
    }

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %f\n", a, b, global_result);

    return 0;
}

double Local_trap(double a, double b, int n){
    double h, local_a, local_b;
    int local_n;

    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    h = (b - a) / n;
    local_n = n / thread_count;
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;

    double my_result = (f(local_a) + f(local_b)) / 2.0;

    for (int i = 1; i < local_n; i++)
        my_result += f(local_a + i * h);
    my_result = my_result * h;

    return my_result;
}

