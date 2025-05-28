#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 100000000  // Tamanho do vetor

int main() {
    int *vetor = malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Inicialização do vetor com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 10;  // valores entre 0 e 9
    }

    // Versão SERIAL
    double start_serial = omp_get_wtime();
    long long soma_serial = 0;
    for (int i = 0; i < N; i++) {
        soma_serial += vetor[i];
    }
    double end_serial = omp_get_wtime();

    printf("Soma (serial): %lld\n", soma_serial);
    printf("Tempo (serial): %.4f segundos\n", end_serial - start_serial);

    // Teste com diferentes números de threads
    for (int num_threads = 2; num_threads <= 8; num_threads *= 2) {
        omp_set_num_threads(num_threads);
        long long soma_parallel = 0;

        double start_parallel = omp_get_wtime();

        // ===== INÍCIO REGIÃO PARALELA =====
        #pragma omp parallel for reduction(+:soma_parallel)
        for (int i = 0; i < N; i++) {
            soma_parallel += vetor[i];
        }
        // ===== FIM REGIÃO PARALELA =====

        double end_parallel = omp_get_wtime();

        printf("Soma (paralela com %d threads): %lld\n", num_threads, soma_parallel);
        printf("Tempo (paralelo): %.4f segundos\n", end_parallel - start_parallel);
    }

    free(vetor);
    return 0;
}
