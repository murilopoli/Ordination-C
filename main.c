#include <stdio.h>
#include <stdlib.h>
#include "es.h"
#include "ordenacao.h"

int main(){
    int op=0,*vet,*v,flag,aux,n;
    int *ord = NULL;
    int *novo = NULL;
    char arq[200];
    flag = 0;
    aux=0;
    printf("-----FUNCOES DE ARQUIVO E VETOR-----\n");
    printf("1  - Ler Arquivo TXT\n");
    printf("2  - Imprimir Vetor\n");
    printf("3  - Inserir Numero\n");
    printf("4  - Remover Numero\n");
    printf("5  - Salvar vetor ordenado\n");  
    printf("\n-----FUNCOES DE ORDENACAO-----\n");
    printf("6  - Metodo InsertionSort\n");
    printf("7  - Metodo SelectionSort\n");
    printf("8  - Metodo ShellSort\n");
    printf("9  - Metodo BubbleSort\n");
    printf("10 - Metodo BubbleSortInteligente\n");
    printf("11 - Metodo MergeSort\n");
    printf("12 - Metodo QuickSort\n");
    printf("\n13 - Imprimir Todas as Opcoes\n");
    printf("14 - Sair\n");
    printf("\nDigite o Opcao Desejada:");
    while(op<14){
        printf("\n\nOpcao: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nDigite o nome do arquivo de dados: \n");
                scanf("%s", arq);
                vet = leArquivo(arq);
                flag=1;
                printf("\nArquivo lido com Sucesso!\n");
                break;
            case 2:
                if(flag==0){
                    printf("\nNenhum arquivo foi lido!\n");
                    break;
                }else{
                    printf("\nDigite o Opcao Desejada:\n");
                    printf("1 - Imprimir vetor lido\n");
                    printf("2 - Imprimir vetor ja ordenado");
                    printf("\n\nOpcao: ");
                    scanf("%d", &aux);
                    if(aux>2) printf("\nOpcao invalida\n");
                    if(aux==1) imprimeVetor(vet);
                    if(aux==2) {
                        if(ord == NULL) {
                            printf("\nO vetor ainda nao foi ordenado!\n");
                        }else{
                            imprimeVetor(ord);
                        }
                    }
                }
                break;
            case 3:
                if(flag==0){
                    printf("\nNenhum arquivo foi lido!\n");
                    break;
                }else{
                    printf("\n\nDigite o total de numeros que devem ser inseridos no final do vetor:\n");
                    scanf("%d",&aux);
                    aux=tam+aux;
                    novo = alocavetor(aux);
                    for(int i=0;i<tam;i++){
                        novo[i]=vet[i];
                    }
                    for(int i=tam;i<aux;i++){
                        printf("\nNumero %d:",i+1);
                        scanf("%d", &n);
                        novo[i]=n;
                    }
                    printf("\nNumero(s) inserido(s) com sucesso!\n");
                }
                tam=aux;
                vet=(int*)malloc(tam*sizeof(int));
                for(int i=0;i<tam;i++){
                    vet[i]=novo[i];
                }
                break;
            case 4:
                if(flag==0){
                    printf("\nNenhum arquivo foi lido!\n");
                    break;
                }else{
                    printf("\n\nDigite o numero que deve ser removido do vetor:");
                    scanf("%d",&aux);
                    vet=removeN(vet,aux);
                    printf("\nNeumero removido com sucesso!\n");
                }
                break;
            case 5:
                if(ord==NULL){
                    printf("\nO vetor ainda nao foi ordenado!\n");
                    break;
                }else{
                salvaArquivo(ord);
                printf("\nO arquivo ordenado.txt foi criado com sucesso!\n");
                }
                break;
            case 6:
                ord=vet;
                ord = insertionSort(ord, tam);
                printf("Vetor ordenado pelo metodo InsertionSort:");
                imprimeVetor(ord);
                vet=novo;
                break;
            case 7:
                ord=vet;
                ord = selectionSort(ord, tam);
                printf("Vetor ordenado pelo metodo SelectionSort:");
                imprimeVetor(ord);
                vet=novo;
                break;
             case 8:
                ord=vet;
                ord = shellSort(ord, tam);
                printf("Vetor ordenado pelo metodo ShellSort:");
                imprimeVetor(ord);
                vet=novo;
                break;               
            case 9:
                ord=vet;
                ord = bubbleSort(ord, tam);
                printf("Vetor ordenado pelo metodo BubbleSort:");
                imprimeVetor(ord);
                vet=novo;
                break;
            case 10:
                ord=vet;
                ord = bubbleSortInteligente(ord, tam);
                printf("Vetor ordenado pelo metodo BubbleSort Inteligente:");
                imprimeVetor(ord);
                vet=novo;
                break;
            case 11:
                ord=vet;
                ord = mergeSort(ord,0,tam-1);
                printf("Vetor ordenado pelo metodo MergeSort:");
                imprimeVetor(ord);
                vet=novo;
                break;
            case 12:
                ord=vet;
                ord = quickSort(vet,0,tam-1);
                printf("Vetor ordenado pelo metodo QuickSort:");
                imprimeVetor(ord);
                vet=novo;
                break;
            case 13:
                printf("\n\nDigite o opcao desejada: \n");
                printf("-----FUNCOES DE ARQUIVO E VETOR-----\n");
                printf("1  - Ler Arquivo TXT\n");
                printf("2  - Imprimir vetor lido\n");
                printf("3  - Imprimir vetor ordenado\n");
                printf("4  - Consultar o total de numeros\n");
                printf("5  - Salvar vetor ordenado\n");  
                printf("\n-----FUNCOES DE ORDENACAO-----\n");
                printf("6  - Metodo InsertionSort\n");
                printf("7  - Metodo SelectionSort\n");
                printf("8  - Metodo ShellSort\n");
                printf("9  - Metodo BubbleSort\n");
                printf("10 - Metodo BubbleSortInteligente\n");
                printf("11 - Metodo MergeSort\n");
                printf("12 - Metodo QuickSort\n");
                printf("\n13 - Imprimir todas as opcoes\n\n");
                printf("\n14 - Sair\n\n");
                break;
            case 14:
                return(0);
                break;
        }
    }
    return(0);
}
