#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int compareInt(void *info1, void *info2)
{
   int *p1 = (int *)info1;
   int *p2 = (int *)info2;
   return *p2 - *p1;
}
/* ---------------------------------------- */
void printInt(void *info)
{
   int *pi = (int *)info;
   printf("%d - ", *pi);
}
/* ---------------------------------------- */
void *allocateIntInfo(void *info)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = *((int *)info);
   return pi;
}
/* ---------------------------------------- */
int *allocateInt(int n)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = n;
   return pi;
}

/* ---------------------------------------- */
/* tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data
{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int compareDate(void *info1, void *info2)
{
   struct Data *p1 = (struct Data *)info1;
   struct Data *p2 = (struct Data *)info2;
   return ((p2->ano - p1->ano) * 365) +
          ((p2->mes - p1->mes) * 30) +
          (p2->dia - p1->dia);
}
/* ---------------------------------------- */
void printDate(void *info)
{
   struct Data *pd = (struct Data *)info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void *allocateDateInfo(void *info)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = ((struct Data *)info)->dia;
   pd->mes = ((struct Data *)info)->mes;
   pd->ano = ((struct Data *)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data *allocateDate(int dia, int mes, int ano)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}
/* ---------------------------------------- */
int compareChar(void *info1, void *info2)
{
   char *c1 = (char *)info1;
   char *c2 = (char *)info2;
   return *c1 - *c2;
}
/* ---------------------------------------- */
void *sliceString(void *info, int pos)
{
   char *chave = (char *)info;
   char *simbolo = malloc(sizeof(char));
   *simbolo = chave[pos];
   return simbolo;
}
/* ---------------------------------------- */
void printChar(void *info)
{
   char *pc = (char *)info;
   printf("%s", pc); // Print the entire string, not just the first character
}

// Função auxiliar para obter o bit na posição i da chave
int getBit(char *chave, int i)
{
   int byteIndex = i / 8;
   int bitIndex = 7 - (i % 8);
   return (chave[byteIndex] & (1 << bitIndex)) != 0;
}

#endif /* UTILS_H */
