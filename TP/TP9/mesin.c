/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP9 Alpro2 (PEMATER) dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int indeks;
char cc;

void START(char pita[])
{
    indeks = 0;
    cc = pita[indeks];
}

void INC(char pita[])
{
    indeks++;
    cc = pita[indeks];
}

int EOP()
{
    if (cc == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ADV(char pita[])
{
    indeks++;
    cc = pita[indeks];
    while ((cc == ' ') && (EOP() == 0))
    {
        indeks++;
        cc = pita[indeks];
    }
}

char GETCC()
{
    return cc;
}

int tanda()
{
    return indeks;
}
