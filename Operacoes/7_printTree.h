#ifndef DESENHA_ARVORE_H
#define DESENHA_ARVORE_H

#include <stdio.h>

#define ESPACO 5

void printPatriciaTreeRecursive(pNohPatricia raiz, int depth, char *path, int right, FuncaoImpressao fi)
{
    if (raiz == NULL)
        return;

    depth++;

    printPatriciaTreeRecursive(raiz->direita, depth, path, 1, fi);

    path[depth - 2] = 0;
    if (right)
        path[depth - 2] = 1;

    if (depth > 1)
    {
        for (int i = 0; i < depth - 1; i++)
        {
            if (i == depth - 2)
                printf("+");
            else if (path[i])
                printf("|");
            else
                printf(" ");

            for (int j = 1; j < ESPACO; j++)
                if (i < depth - 2)
                    printf(" ");
                else
                    printf("-");
        }
    }

    if (raiz->ehFolha)
        fi(raiz->chave);
    else
        printf("%d", raiz->indice);
    printf("\n");

    printPatriciaTreeRecursive(raiz->esquerda, depth, path, 0, fi);
}

void printPatriciaTree(pDPatricia arvore, FuncaoImpressao fi)
{
    if (arvore == NULL || arvore->raiz == NULL)
        return;

    char path[255] = {0};
    printPatriciaTreeRecursive(arvore->raiz, 0, path, 0, fi);
}

#endif
