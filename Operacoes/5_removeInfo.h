#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

pNohPatricia removePatriciaKeyRecursive(pNohPatricia raiz, char *chave, int nivel, int *removido)
{
    if (raiz == NULL)
    {
        *removido = 0;
        return NULL;
    }

    if (raiz->ehFolha)
    {
        if (strcmp(raiz->chave, chave) == 0)
        {
            free(raiz->chave);
            free(raiz);
            *removido = 1;
            return NULL;
        }
        *removido = 0;
        return raiz;
    }

    pNohPatricia filho;
    if (getBit(chave, nivel) == 0)
    {
        raiz->esquerda = removePatriciaKeyRecursive(raiz->esquerda, chave, nivel + 1, removido);
        filho = raiz->esquerda;
    }
    else
    {
        raiz->direita = removePatriciaKeyRecursive(raiz->direita, chave, nivel + 1, removido);
        filho = raiz->direita;
    }

    if (*removido)
    {
        if (filho == NULL)
        {
            pNohPatricia outro_filho = (getBit(chave, nivel) == 0) ? raiz->direita : raiz->esquerda;
            free(raiz);
            return outro_filho;
        }
        if (!raiz->esquerda || !raiz->direita)
        {
            pNohPatricia temp = raiz;
            raiz = raiz->esquerda ? raiz->esquerda : raiz->direita;
            free(temp);
        }
    }

    return raiz;
}

int removePatriciaKey(pDPatricia arvore, char *chave)
{
    if (arvore == NULL || arvore->raiz == NULL || chave == NULL)
    {
        return 0;
    }

    int removido = 0;
    arvore->raiz = removePatriciaKeyRecursive(arvore->raiz, chave, 0, &removido);

    if (removido)
    {
        arvore->quantidadeChaves--;
    }

    return removido;
}

#endif
