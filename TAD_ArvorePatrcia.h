#ifndef PREFIXO_TAD_H
#define PREFIXO_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct nohPatricia NohPatricia;
typedef NohPatricia *pNohPatricia;

/* descritor da arvore */
typedef struct dPatricia DPatricia;
typedef DPatricia *pDPatricia;

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPatricia criarArvorePrefixo();

int incluirInfoPrefixo(pDPatricia, char[], int);
int excluirInfoPrefixo(pDPatricia, char[], int);
int buscarInfoPrefixo(pDPatricia, char[], int);

void desenhaArvorePrefixo(pDPatricia);

#endif
