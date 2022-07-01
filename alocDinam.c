#include <stdio.h>
#include <stdlib.h> //biblioteca que tem o malloc
#include <string.h>

int leInteiroDaTela(char* s) {

    int n;

    printf("%s", s);
    scanf("%d", &n);

    return n;
}

int main() {

    int n = leInteiroDaTela("Por favor, informe o tamanho do vetor: ");

    int* v = (int*) malloc(sizeof(int) * n); //malloc aloca memória conforme um parâmetro passado, o (int*) é o tipo que peço do malloc, ele vem de um void*

    for(int i=0; i<n; i++)
        v[i] = leInteiroDaTela("Por favor, informe um elemento do vetor: ");

    for(int i=0; i<n; i++)
        v[i] = v[i] * 2;

    printf("\n"); // Quebra de linha

    for(int i=0; i<n; i++)
        printf("v[%d]: %d\n", i, v[i]);

    printf("\n");

    free(v); //É necessário para limpar a memória alocada.
    //Regra do 1 pra 1, para cada malloc deve haver um "free(v)".

    v = (int*) malloc(sizeof(int) * n); //vou usar OUTRO espaço na memória, agora porcausa do free, deixando o anterior livre.

    int r = leInteiroDaTela("Por favor, informe a dimensão 'i' da matriz: ");
    int s = leInteiroDaTela("Por favor, informe a dimensão 'j' da matriz: ");
    
    printf("\n");
    
    int** x = (int**) malloc(sizeof(int) * r);

    // char message[48];

    for(int i = 0; i < r; i++)
        x[i] = (int*) malloc(sizeof(int)* s);


    for(int i = 0; i < r; i++)
        for(int j = 0; j < s; j++) {
            // strcpy(message, "Por favor, informe o elemento [%d][%d] da matriz: ", i, j);
            // x[i][j] = leInteiroDaTela(message);
            x[i][j] = leInteiroDaTela("Por favor, informe o elemento da matriz: ");
        }

    printf("\n");

    for(int i = 0; i < r; i++){
        for(int j = 0; j < s; j++)
            printf("x[%d][%d]: %d\t", i, j, x[i][j]);

        printf("\n");
    }

    for(int i = 0; i < r; i++) //lembrando da regra, pra cada malloc deve haver um free!!!
        free(x[i]);

    free(x);

    return 0;
}