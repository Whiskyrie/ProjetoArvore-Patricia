#ifndef CRIAR_ARVORE_PREFIXO_H
#define CRIAR_ARVORE_PREFIXO_H

#include <stdlib.h>

//---------------------------------
pNohPatricia criarNohPrefixo(int terminal)
{

    pNohPatricia pNovo = malloc(sizeof(NohPatricia));
    pNovo->terminal = terminal;
    pNovo->esquerda = NULL;
    pNovo->direita = NULL;
    return pNovo;
}

/* --------------------------*/
pDPatricia criarArvorePrefixo()
{

    pDPatricia dPref = malloc(sizeof(DPatricia));
    dPref->raiz = criarNohPrefixo(0); // a raiz n�o armazena chave
    dPref->quantidadeNohs = 1;

    return dPref;
};

#endif
