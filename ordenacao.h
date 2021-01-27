#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct Tree T;
extern int tam;
void permuta(int *p1, int *p2);
void merge(int *vet, int p1, int q2, int tam);
int *selectionSort(int *vet, int tam);
int *insertionSort(int *vet, int tam);
int *shellSort(int *vet, int tam);
int *bubbleSort(int *vet, int tam);
int *bubbleSortInteligente(int *vet, int n);
int *mergeSort(int *vet, int ini, int fim);
int *quickSort(int *vet, int ini, int fim);

#endif /* ORDENACAO_H */

