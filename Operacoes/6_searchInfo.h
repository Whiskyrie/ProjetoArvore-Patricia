#ifndef BUSCAR_INFO_PREFIXO_H
#define BUSCAR_INFO_PREFIXO_H

int searchPatriciaKeyRecursive(pNohPatricia raiz, char *chave, int nivel)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (raiz->ehFolha)
    {
        return strcmp(raiz->chave, chave) == 0;
    }

    if (getBit(chave, nivel) == 0)
    {
        return searchPatriciaKeyRecursive(raiz->esquerda, chave, nivel + 1);
    }
    else
    {
        return searchPatriciaKeyRecursive(raiz->direita, chave, nivel + 1);
    }
}

int searchPatriciaKey(pDPatricia arvore, char *chave)
{
    if (arvore == NULL || chave == NULL || arvore->raiz == NULL)
    {
        return 0;
    }

    return searchPatriciaKeyRecursive(arvore->raiz, chave, 0);
}
#endif
