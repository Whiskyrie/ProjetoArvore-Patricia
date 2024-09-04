#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "ArvorePatricia.h"

int main()
{
    pDPatricia arvore = createPatriciaTree();

    printf("Inserindo chaves na arvore Patricia:\n");
    addPatriciaKey(arvore, "1010");
    addPatriciaKey(arvore, "1011");
    addPatriciaKey(arvore, "0010");
    addPatriciaKey(arvore, "1100");
    addPatriciaKey(arvore, "1111");

    // printf("\nImprimindo a arvore:\n");
    // printPatriciaTree(arvore, printChar);

    printf("\nBuscando chaves:\n");
    printf("Busca '1010': %d\n", searchPatriciaKey(arvore, "1010"));
    printf("Busca '1100': %d\n", searchPatriciaKey(arvore, "1100"));

    printPatriciaTree(arvore, printChar);

    printf("\nRemovendo a chave '1011':\n");
    removePatriciaKey(arvore, "1011");
    printPatriciaTree(arvore, printChar);

    printf("\nRemovendo a chave '0010':\n");
    removePatriciaKey(arvore, "0010");
    printPatriciaTree(arvore, printChar);

    printf("\nTentando remover uma chave inexistente '0000':\n");
    int resultado = removePatriciaKey(arvore, "0000");
    printf("Resultado da remocao: %d\n", resultado);
    printPatriciaTree(arvore, printChar);

    return 0;
}
