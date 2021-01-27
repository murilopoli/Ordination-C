#include <stdio.h>
#include <stdlib.h>
#include "es.h"

int tam=0;

void salvaArquivo(int *vet){
    FILE *arq;
    arq = fopen("ordenado.txt", "w+");
    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    for(int i=0;i<tam;i++){
        if(i==tam-1){
            fprintf(arq,"%d",vet[i]); 
        }else{
            fprintf(arq,"%d\n",vet[i]);
        }
    }
    fclose(arq);
}

int *leArquivo(char nome[]){
    int *vet,*ptr,aux,i;
    FILE *arq;
    i=0;
    arq = fopen(nome, "r");
    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    tam = tamArquivo(arq);
    vet = alocavetor(tam);
    ptr=vet;
    rewind(arq);
    while(!feof(arq)){
        fscanf(arq, "%d\n", &aux);
        *ptr=aux;
        ptr++;
    }
    free(ptr);
    fclose(arq);
    return vet;
}

int tamArquivo(FILE *arq){
    int i=1;
    char ch;
    if(arq == NULL){
        printf("Erro na transmissão entre as funções\n");
    }else{
        while( (ch=fgetc(arq))!= EOF ){
        if(ch == '\n') i++;         
    }
    }
    return i;
}
    
void imprimeVetor(int *vet){
    int *ptr;
    ptr=vet;
    printf("\n");
    for(int i=0;i<tam;i++){
        printf("%d ",*ptr);
        ptr++;
    }
    printf("\nTotal de numeros:%d\n", tam);
    free(ptr);
}

int *alocavetor(int n){
    int *aux;
    aux = (int*)malloc(n*sizeof(int));
    if(aux == NULL){
        printf("\n Erro de alocacao do vetor\n");
        exit(1);
    }
    return aux;
}

int *removeN(int *vet,int n){
    int *ptr;
    ptr = vet;
    for(int i=0;i<tam;i++){
        if(ptr[i]==n){
            for(int j=i;j<tam;j++){
                if(j==tam-1){
                    ptr[j]==NULL;
                }else{
                    ptr[j]=ptr[j+1];
                }
            }
        }
    }
    return vet;
}