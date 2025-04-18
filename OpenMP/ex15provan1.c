#include <stdio.h>
#include <omp.h>
int main() {
    int i, n = 10;
    int a[10], b[10], result[10];
    // Inicializando os arrays
    for (i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i * 2;
    }
    // Paralelizando o loop com OpenMP
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
        printf("Thread %d calculou result[%d] = %d\n", omp_get_thread_num(), i, result[i]);
    }
    return 0;
}