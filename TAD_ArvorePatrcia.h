#ifndef PREFIXO_TAD_H
#define PREFIXO_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct nohPatricia NohPatricia;

typedef NohPatricia *pNohPatricia;

typedef struct dPatricia DPatricia;

typedef DPatricia *pDPatricia;

typedef void (*FuncaoImpressao)(void *);

pDPatricia createPatriciaTree();

int addPatriciaKey(pDPatricia arvore, char *chave);

int removePatriciaKey(pDPatricia arvore, char *chave);

int searchPatriciaKey(pDPatricia arvore, char *chave);

void printPatrciaTree(pDPatricia arvore);

#endif
