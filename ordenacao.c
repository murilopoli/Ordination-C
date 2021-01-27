#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void permuta(int*p1,int*p2){ 
    int aux;
    aux = *p1; 
    *p1 = *p2; 
    *p2 = aux; 
}

void merge(int *vet,int p1,int p2,int fim) {
  int i,j,k,n1,n2;
  n1 = p2 - p1 + 1;
  n2 = fim - p2;
  int v1[n1],v2[n2];
  for (int i = 0; i < n1; i++){
      v1[i] = vet[p1 + i];
  }
  for (int j = 0; j < n2; j++){
      v2[j] = vet[p2 + 1 + j];
  }
  i = 0;
  j = 0;
  k = p1;
  while (i<n1 && j<n2){
      if (v1[i] <= v2[j]){
          vet[k] = v1[i];
          i++;
      }else{
          vet[k] = v2[j];
          j++;
      }
      k++;
  }
  while (i < n1){
      vet[k] = v1[i];
      i++;
      k++;
  }
  while (j < n2){
      vet[k] = v2[j];
      j++;
      k++;
  }
}

int *selectionSort(int *vet,int tam){
 int i,j,k,aux,troca;
 for(i=0;i<tam-1;i++){
     troca=0;
     k=i;
     aux=vet[i];
     for(j=i+1;j<tam;j++){
         if(vet[j]<aux){
             k = j;
             aux=vet[j];
             troca=1;
         }
     }
     if(troca=1){
         vet[k]=vet[i];
         vet[i]=aux;
     }
 }
 return vet;
}

int *insertionSort(int *vet,int tam){
    int i,j,aux;
    for(i=1;i<tam;i++){
        aux=vet[i];
        for(j=i-1;j>=0 && aux<vet[j];j--){
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
    return vet;
}

int *shellSort(int *vet, int tam){
    int i , j , val;
    int gap = 1;
    while(gap < tam){
        gap = 3*gap+1;
    };
    while(gap > 1){
        gap /= 3;
        for(i = gap; i < tam; i++) {
            val = vet[i];
            j = i - gap;
              while (j >= 0 && val < vet[j]) {
                  vet[j + gap] = vet[j];
                  j -= gap;
              }
            vet[j + gap] = val;
        }
    }
    return vet;
}

int *bubbleSort(int *vet, int tam){
    int i, j;
    int aux;
    for (i=0;i<tam;i++){
        for (j=0; j<tam-1; j++){
            if (vet[j]>vet[j+1]){
                aux = vet[j+1];
                vet[j+1]=vet[j];
                vet[j]=aux;
            }
        }
    }
    return vet;
} 

int *bubbleSortInteligente(int *vet, int tam) { 
    int i,j,troca; 
    troca=0; 
    for(i=0;i<tam-1;i++){ 
        troca=0; 
        for(j=0;j<tam-i-1;j++){ 
            if (vet[j] > vet[j+1]){ 
                permuta(&vet[j],&vet[j+1]); 
                troca=1;
            } 
        }
        if (troca=0){
            break;
        }
    }
    return vet;
}

int *mergeSort(int *vet,int ini,int fim) {
    int aux = 0;
    if(ini < fim) {
        aux=ini+(fim-ini)/2;
        mergeSort(vet,ini,aux);
        mergeSort(vet,aux + 1,fim);
        merge(vet,ini,aux,fim);
    }
  return vet;
}

int *quickSort(int *vet, int ini, int fim) {
    int i, j, n, aux;
    i = ini;
    j = fim;
    n = vet[(ini+fim)/2];
    while(i<=j) {
        while(vet[i]<n && i<fim) {
            i++;
        }
        while(vet[j]>n && j>ini) {
            j--;
        }
        if(i<=j){
            aux=vet[i];
            vet[i]=vet[j];
            vet[j]=aux;
            i++;
            j--;
        }
    }
    if(j>ini){
        vet=quickSort(vet, ini, j);
    }
    if(i<fim){
        vet=quickSort(vet, i, fim);
    }
    return vet;
}