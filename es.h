#ifndef es_h
#define	es_h

extern int tam;
int *leArquivo(char nome[]);
void imprimeVetor(int vet[]);
int tamArquivo(FILE *arq);
void salvaArquivo(int *vet);
int *alocavetor(int n);
int *removeN(int *vet,int n);

#endif	/* es_h */
