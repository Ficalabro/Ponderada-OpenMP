# Ponderada-OpenMP

Este repositório contém um programa em C que calcula a soma dos elementos de um vetor de 100 milhões de inteiros. A implementação compara o desempenho entre a versão serial e versões paralelas utilizando OpenMP com 2, 4 e 8 threads.

## Descrição

O vetor é preenchido com valores aleatórios entre 0 e 9. O programa mede o tempo de execução da soma serial e das versões paralelas com diferentes quantidades de threads, utilizando `#pragma omp parallel for`.

## Vídeo de demonstração

Link para o vídeo no YouTube: https://www.youtube.com/watch?v=FmHObxlFUag
