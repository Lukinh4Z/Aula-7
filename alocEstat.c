#include <stdio.h>

int leInteiroDaTela(char* s) {

    int n;

    printf("%s", s);
    scanf("%d", &n);

    return n;
}

#define N 9999

int main() {

    int n = leInteiroDaTela("Por favor, informe o tamanho do vetor: ");

    int v[N];

    for(int i=0; i<n; i++)
        v[i] = leInteiroDaTela("Por favor, informe um elemento do vetor: ");

    for(int i=0; i<n; i++)
        v[i] = v[i] * 2;

    printf("\n"); // Quebra de linha

    for(int i=0; i<n; i++)
        printf("v[%d]: %d\n", i, v[i]);

    return 0;
}