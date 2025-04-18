#include <stdio.h>
#include <omp.h>
int main() {
    const int MAX = 100;
    int i, n = MAX;
    int a[MAX], b[MAX], result[MAX];
    // Inicializando os arrays
    for (i = 0; i < n; i++) {
        a[i] = i * 3;
        b[i] = (i * 7) - 1;
    }
    int total = 0;
    // Paralelizando o loop com OpenMP
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        result[i] = (a[i] + b[i]) * (a[i] + b[i]);
        total += result[i];
        printf("Thread %d calculou result[%d] = %d\n", omp_get_thread_num(), i, result[i]);
    }
    printf("Total: %d\n", total);
    return 0;
}