#ifndef INCLUIR_INFO_PREFIXO_H
#define INCLUIR_INFO_PREFIXO_H

pNohPatricia addPatriciaKeyRecursive(pNohPatricia raiz, char *chave, int nivel)
{
   if (raiz == NULL)
   {
      pNohPatricia novo = criarNohPatricia(1, nivel);
      novo->chave = strdup(chave);
      return novo;
   }

   if (raiz->ehFolha)
   {
      if (strcmp(raiz->chave, chave) == 0)
      {
         return raiz; // Chave já existe
      }

      pNohPatricia novoInterno = criarNohPatricia(0, nivel);
      int bitAtual = getBit(chave, nivel);
      int bitExistente = getBit(raiz->chave, nivel);

      if (bitAtual == bitExistente)
      {
         if (bitAtual == 0)
         {
            novoInterno->esquerda = addPatriciaKeyRecursive(raiz, chave, nivel + 1);
            novoInterno->direita = NULL;
         }
         else
         {
            novoInterno->direita = addPatriciaKeyRecursive(raiz, chave, nivel + 1);
            novoInterno->esquerda = NULL;
         }
      }
      else
      {
         pNohPatricia novaFolha = criarNohPatricia(1, nivel);
         novaFolha->chave = strdup(chave);

         if (bitAtual == 0)
         {
            novoInterno->esquerda = novaFolha;
            novoInterno->direita = raiz;
         }
         else
         {
            novoInterno->direita = novaFolha;
            novoInterno->esquerda = raiz;
         }
      }
      return novoInterno;
   }

   if (getBit(chave, nivel) == 0)
   {
      raiz->esquerda = addPatriciaKeyRecursive(raiz->esquerda, chave, nivel + 1);
   }
   else
   {
      raiz->direita = addPatriciaKeyRecursive(raiz->direita, chave, nivel + 1);
   }

   return raiz;
}

int addPatriciaKey(pDPatricia arvore, char *chave)
{
   if (arvore == NULL || chave == NULL)
   {
      return 0;
   }

   arvore->raiz = addPatriciaKeyRecursive(arvore->raiz, chave, 0);
   arvore->quantidadeChaves++;
   return 1;
}

#endif
